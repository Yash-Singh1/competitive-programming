# this was to help me code it faster, real code is in silver.ts

# read stdin into a list of lines
lines = [line.rstrip() for line in open(0, "r").readlines()]

# split the lines by ' , ' and replace @ with , first
lines = [line.replace("@", ",").split(", ") for line in lines]

# parse ints in 2d lines
lines = [tuple(int(x) for x in line) for line in lines]

mintest = 200000000000000
maxtest = 400000000000000

# list of collisions
collisions = []

for i in range(len(lines)):
  for j in range(i+1, len(lines)):
    x1, y1, z1, vx1, vy1, vz1 = lines[i]
    x2, y2, z2, vx2, vy2, vz2 = lines[j]
    if vy2 / vx2 - vy1 / vx1 == 0:
      continue
    t = (y1 - (vy1 / vx1) * x1 - (y2 - (vy2 / vx2) * x2)) / (vy2 / vx2 - vy1 / vx1)
    if (t - x1) / vx1 < 0 or (t - x2) / vx2 < 0:
      continue
    # print('t > 0')
    if y1 - (vy1 / vx1) * x1 + t * (vy1 / vx1) < mintest or y1 - (vy1 / vx1) * x1 + t * (vy1 / vx1) > maxtest:
      continue
    # print('y match')
    if t < mintest or t > maxtest:
      continue
    collisions.append(((t - x1) / vx1, i, j))

print(len(collisions))
