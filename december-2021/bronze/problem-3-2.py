import sys

def main():
  t = int(sys.stdin.readline())

  for subtestcase in range(t):
    n, k = map(int, sys.stdin.readline().split())
    lines = []
    for i in range(n):
      lines.append(sys.stdin.readline())
    paths = []
    if lines[1][0] != 'H':
      paths.append([1, 0, True, k])
    if lines[0][1] != 'H':
      paths.append([0, 1, False, k])
    while not(all(path[0] == n - 1 and path[1] == n - 1 for path in paths)):
      newpaths = []
      for path in paths:
        currentlyNewPaths = []
        if path[3] > 0:
          currentlyNewPaths.append([
            path[0] if path[2] == True else path[0] + 1,
            path[1] if path[2] == False else path[1] + 1,
            not(path[2]),
            path[3] - 1
          ])
        currentlyNewPaths.append([
          path[0] + 1 if path[2] == True else path[0],
          path[1] + 1 if path[2] == False else path[1],
          path[2],
          path[3]
        ])
        currentlyNewPaths = [
          *filter(
            lambda currentlyNewPath: currentlyNewPath[0] < n and currentlyNewPath[1] < n and lines[currentlyNewPath[0]][currentlyNewPath[1]] != 'H',
            currentlyNewPaths
          )
        ]
        newpaths.extend(currentlyNewPaths)
      paths = newpaths
    print(len(paths))

main()
