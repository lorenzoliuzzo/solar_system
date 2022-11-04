import sys
import numpy as np
import matplotlib.pyplot as plt


planets = ['Sun', 'Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune']
names = sys.argv[1:]

plt.style.use('science')
fig, ax = plt.subplots()
plt.title(names[1])

for name in planets:
    data = np.loadtxt('data/' + name + '_position.txt', delimiter=' ', unpack=True)
    ax.plot(data[0], data[1], label=name)

ax.set_xlabel(names[2])
ax.set_ylabel(names[3])
ax.legend(loc='upper right')

# plt.tight_layout()
plt.savefig(names[0], dpi=500)

# python plot_solar_system.py images/ss.png "Solar system" "X [km]" "Y [km]"
