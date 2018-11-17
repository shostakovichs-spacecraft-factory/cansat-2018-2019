import numpy as np
from mpl_toolkits.mplot3d import Axes3D # This import has side effects required for the kwarg projection='3d' in the call to fig.add_subplot
import matplotlib.pyplot as plt
import random
import test_light_system as ls
import math

sum = 0
count = 0




def mysimulate(lightS, psi, fi):
    light = ls.euler_to_dekart(psi, fi)
    #print(light)

    b = lightS.simulate_random(light)

    x = lightS.get_solution(b)
    if(isinstance(x, str)):
        return x;
    #print(ls.normate(x))

    dev = ls.find_angle(light,x)

    return dev



def myfun(lightS, psi, fi):
    n = 20
    s = 0
    for i in range(n):
        k = mysimulate(lightS, psi, fi)
        if(isinstance(k, str)):
            return -20
        else:
            s += k**2

    s /= n
    s = s**0.5

    global sum
    sum += s
    global count
    count += 1

    return math.degrees(s)


def fun(lightS, x, y):
    return myfun(lightS,x,y)

lightS = ls.Light_system()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
x = np.arange(-180.0, 180.0, 2)
y = np.arange(-90.0, 90.0, 2   )
X, Y = np.meshgrid(x, y)

hh = lightS.get_sensor_matrix()

ss = [[],[],[]]
for l in hh:
    for i in range(len(l)):
        ss[i].append(l[i])

#ax.scatter([0], [0], [-10], 'r', marker='o')

zs = np.array([fun(lightS,x,y) for x,y in zip(np.ravel(X), np.ravel(Y))])
Z = zs.reshape(X.shape)

ax.plot_surface(X, Y, Z)

ax.set_xlabel('Psi Label')
ax.set_ylabel('Fi Label')
ax.set_zlabel('Deviation Label')


print(math.degrees(sum/count))
plt.show()
