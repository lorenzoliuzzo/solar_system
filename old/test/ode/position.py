
import sys
import numpy as np
import matplotlib.pyplot as plt

names = sys.argv[1:]
data_pos = np.loadtxt(names[0], delimiter=' ', unpack=True)

plt.style.use('science')
fig, ax = plt.subplots()
plt.title(names[2])

ax.plot(data_pos[0], data_pos[1], color='red')

ax.set_xlabel(names[3])
ax.set_ylabel(names[4])
ax.legend(loc='upper right')

plt.tight_layout()
plt.savefig(names[1], dpi=250)

