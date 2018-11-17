import numpy.linalg as lg
import numpy as np
import random
import math

#important!!!!
#all functions return lists. Even if it's named get_..._matrix

#values for rejecting sensors that not under sun light
min_flow_abs = 0.05
min_flow_rel = 0.05

#simulate_random parametres
random_rel = 0.01
random_abs = 0.01
sensor_dev_rel = 0
sensor_dev_abs = 0

count_of_sensors = 8

#bigger - more accurate test_system
count_of_rounds = 10000

#maximum of light power
min = 1
max = 5
#help functions
def euler_to_dekart(psi, fi):
    psi = math.radians(psi)
    fi = math.radians(fi)
    x = (math.cos(fi) * math.cos(psi))
    y = (math.cos(fi) * math.sin(psi))
    z = (math.sin(fi))

    return [x,y,z]


def norm(a):
    s = 0
    for i in a:
        s += i**2
    return s**0.5



def find_angle(a1,a2):
    a1 = normate(a1)
    a2 = normate(a2)
    s = 0
    for i in range(len(a1)):
        s += a1[i] * a2[i]
    return math.acos(s)


def dekart_to_euler(a):
    x = a[0]
    y = a[1]
    z = a[2]
    fi = find_angle(a, [0,0,1])
    psi = find_angle([x, y, 0], [1, 0, 0])

    if x > 0 and y < 0:
        psi = -psi
    elif x < 0 and y < 0:
        psi = -psi
    return [math.degrees(psi), 90 - math.degrees(fi)]

def normate(a):
    s = norm(a)
    if(s == 0):
        return a

    res = []
    for i in a:
        res.append(i/s)
    return res

def square_deviation(a1, a2):
    s = []
    for i in range(len(a1)):
        s.append(a1[i] - a2[i])
    return norm(s)/len(s)**0.5

#returns deviation in degrees
def test_system(min_height,max_height):

    ls = Light_system()

    deviation = 0

    i = 0
    minZ = 0
    while(i < count_of_rounds):
        x = random.uniform(-1, 1)
        z = random.uniform(min_height, max_height)
        pp = x**2 + z**2
        if pp > 1:
            continue
        y = (1 - pp)**0.5
        m = random.uniform(min, max)
        x *= m
        y *= m
        z *= m

        b = ls.simulate_random([x, y, z])

        res = ls.get_solution(b)
        if(isinstance(res, str)):
            continue

        dev = math.cos(find_angle([x,y,z],res))

        dev = dev**2
        deviation += dev
        i += 1

    deviation = ((deviation / count_of_rounds)**0.5)
    return math.degrees(math.acos(deviation))
    #return deviation


#will be deleted in next versions
def get_solve_matrix(matrix):
    a = np.matrix(matrix)
    """
    print(a)
    print(a.getI())
    b = np.matmul(a,a.getI())

    x = np.matrix([1,1,1]).getT()
    res = np.matmul(a, x)
    print(b.getI())
    print(b)
    """
    return a.getI()

#is not used in this version
def restrainMatrix(matrix, choise):
    res = []
    mask = 1
    for l in matrix.tolist():
        if(mask & choise):
            res.append(r)
        k = k << 1
    return res


def save_solve_matrix(f, matrix):
    for l in matrix.getT().tolist():
        for a in l:
            f.write("{0:f} ".format(a))
        f.write('\n')

def set_properties():
    m = get_sensor_matrix()
    f = open("light_sensors_properties","w")
    #f.write("{0:b} ".format(choise))
    save_solve_matrix(f, get_solve_matrix(m))
    f.close();


class Light_system:
    count_of_sensors = 0
    __sensor_matrix = []
    __all_solve_matrixes = []
    def __get_sensor_matrix(self):
        f = open("sensor_values","r")
        b = (f.read().split('\n'))
        d = []
        for i in b:
            d.append(i.split(' '))
        f.close();
        d.pop()
        s = []
        for l in d:
            r = euler_to_dekart(float(l[0]), float(l[1]))
            s.append(r)
        return s

    def __get_all_solve_matrixes(self, sensor_matrix):
        l = sensor_matrix
        r = []
        r.append(None)
        for i in range(2**count_of_sensors):
            if(i == 0):
                continue
            s = []
            j = i
            for k in l:
                if(j % 2 == 1):
                    s.append(k)
                j = j >> 1
            k = np.matrix(s)

            j = i
            if(lg.matrix_rank(k) == 3):
                h = k.getI().getT().tolist()
                d = []
                ii = 0
                for k in l:
                    if(j % 2 == 1):
                        d.append(h[ii])
                        ii += 1
                    else:
                        d.append([0.0,0.0,0.0])
                    j = j >> 1
                h = np.matrix(d).getT()
                #print(h.getT())
                r.append(h)
            else:
                r.append(None)
        return r

    def __find_solution(self, solve_matrix, sensor_values):
        sensor_values.reverse()
        res = np.matmul(np.matrix(solve_matrix), np.matrix(sensor_values).T).tolist()
        res = [a[0] for a in res]
        return res

    def __get_good_solve_matrix(self, sensor_values):
        l = sensor_values
        a = 0
        l.reverse()
        s = 0
        for i in l:
            s += i
        s /= len(l)
        for i in l:
            a = a << 1
            if(i > s * min_flow_rel + min_flow_abs):
                a += 1

        return self.__all_solve_matrixes[a]


    def __init__(self):
        self.__sensor_matrix = self.__get_sensor_matrix()
        self.count_of_sensors = len(self.__sensor_matrix)
        self.__all_solve_matrixes = self.__get_all_solve_matrixes(self.__sensor_matrix)

    def get_solution(self, sensor_values):
        a = self.__get_good_solve_matrix(sensor_values)
        if a is None:
            return None

        return self.__find_solution(a, sensor_values)

    #simulates sensor values
    def simulate_random(self, light):
        r = []
        #best way to find norm of light
        M = norm(light)
        #return simulate(sensor_matrix, light, random.random() * random_rel, random.random() * random_abs + sensor_dev_rel * M)

        for i in self.__sensor_matrix:
            s = 0
            for j in [0,1,2]:
                s += i[j] * light[j]
            if s < 0:
                s = 0

            r1 = random.random() * random_rel
            r2 = random.random() * random_abs

            s = (1 + r1) * s + r2 + sensor_dev_rel * M + sensor_dev_abs
            r.append(s)

        return r


    def simulate(self, light):

        r = []
        for b in self.__sensor_matrix:
            s = 0

            for i in range(len(light)):
                s += light[i] * b[i]

            if(s < 0):
                s = 0
            r.append(s)
        return r

    def get_sensor_matrix(self):
        return self.__sensor_matrix

if __name__ == "__main__":
    i = -90
    while i < 90:
        print(dekart_to_euler(euler_to_dekart(0,i)))
        i += 10
