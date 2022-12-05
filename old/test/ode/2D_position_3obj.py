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

ax.plot(data_sun[0], data_sun[1], label=names[7], color='red')
ax.plot(data_earth[0], data_earth[1], label=names[8], color='blue')
ax.plot(data_mars[0], data_mars[1], label=names[9], color='green')

ax.set_xlabel(names[5])
ax.set_ylabel(names[6])
ax.legend(loc='upper right')

plt.tight_layout()
plt.savefig(names[3], dpi=250)

# python 2D_position_3obj.py data/sun_position.txt data/earth_position.txt data/mars_position.txt images/sun_earth_mars.png "Earth and Mars' orbits" "X [km]" "Y [km]" Sun Earth Mars
