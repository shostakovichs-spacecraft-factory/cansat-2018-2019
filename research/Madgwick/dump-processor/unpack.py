#!/usr/bin/env python3

import struct
from itertools import chain
import serial
import socket
from enum import IntEnum
from math import acos, sin, degrees

import numpy as np
from stl import mesh
from pyqtgraph.Qt import QtGui, QtCore
from pyqtgraph import Qt
import pyqtgraph as pg
import pyqtgraph.opengl as gl

from OpenGL.GL import *
from pyqtgraph.opengl.GLGraphicsItem import GLGraphicsItem

import pyquaternion

MESH_PATH = './theplane.stl'

SUN_TCP_PORT = 43521

MAG_LOG = './mag_log'

mag_log = open(MAG_LOG, 'w')

class Record(QtCore.QObject):
	record_size = (32 * 10)//8


	def __init__(self, block):
		super(Record, self).__init__()

		if block != None: data = struct.unpack("<10f", block)

		else: data = [0.7071, 0.7071, 0, 0, 0, -1, 0, 0, 0, 1]


		self.quat = (data[0], data[1], data[2], data[3])
		self.acc = (data[4], data[5], data[6])
		self.mag = (data[7], data[8], data[9])

		if block != None:
			print(*self.mag, file=mag_log)
			mag_log.flush()


class SunRecord(QtCore.QObject):
	record_size = (32 * 3)//8


	def __init__(self, block):
		super(SunRecord, self).__init__()

		if block != None: data = struct.unpack("<3f", block)

		else: data = [0, 1, 0]


		self.data = data


class GLVectorItem(GLGraphicsItem):
	def __init__(self, x = 1, y = 1, z = 1, color = [1, 0, 0], thickness = 5, antialias=True, glOptions='translucent'):
		super(GLVectorItem, self).__init__()
		self.setCords(x, y, z)
		self.color = color
		self.thickness = thickness
		self.antialias = antialias
		self.setGLOptions(glOptions)


	def setCords(self, x, y, z):
		self.__cords = [x, y, z]
		self.update()


	def getCords(self):
		return self.__cords


	def paint(self):
		self.setupGLState()
		
		if self.antialias:
			glEnable(GL_LINE_SMOOTH)
			glHint(GL_LINE_SMOOTH_HINT, GL_NICEST)
			
		glLineWidth(self.thickness);

		glBegin( GL_LINES )
		
		x,y,z = map(float, self.getCords())
		glColor4f(self.color[0], self.color[1], self.color[2], .6)
		glVertex3f(0, 0, 0)
		glVertex3f(x, y, z)

		glEnd()

		glLineWidth(1)


class PlaneWidget(gl.GLViewWidget):
	def __init__(self, mesh_path, *args, **kwargs):
		super(PlaneWidget, self).__init__(*args, **kwargs)
		self.setCameraPosition(distance=40)

		g = gl.GLGridItem()
		g.scale(2,2,1)
		g.translate(0,0,-2)
		self.addItem(g)

		self.plane_axis = gl.GLAxisItem()
		self.plane_axis.setSize(x=300, y=300, z=300)
		self.addItem(self.plane_axis)

		self.acc = GLVectorItem(0, -1, 0)
		self.addItem(self.acc)

		self.mag = GLVectorItem(0, 0, 1, color=[0,0,1])
		self.addItem(self.mag)

		self.sun = GLVectorItem(0, 1, 0, color=[1,1,0])
		self.addItem(self.sun)

		verts = self._get_mesh_points(mesh_path)
		faces = np.array([(i, i+1, i+2,) for i in range(0, len(verts), 3)])
		colors = np.array([(0.0, 1.0, 0.0, 1.0,) for i in range(0, len(verts), 3)])
		self.mesh = gl.GLMeshItem(vertexes=verts, faces=faces, faceColors=colors, smooth=False, shader='shaded')
		self.addItem(self.mesh)

		self._update_rotation(Record(None))

	def on_new_records(self, records):
		record = records[-1]

		self._update_rotation(record)

	def on_new_sun_records(self, records):
		record = records[-1]

		self.sun.setCords(*self.rotation.rotate(record.data))

	def _get_mesh_points(self, mesh_path):
		your_mesh = mesh.Mesh.from_file(mesh_path)
		points = your_mesh.points

		points = np.array(list(chain(*points)))
		i = 0
		nd_points = np.ndarray(shape=(len(points)//3, 3,) )
		for i in range(0, len(points)//3):
			nd_points[i] = points[i*3: (i+1)*3]

		return nd_points

	def _transform_object(self, target, move=True, rotate=True, scale=1/50):
			target.resetTransform()
			target.scale(scale, scale, scale)
			if move: target.translate(0, 0, -3)
			if rotate:
				target.rotate(degrees(self.rotation.angle), self.rotation.axis[0], self.rotation.axis[1], self.rotation.axis[2])

	def _update_rotation(self, record):
		quat = pyquaternion.Quaternion(*record.quat) 
		self.rotation = quat

		self.acc.setCords(* quat.rotate(record.acc) ) #Поворачиваем ускорение не при отображении, а действительно меняя вектор
		record.mag = [axis * 40 for axis in record.mag]
		self.mag.setCords(* quat.rotate(record.mag) )

		self._transform_object(self.mesh)
		self._transform_object(self.plane_axis, move=False)
		self._transform_object(self.acc, move=False, rotate=False, scale=10)#Не поворачиваем ускорение, т.к. уже повернули его

	def _update_sun(self, record):
		print(record.x)
		print(record.y)
		print(record.z)

		sun_vect = self.quat.rotate([record.x, record.y, record.z])
		self.sun.setCords(sun_vect[0], sun_vect[1], sun_vect[2])



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

	@QtCore.pyqtSlot(list)
	def on_new_sun_record(self, records):
		self.plane_widget.on_new_sun_records(records)



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
			block = port.read(Record.record_size)
			records.append(Record(block))
			if len(records) > 0:
				self.new_record.emit(records)
				records = []
			#time.sleep(0.1)



class SunDataGenerator(QtCore.QThread):
	new_record = QtCore.pyqtSignal(list)

	def __init__(self, *args, **kwargs):
		super(SunDataGenerator, self).__init__(*args, **kwargs)

	def run(self):
		while True:
			try:
				sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				sock.bind(('0.0.0.0', SUN_TCP_PORT))
				sock.listen()
				print("listening for sun data on %d tcp port" % SUN_TCP_PORT)
				break
			except IOError as e:
				print(IOError.message)
				pass


		records = []
		while True:
			conn, addr = sock.accept()

			try:
				while True:
					block = conn.recv(SunRecord.record_size)
					records.append(SunRecord(block))
					if len(records) > 0:
						self.new_record.emit(records)
						records = []

			except socket.error as e:
				print('Socket error %s' % e)
				conn.close()



app = QtGui.QApplication([])
pg.setConfigOptions(antialias=True)

win = MainWindow()
win.resize(1024, 768)
win.show()

data_generator = DataGenerator()
data_generator.new_record.connect(win.on_new_record)
data_generator.start()

sun_data_generator = SunDataGenerator()
sun_data_generator.new_record.connect(win.on_new_sun_record)
sun_data_generator.start()

exit(app.exec_())