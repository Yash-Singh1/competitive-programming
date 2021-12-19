import math

n = input()
stalls = input()

maxSpace = []

spaces = stalls.split('1')

for spaceIndex, stall in enumerate(spaces):
  if stall != '':
    if len(maxSpace) == 0 or len(stall) + 1 >= maxSpace[-1][0]:
      maxSpace.append([len(stall) + 1, spaceIndex])
    elif len(maxSpace) == 1 or len(stall) + 1 > maxSpace[-2][0]:
      maxSpace.insert(-1, [len(stall) + 1, spaceIndex])
    else:
      maxSpace.insert(0, [len(stall) + 1, spaceIndex])

changedD = None
dFirst = math.ceil((maxSpace[-1][0] - 1) / 2) if maxSpace[-1][1] == 0 or maxSpace[-1][1] == len(spaces) - 1 else math.floor((maxSpace[-1][0] - 2) / 2)
dSecond = maxSpace[-2][0] - 1 if maxSpace[-2][1] == 0 or maxSpace[-2][1] == len(spaces) - 1 else math.ceil(maxSpace[-2][0] / 2)
if dFirst > dSecond:
  changedD = dFirst
else:
  changedD = dSecond

print(min([min([*map(lambda arr: arr[0], maxSpace)]), changedD]))
