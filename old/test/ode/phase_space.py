# plotting position and linear velocity in the phase space 

# python plot.py data/position.txt data/velocity.txt pos.png "System of Harmonic Oscillators" "Position [m]" "Velocity [m/s]"


import sys
import numpy as np
import matplotlib.pyplot as plt

names = sys.argv[1:]
data_pos = np.loadtxt(names[0], delimiter=' ', unpack=True)
data_vel = np.loadtxt(names[1], delimiter=' ', unpack=True)

plt.style.use('science')
fig, ax = plt.subplots()
plt.title(names[3])

ax.plot(data_pos[0], data_vel[0], color='red')

ax.set_xlabel(names[4])
ax.set_ylabel(names[5])
ax.legend(loc='upper right')

plt.tight_layout()
plt.savefig(names[2], dpi=250)


