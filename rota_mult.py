import numpy as np
import matplotlib.pyplot as plt
import time
from numpy import linspace,sin,cos,pi,array

P=np.array([[1,1],[3,1],[2,2],[1,1]],dtype=float)
ang=float(input("Escriba el angulo de rotación:"))
a=ang
print("puntos a transformar")
print(P)
figure, ax=plt.subplots()
ax.plot(P[:,0],P[:,1])
ax.grid()
n=int(input("Numero de rotaciones: "))

for i in range(n):
    ang+=a
    th=ang*(pi/180)
    Rxy=array([[cos(th),sin(th)],[-sin(th),cos(th)]])
    R=P@Rxy
    ax.plot(R[:,0],R[:,1])

ax.set_title("Rotación multiple en ejes x,y")
plt.show()
# plt.savefig('scala_2.png')