import test_light_system as ls
import sys
sys.path.append("../sunseeker")
import photoresistor as phr

class Sun_seeker(ls.Light_system):

    photoresistors = []
    def __get_sensor_values(self):
        a = []
        print(self.photoresistors)
        for p in self.photoresistors:
            a.append(p.read())
        print(a)
        print("\n")
        return a

    def __init__(self):
        super().__init__()

        BRIDGERESISTOR = 1.1E3
        VOLTAGE = 3.3

        WINCOUNT = 4
        PERIOD = 0.5

        photoresistors = []
        print(self.count_of_sensors)
        for i in range(self.count_of_sensors):
            devnum = int(i / 4)
            channel = i % 4
            photoresistors.append(phr.Photoresistor(BRIDGERESISTOR, VOLTAGE, phr.ADDRESS_BASE + devnum, channel))
        self.photoresistors = photoresistors

    def get_sun_vector(self):
        b = self.__get_sensor_values()
        x = super().get_solution(b)
        return x


if __name__ == "__main__":
    ss = Sun_seeker()

    while True:
        x = ss.get_sun_vector()
        print(x)
