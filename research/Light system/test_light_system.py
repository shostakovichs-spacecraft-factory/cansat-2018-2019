import numpy.linalg as lg
import numpy as np
import random
import math

#important!!!!
#all functions return lists. Even if it's named ..._matrix

#values for rejecting sensors that not under sun light
min_flow_abs = 0.21
min_flow_rel = 0.25

#simulate parametres
random_rel = 0.2
random_abs = 0.2
sensor_dev_rel = 0.1

count_of_sensors = 8

#bigger - more accurate test_system
count_of_rounds = 10000

#maximum of light power
max = 5

#getting data from the file
def get_sensor_matrix():
    f = open("sensor_values","r")
    b = (f.read().split('\n'))
    d = []
    for i in b:
        d.append(i.split(' '))
    f.close();
    d.pop()
    s = []
    for l in d:
        r = []
        m = 0
        for i in l:
            r.append(float(i))
        r1 = normate(r)
        s.append(r1)

    return s


#simulates sensor values
def simulate(sensor_matrix, light):
    r = []

    M = light[0]/normate(light)[0]
    for i in sensor_matrix:
        s = 0
        for j in [0,1,2]:
            s += i[j] * light[j]
        if s < 0:
            s = 0
        r1 = random.random() * random_rel
        r2 = random.random() * random_abs

        s = (1 + r1) * s + r2 + sensor_dev_rel * M
        r.append(s)

    return r

#gives proper matrix for such sensor values
def get_good_solve_matrix(matrixes, sensor_values):
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

    return matrixes[a]


def get_all_solve_matrixes(sensor_matrix):
    #print("all solve matrixes!\n")
    l = sensor_matrix
    i = 1
    r = []
    r.append("0")
    while i < 2**count_of_sensors:
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
            r.append("kek")
            #print("kek")
            #print(k)

        #print("{0:b}".format(i))
        #print("\n")
        i += 1
    return r


def normate(a):
    s = 0
    for i in a:
        s += i**2
    s = s**0.5
    if(s == 0):
        return a

    res = []
    for i in a:
        res.append(i/s)
    return res

#returns deviation in degrees
def test_system(min_height,max_height):

    #print("testing!\n")
    a = get_sensor_matrix()
    #print(a)
    all = get_all_solve_matrixes(a)

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
        m = random.uniform(1, max)
        x *= m
        y *= m
        z *= m

        b = simulate(a, [x, y, z])

        a_ = get_good_solve_matrix(all, b)
        if(isinstance(a_,str)):
            continue

        #I have no idea why it's work, but it's work
        b.reverse()
        res = np.matmul(np.matrix(a_), np.matrix(b).getT() )

        res = res.tolist()
        res = [a[0] for a in res]

        h1 = normate([x,y,z])
        h2 = normate(res)

        if(minZ > h2[2]):
            minZ = h2[2]


        dev = 0
        j = 0
        while(j < 3):
            dev += h1[j]*h2[j]
            j += 1

        dev = dev**2
        deviation += dev
        i += 1

    deviation = ((deviation / count_of_rounds)**0.5)
    #print(minZ)
    #print(360*math.asin(minZ)/(math.pi*2))
    return 360*math.acos(deviation)/(math.pi*2)
    #return deviation

#just shows deviation for different vertical angles
i = -30
d = 10
while i <= 90 - d:
    print("{0:f}: {1:f}".format(i, test_system(math.sin(math.pi*2*i/360),math.sin(math.pi*2*(i + d)/360))))
    i+=d



#Don't look below. Will be probably used in next versions

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
