firstLine = [*map(int, input().split(' '))]
n = firstLine[0]
m = firstLine[1]

grid = {
  'C': [],
  'G': [],
  '.': []
}

for i in range(1, n + 1):
  poses = [*input()]
  for posIndex, pos in enumerate(poses):
    grid[pos].append(str(i) + ',' + str(posIndex + 1))

meetups = 0

def changePos(pos, dir):
  posSplit = [*map(int, pos.split(','))]
  if dir == 'above':
    posSplit[0] -= 1
    if posSplit[0] == -1:
      return None
  elif dir == 'below':
    posSplit[0] += 1
    if posSplit[0] > n:
      return None
  elif dir == 'right':
    posSplit[1] += 1
    if posSplit[1] > m:
      return None
  elif dir == 'left':
    posSplit[1] -= 1
    if posSplit[1] == -1:
      return None
  return ','.join([*map(str, posSplit)])

grassFound = []

for cowIndex, cow in enumerate(grid['C']):
  if changePos(cow, 'above') in grid['G']:
    grassFound.append([cowIndex, changePos(cow, 'above')])
  if changePos(cow, 'right') in grid['G']:
    grassFound.append([cowIndex, changePos(cow, 'right')])
  if changePos(cow, 'left') in grid['G']:
    grassFound.append([cowIndex, changePos(cow, 'left')])
  if changePos(cow, 'below') in grid['G']:
    grassFound.append([cowIndex, changePos(cow, 'below')])

pairs = []

for cowIndex, cow in enumerate(grid['C']):
  for grassFoundLoc in [*filter(lambda grassWithCow: grassWithCow[0] != cowIndex, grassFound)]:
    if grassFoundLoc in grassFound and not([grassFoundLoc[0], cowIndex] in pairs or [cowIndex, grassFoundLoc[0]] in pairs) and (changePos(cow, 'above') == grassFoundLoc[1] or changePos(cow, 'right') == grassFoundLoc[1] or changePos(cow, 'left') == grassFoundLoc[1] or changePos(cow, 'below') == grassFoundLoc[1]):
      meetups += 1
      pairs.append([grassFoundLoc[0], cowIndex])
      grassFound = [*filter(lambda grassFoundLocation: grassFoundLocation[1] != grassFoundLoc[1], grassFound)]

print(meetups)
