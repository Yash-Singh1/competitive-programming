firstLine = [*map(int, input().split(' '))]
k = firstLine[0]
n = firstLine[1]

for i in range(n):
  x = int(input())
  speed = 0
  distance = 0
  time = 0
  while distance < k:
    time += 1
    distanceLeft = k - distance
    if sum(range(*([speed + 1, x + 1] if speed + 1 < x else [x, speed + 2]))) - (0 if speed + 1 > x else x) <= distanceLeft:
      speed += 1
    elif sum(range(*([speed, x + 1] if speed < x else [x, speed + 1]))) > distanceLeft:
      speed -= 1
    distance += speed
  print(time)
