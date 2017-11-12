import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

data1 = np.genfromtxt("c1.txt", delimiter = ",")
plt.plot(data1[:,0], data1[:,1])
plt.savefig("c1.pdf")
plt.close()

plt.plot(data1[:,0], data1[:,2])
plt.savefig("c2.pdf")
plt.close()

data2 = np.genfromtxt("c2.txt", delimiter = ",")
plt.plot(data2[:,0], data2[:,1])
plt.savefig("c3.pdf")
plt.close()

data3 = np.genfromtxt("c3.txt", delimiter = ",")
plt.plot(data3[:,0], data3[:,1])
plt.savefig("c4.pdf")
plt.close()

data4 = np.genfromtxt("c4.txt", delimiter = ",")
plt.plot(data4[:,0], data4[:,1])
plt.savefig("c5.pdf")
plt.close()

plt.plot(data4[:,0], data4[:,2])
plt.savefig("c6.pdf")
plt.close()

data5 = np.genfromtxt("c5.txt", delimiter = ",")
plt.plot(data5[:,0], data5[:,1])
plt.savefig("c7.pdf")
plt.close()

data6 = np.genfromtxt("c6.txt", delimiter = ",")
plt.plot(data6[:,0], data6[:,1])
plt.savefig("c8.pdf")
plt.close()


datat = np.genfromtxt("cond_ini_tambor.dat")
x = np.linspace(0, 0.5, 101)
y = np.linspace(0, 0.5, 101)
X, Y = np.meshgrid(x,y)
fig = plt.figure()
ax1 = fig.gca(projection = "3d")
ax1.plot_surface(X, Y, datat)
plt.savefig("t1.pdf")
plt.close()

data7 = np.genfromtxt("t1.txt")
phi1 = np.reshape(data7, (101, 101))
ax2 = fig.gca(projection = "3d")
ax2.plot_surface(X, Y, phi1)
plt.savefig("t2.pdf")
plt.close()

data8 = np.genfromtxt("t2.txt")
phi2 = np.reshape(data8, (101, 101))
ax3 = fig.gca(projection = "3d")
ax3.plot_surface(X, Y, phi2)
plt.savefig("t3.pdf")
plt.close()

data9 = np.genfromtxt("t3.txt")
phi3 = np.reshape(data9, (101, 101))
ax4 = fig.gca(projection = "3d")
ax4.plot_surface(X, Y, phi3)
plt.savefig("t4.pdf")