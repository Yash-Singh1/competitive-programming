from sympy import Plane, Point3D

from z3 import *

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

p = 0

x,y,z,vx,vy,vz = Int('x'), Int('y'), Int('z'), Int('vx'), Int('vy'), Int('vz')
t = [Int('T' + str(i)) for i in range(len(lines[:3]))]
ans = Solver()

for i, line in enumerate(lines[:3]):
  print(i)
  ans.add(x + t[i] * vx == line[0]+t[i]*line[3])
  ans.add(y + t[i] * vy == line[1]+t[i]*line[4])
  ans.add(z + t[i] * vz == line[2]+t[i]*line[5])

print(ans.to_smt2())

ans.check()
print('checked')
print(ans.model().eval(x+y+z))
