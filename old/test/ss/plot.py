import sys
import numpy as np
import matplotlib.pyplot as plt

names = sys.argv[1:]
data_sun = np.loadtxt(names[0], delimiter=' ', unpack=True)
data_earth = np.loadtxt(names[1], delimiter=' ', unpack=True)
data_mars = np.loadtxt(names[2], delimiter=' ', unpack=True)

plt.style.use('science')
fig, ax = plt.subplots()
plt.title(names[4])

ax.plot(data_sun[0], data_sun[1], label=names[5], color='red')
ax.plot(data_earth[0], data_earth[1], label=names[6], color='blue')
ax.plot(data_mars[0], data_mars[1], label=names[7], color='orange')

ax.set_xlabel(names[8])
ax.set_ylabel(names[9])
ax.legend(loc='upper right')

plt.tight_layout()
plt.savefig(names[3], dpi=250)
