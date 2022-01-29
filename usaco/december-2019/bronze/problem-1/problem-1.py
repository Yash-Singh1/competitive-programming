firstLine = [*map(int, input().split(' '))]
k = firstLine[0]
n = firstLine[1]

sessions = []

for i in range(k):
  sessions.append([*map(int, input().split(' '))])

nRange = range(1, n + 1)
pairs = []

for nVal in nRange:
  for deepNVal in [*filter(lambda nValue: nValue != nVal, nRange)]:
    pairs.append([nVal, deepNVal])

def pairInSession(pair, session):
  return session[pair[0] - 1] > session[pair[1] - 1]

print(len([*filter(lambda pair: all(pairInSession(pair, session) for session in sessions), pairs)]))
