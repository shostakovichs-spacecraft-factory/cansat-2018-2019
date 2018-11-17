import time
import sys

import Adafruit_ADS1x15 as ADS1x15
import pigpio

class Photoresistor:
	def __init__(self, bridgeresistor, fullvoltage, address, channel, i2c=None, **kwargs):
		self.ads = ADS1x15.ADS1115(address, i2c, **kwargs)
		self.channel = channel
		self.bridgeresistor = bridgeresistor
		self.fullvoltage = fullvoltage

	def read(self):
		raw = self.ads.read_adc(self.channel, gain=1)
		voltage = raw * 125E-6 #change for another range
		
		resistance = self.fullvoltage * self.bridgeresistor / voltage - self.bridgeresistor

		value = 1000.0 / resistance #resistance falls with growth of luminance

		print(voltage, resistance)

		return value


class Servo:
	def __init__(self, pin=18, minval=520, maxval=2240, wincount=8):
		self.pi = pigpio.pi()
		self.pin = pin
		self.minval = minval
		self.maxval = maxval
		self.wincount = wincount

	def setwindow(self, number):
		value = self.minval + (self.maxval - self.minval) / (self.wincount - 1) * number
		self.pi.set_servo_pulsewidth(self.pin, value)


if __name__=='__main__':
	BRIDGERESISTOR = 1.1E3
	VOLTAGE = 3.3

	WINCOUNT = 4
	PERIOD = 0.5

	if len(sys.argv) > 1:
		WINCOUNT = int(sys.argv[1])
	if len(sys.argv) > 2:
		PERIOD = float(sys.argv[2])


	photoresistors = []
	servo = Servo(wincount=WINCOUNT)

	for i in range(0, WINCOUNT):
		devnum = int(i / 4)
		channel = i % 4

		photoresistors.append( Photoresistor(BRIDGERESISTOR, VOLTAGE, 0x48 + devnum, channel) )
		photoresistors[-1].seqnum = i

	while True:
		sunhouse = max(photoresistors, key=Photoresistor.read).seqnum
		servo.setwindow(sunhouse)
		#print(sunhouse)

		print('_______________________________________________________________________________')
		time.sleep(PERIOD)