n = int(input())

paths = []

for i in range(n):
    paths.append(input())

for path in paths:
    turns = 0
    lastDir = path[0]
    for dir in path:
        if lastDir != dir:
            if (lastDir == 'N' and dir == 'E') or (lastDir == 'E' and dir == 'S') or (lastDir == 'S' and dir == 'W') or (lastDir == 'W' and dir == 'N'):
              turns = turns + 1
            else:
              turns = turns - 1
        lastDir = dir
    if turns > 0:
      print('CW')
    else:
      print('CCW')
