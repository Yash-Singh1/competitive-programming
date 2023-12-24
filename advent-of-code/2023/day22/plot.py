# Coped from Shrey Vishen, he is better at visualization than me

import matplotlib.pyplot as plt

content=open("in.txt").read().splitlines()
x1p = []
y1p = []
z1p = []
x2p = []
y2p = []
z2p = []
for line in content:
    p1, p2 = line.split("~")
    x1, y1, z1 = p1.split(",")
    x2, y2, z2 = p2.split(",")
    x1p.append(int(x1))
    y1p.append(int(y1))
    z1p.append(int(z1))
    x2p.append(int(x2))
    y2p.append(int(y2))
    z2p.append(int(z2))

import matplotlib.pyplot as plt


def get_cmap(n, name='hsv'):
    '''Returns a function that maps each index in 0, 1, ..., n-1 to a distinct 
    RGB color; the keyword argument name must be a standard mpl colormap name.'''
    return plt.cm.get_cmap(name, n)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

cmap = get_cmap(len(x1p))

# Scatter plot
for i in range(len(x1p)):
    x = [x1p[i], x2p[i]]
    y = [y1p[i], y2p[i]]
    z = [z1p[i], z2p[i]]
    ax.plot(x, y, z, c=cmap(i), linestyle='-', linewidth=2)

# Set axis labels
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

# Show the plot
plt.show()