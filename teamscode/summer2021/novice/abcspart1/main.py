turns = int(input())
plays = input()
opts = ['A', 'B', 'C']

won = [0, 0, 0]

for i in range(1, turns + 1):
  count = [0, 0, 0]
  for turnChar in plays[0:i]:
    count[opts.index(turnChar)] += 1
  maximum = max(count)
  for subI in range(len(count)):
    if count[subI] == maximum:
      won[subI] += 1

print(max(won))
