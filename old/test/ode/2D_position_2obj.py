import sys
import numpy as np
import matplotlib.pyplot as plt

names = sys.argv[1:]
data_sun = np.loadtxt(names[0], delimiter=' ', unpack=True)
data_earth = np.loadtxt(names[1], delimiter=' ', unpack=True)

plt.style.use('science')
fig, ax = plt.subplots()
plt.title(names[3])

ax.plot(data_sun[0], data_sun[1], label=names[6], color='red')
ax.plot(data_earth[0], data_earth[1], label=names[7], color='green')

ax.set_xlabel(names[4])
ax.set_ylabel(names[5])
ax.legend(loc='upper right')

plt.tight_layout()
plt.savefig(names[2], dpi=250)

# python 2D_position_2obj.py data/sun_position.txt data/earth_position.txt sun_earth.png "Earth's orbit" "X [km]" "Y [km]" Sun Earth
