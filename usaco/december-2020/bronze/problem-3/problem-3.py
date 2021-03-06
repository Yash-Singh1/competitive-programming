eatenPos = []
cowsNum = int(raw_input())
cowPoss = []
for cowNumber in range(cowsNum):
  currentInputSplit = raw_input().split()
  cowPoss.append({
    "direction": currentInputSplit[0],
    "x": int(currentInputSplit[1]),
    "y": int(currentInputSplit[2]),
    "done": False,
    "eaten": 0
  })

while len(filter(lambda cow: not(cow['done']), cowPoss)) > 0:
  for index, cowPos in enumerate(cowPoss):
    if not(cowPos['done']):
      cowPoss[index]['eaten'] += 1
      eatenPos.append({ "x": cowPos['x'], "y": cowPos['y'] })
      if cowPos['direction'] == 'E':
        cowPoss[index]['x'] += 1
      elif cowPos['direction'] == 'N':
        cowPoss[index]['y'] += 1
      elif cowPos['direction'] == 'S':
        cowPoss[index]['y'] -= 1
      elif cowPos['direction'] == 'W':
        cowPoss[index]['x'] -= 1
  for index, cowPos in enumerate(cowPoss):
    if not(cowPos['done']):
      foundEatenPositionsMatching = filter(lambda eatenPosition: eatenPosition['x'] == cowPoss[index]['x'] and eatenPosition['y'] == cowPoss[index]['y'], eatenPos)
      if len(foundEatenPositionsMatching) > 0:
        cowPoss[index]['done'] = True
        continue
  overallDone = True
  for index, cowPos in enumerate(cowPoss):
    if not(cowPos['done']):
      for aEatenPos in eatenPos:
        if cowPos['direction'] == 'E' and aEatenPos['x'] > cowPos['x'] and aEatenPos['y'] == cowPos['y'] or cowPos['direction'] == 'N' and aEatenPos['y'] > cowPos['y'] or cowPos['direction'] == 'S' and aEatenPos['y'] < cowPos['y'] or cowPos['direction'] == 'W' and aEatenPos['x'] < cowPos['x'] and aEatenPos['y'] == cowPos['y']:
          overallDone = False
      for cowPos2 in map(lambda entryCowPos: entryCowPos[1], filter(lambda entryCowPos: entryCowPos[0] != index and not(entryCowPos[1]['done']), enumerate(cowPoss))):
        if cowPos['direction'] == 'E' and (cowPos2['direction'] == 'N' or cowPos2['direction'] == 'S') and cowPos2['x'] > cowPos['x'] or cowPos['direction'] == 'N' and (cowPos2['direction'] == 'E' or cowPos2['direction'] == 'W') and cowPos2['y'] > cowPos['y'] or cowPos['direction'] == 'S' and (cowPos2['direction'] == 'E' or cowPos2['direction'] == 'W') and cowPos2['y'] < cowPos['y'] or cowPos['direction'] == 'W' and (cowPos2['direction'] == 'N' or cowPos2['direction'] == 'S') and cowPos2['x'] < cowPos['x']:
          overallDone = False
  if overallDone:
    for index, cowPos in enumerate(cowPoss):
      if not(cowPos['done']):
        cowPos['eaten'] = 'Infinty'
    break

for cowPos in cowPoss:
  print(cowPos['eaten'])
