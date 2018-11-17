import time
import sys

import Adafruit_ADS1x15 as ADS1x15
import pigpio

ADDRESS_BASE = 0x48

class Photoresistor:
	def __init__(self, bridgeresistor, fullvoltage, address=ADDRESS_BASE, channel=0, i2c=None, **kwargs):
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