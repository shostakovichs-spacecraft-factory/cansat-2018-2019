import struct
from itertools import chain
import serial
from enum import IntEnum
from math import acos, sin

import numpy as np
from stl import mesh
from pyqtgraph.Qt import QtGui, QtCore
from pyqtgraph import Qt
import pyqtgraph as pg
import pyqtgraph.opengl as gl

MESH_PATH = './theplane.stl'


class Record(QtCore.QObject):
	record_size = (32 * 4)//8


	def __init__(self, block):
		super(Record, self).__init__()

		if block != None: data = struct.unpack("<4f", block)

		else: data = [1, 0, 0, 0]


		self.w = data[0]
		self.x = data[1]
		self.y = data[2]
		self.z = data[3]



class PlaneWidget(gl.GLViewWidget):
	def __init__(self, mesh_path, *args, **kwargs):
		super(PlaneWidget, self).__init__(*args, **kwargs)
		self.setCameraPosition(distance=40)

		g = gl.GLGridItem()
		g.scale(2,2,1)
		g.translate(0,0,-2)
		self.addItem(g)

		self.plane_axis = gl.GLAxisItem()
		self.plane_axis.setSize(x=1000, y=500, z=500)
		self.addItem(self.plane_axis)

		verts = self._get_mesh_points(mesh_path)
		faces = np.array([(i, i+1, i+2,) for i in range(0, len(verts), 3)])
		colors = np.array([(0.0, 1.0, 0.0, 1.0,) for i in range(0, len(verts), 3)])
		self.mesh = gl.GLMeshItem(vertexes=verts, faces=faces, faceColors=colors, smooth=False, shader='shaded')
		self.addItem(self.mesh)
		self._update_mesh(Record(None))


	def on_new_records(self, records):
		record = records[-1]

		self._update_mesh(record)


	def _get_mesh_points(self, mesh_path):
		your_mesh = mesh.Mesh.from_file(mesh_path)
		points = your_mesh.points

		points = np.array(list(chain(*points)))
		i = 0
		nd_points = np.ndarray(shape=(len(points)//3, 3,) )
		for i in range(0, len(points)//3):
			nd_points[i] = points[i*3: (i+1)*3]

		return nd_points

	def _update_mesh(self, quat):
		print(quat.w)
		print(quat.x)
		print(quat.y)
		print(quat.z)

		angle = acos(quat.w)
		angle *= 2

		axis = []

		if angle != 0.0:
			vector_coeff = sin(angle / 2)

			axis.append( quat.x / vector_coeff )
			axis.append( quat.y / vector_coeff )
			axis.append( quat.z / vector_coeff )

		else: axis = [0.0, 0.0, 0.0]

		angle *= 180 / np.pi


		def do_things(target, move=True):
			target.resetTransform()
			target.scale(1/50, 1/50, 1/50)
			#target.rotate(90, 1, 0, 0)
			#target.rotate(180, 0, 0, 1)
			if move: target.translate(0, 0, -3)
			target.rotate(angle, axis[0], axis[1], axis[2])

		do_things(self.mesh)
		do_things(self.plane_axis, move=False)



class MainWindow(QtGui.QDialog):
	def __init__(self):
		super(MainWindow, self).__init__()
		layout = QtGui.QHBoxLayout(self)
		pal = QtGui.QPalette()
		pal.setColor(QtGui.QPalette.Background, QtGui.QColor(0));
		self.setAutoFillBackground(True);
		self.setPalette(pal);

		self.plane_widget = PlaneWidget(mesh_path=MESH_PATH, parent=self)
		layout.addWidget(self.plane_widget, stretch=12)

	@QtCore.pyqtSlot(list)
	def on_new_record(self, records):
		self.plane_widget.on_new_records(records)



class DataGenerator(QtCore.QThread):
	new_record = QtCore.pyqtSignal(list)

	def __init__(self, *args, **kwargs):
		super(DataGenerator, self).__init__(*args, **kwargs)

	def run(self):
		while True:
			try:
				port = serial.Serial(
					port="/dev/ttyVUSB0",
					baudrate=115200,
					parity=serial.PARITY_NONE,
					stopbits=serial.STOPBITS_ONE,
					bytesize=serial.EIGHTBITS,
					xonxoff=False,
					rtscts=False,
					dsrdtr=False
				)
				print("port_opened")
				break
			except IOError as e:
				print(IOError.message)
				#raise
				pass


		records = []
		while True:
			print(port.name)
			block = port.read(Record.record_size)
			records.append(Record(block))
			if len(records) > 0:
				self.new_record.emit(records)
				records = []
			#time.sleep(0.1)




app = QtGui.QApplication([])
pg.setConfigOptions(antialias=True)

win = MainWindow()
win.resize(1024, 768)
win.show()

data_generator = DataGenerator()
data_generator.new_record.connect(win.on_new_record)
data_generator.start()

exit(app.exec_())