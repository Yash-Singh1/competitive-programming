firstLine = [*map(int, input().split(' '))]
n = firstLine[0]
l = firstLine[1]
cSequence = [*map(int, input().split(' '))]

def findHIndex(papers):
  papers.sort()
  hIndex = 0
  for i in range(1, n):
    if len([*filter(lambda paper: paper >= i, papers)]) >= i:
      hIndex = i
  return hIndex

for cite in range(l):
  hIndex = findHIndex(cSequence)
  minDetails = [None, float('inf')]
  for citationIndex, citation in enumerate(cSequence):
    if citation >= hIndex and citation < minDetails[1]:
      minDetails[0] = citationIndex
      minDetails[1] = citation
  cSequence[minDetails[0]] += 1

print(findHIndex(cSequence))
