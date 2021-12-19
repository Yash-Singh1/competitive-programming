n = int(input())

cows = []

for i in range(n):
  line = [*map(int, input().split(' '))]
  cows.append([line[0], True if line[1] == 0 else False])

cows.sort(key=lambda cow: cow[0])

r = float('inf')

for cowIndex, cow in enumerate(cows):
  if cow[1] == True:
    if cowIndex != len(cows) - 1 and cows[cowIndex + 1][1] == False and cows[cowIndex + 1][0] - cow[0] < r:
      r = cows[cowIndex + 1][0] - cow[0]
    if cowIndex != 0 and cows[cowIndex - 1][1] == False and cow[0] - cows[cowIndex - 1][0] < r:
      r = cow[0] - cows[cowIndex - 1][0]

clusters = []

for cowIndex, cow in enumerate(cows):
  if cow[1] == True:
    continue
  if clusters == []:
    clusters = [[cow[0]]]
  elif cow[0] - clusters[-1][-1] >= r:
    clusters.append([cow[0]])
  else:
    clusters[-1].append(cow[0])

print(len(clusters))
