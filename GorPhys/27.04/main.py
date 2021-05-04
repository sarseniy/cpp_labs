import os
import matplotlib.pyplot as plt
import numpy as np
from matplotlib import pyplot as plt
from celluloid import Camera
import networkx as nx
from matplotlib.animation import FuncAnimation, PillowWriter

x = []
y = []

f = open('output.txt', 'r')
for line in f:
    yt = line.strip().split(' ')
    y.append(yt)
    xt = []
    for i in range(len(yt)):
        xt.append(i)
    x.append(xt)
    print()



fig = plt.figure()
camera = Camera(fig)
for i in range(len(y)):
    plt.plot(x[i], y[i])
    camera.snap()
animation = camera.animate()
animation.save('celluloid_minimal.gif')
