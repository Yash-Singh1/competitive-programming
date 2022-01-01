import sys

def main():
  sys.stdin.readline()
  prefered = [*map(int, sys.stdin.readline().split())]
  current = [*map(int, sys.stdin.readline().split())]
  diff = [prefered[currentIndex] - currentTemp for currentIndex, currentTemp in enumerate(current)]
  commands = 0
  while not(all(temp == 0 for temp in diff)):
    diffNeeds = ['i' if difference > 0 else ('n' if difference == 0 else 'd') for difference in diff]
    if diffNeeds.count('i') > diffNeeds.count('d'):
      lastIndex = -diffNeeds[::-1].index('i')
      sliceIt = slice(diffNeeds.index('i'), None if lastIndex == 0 else lastIndex)
      diff[sliceIt] = [increaseThis - 1 for increaseThis in diff[sliceIt]]
    else:
      lastIndex = -diffNeeds[::-1].index('d')
      sliceIt = slice(diffNeeds.index('d'), None if lastIndex == 0 else lastIndex)
      diff[sliceIt] = [decreaseThis + 1 for decreaseThis in diff[sliceIt]]
    commands += 1
  print(commands)

main()
