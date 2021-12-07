n = int(input())

def adjacentPoints(point):
  left = True
  bottom = True
  if point[0] == 0:
    left = False
  if point[1] == 0:
    bottom = False
  points = [[point[0], point[1] + 1], [point[0] + 1, point[1]]]
  if left == True:
    points.append([point[0] - 1, point[1]])
  if bottom == True:
    points.append([point[0], point[1] - 1])
  return points

startingPoints = []

for i in range(n):
  startingPoints.append([*map(int, input().split())])

currentPoints = []

for i in range(n):
  currentPoints.append(startingPoints[i])
  comfortableCows = 0
  for point in currentPoints:
    adjacentPointList = [*filter(lambda adjacentPoint: adjacentPoint in currentPoints, adjacentPoints(point))]
    if len(adjacentPointList) == 3:
      comfortableCows = comfortableCows + 1
  print(comfortableCows)
