from math import pi, radians

import find_sun
import test_light_system as ls

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

	def setangle(self, radians):
		radians %= 2 * pi
		value = self.minval + (self.maxval - self.minval) / 2 * pi
		self.pi.set_servo_pulsewidth(self.pin, value)

if __name__ == "__main__":
	ss = find_sun.Sun_seeker()

	Servo1 = Servo(pin=17) #TODO define min and max val precisely
	Servo2 = Servo(pin=18)

	while True:
		direction = ss.get_sun_vector()
		direction = ls.dekart_to_euler(direction)

		Servo1.setangle(radians(direction[0]))
		Servo2.setangle(radians(direction[1]))