firstLine = [*map(int, input().split(' '))]
k = firstLine[0]
n = firstLine[1]
authors = input().split(' ')

publications = []
for i in range(k):
  publications.append(input().split(' '))

def findIndex(flist, func):
    for i,v in enumerate(flist):
        if func(v): return i
    return -1

def interpretPublication(publication):
  workDone = []
  for publicationAuthorIndex, publicationAuthor in enumerate(publication):
    if publicationAuthorIndex == 0:
      workDone.append([publicationAuthor])
    elif sorted([publication[publicationAuthorIndex - 1], publicationAuthor])[1] is publicationAuthor:
      workDone[-1].append(publicationAuthor)
    else:
      workDone.append([publicationAuthor])
  return workDone

def workDoneToOutput(workDone):
  authorsInfo = []
  for authorIndex, author in enumerate(authors):
    authorInfo = []
    authorLocIndex = findIndex(workDone, lambda group: author in group)
    for inspectingAuthorIndex, inspectingAuthor in enumerate(authors):
      inspectingAuthorLocIndex = findIndex(workDone, lambda group: inspectingAuthor in group)
      if inspectingAuthorIndex == authorIndex:
        authorInfo.append('B')
      elif authorLocIndex < inspectingAuthorLocIndex:
        authorInfo.append('0')
      elif authorLocIndex > inspectingAuthorLocIndex:
        authorInfo.append('1')
      else:
        authorInfo.append('?')
    authorsInfo.append(authorInfo)
  return authorsInfo

authorsInfo = []

def mergeAuthorsInfo(first, second):
  if first == []:
    return second
  else:
    return [*map(lambda authorInfo: [
          *map(
            lambda authorInfoPiece: second[authorInfo[0]][authorInfoPiece[0]] if authorInfoPiece[1] == '?' else authorInfoPiece[1],
            enumerate(authorInfo[1])
          ),
        ],
        enumerate(first)
      )
    ]

for publication in publications:
  workDone = interpretPublication(publication)
  authorsInfo = mergeAuthorsInfo(authorsInfo, workDoneToOutput(workDone))

for authorInfo in authorsInfo:
  print(''.join(authorInfo))
