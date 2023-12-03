#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
import sys

# Parameters for terrain generation
width = 256
height = 256

# Initialize an empty 3D array to store terrain data
terrain = np.loadtxt(sys.argv[1])

# Create a visualization of the terrain
x_coords, y_coords = np.meshgrid(np.arange(width), np.arange(height))
fig = plt.figure()
ax = fig.add_subplot(111)
terrain_plot = ax.imshow(terrain, cmap='terrain')
ax.contour(terrain,[0])

# Load and plot file path.dat

path = np.loadtxt(sys.argv[2])

start = path[0]
target = path[-1]

ax.scatter([start[0], target[0]],[start[1],target[1]],s=120,marker='+',color="red")

ax.plot(*zip(*path),color="red")

ax.set_aspect('equal')
ax.set_xlabel('X')
ax.set_ylabel('Y')

plt.colorbar(terrain_plot)
plt.show()
