import itertools

n = int(input())
breeds = [*map(int, input().split(' '))]

def subsequences(iterable, length):
    return [[*iterable[i: i + length]] for i in range(len(iterable) - length + 1)]

combinations = []
cows = range(1, n + 1)
for i in cows:
  if i >= 3:
    combinations.extend(subsequences(cows, i))

def validateCombination(combination):
  if combination[0] in combination[1:] or combination[-1] in combination[0: -1] or (len(set(combination[1: -1])) == 1 and len(combination) > 3):
    return False
  return True

combinations = [*filter(lambda combination: validateCombination([*map(lambda combinationPart: breeds[combinationPart[1] - 1], enumerate(combination))]), combinations)]

combinationsCount = 0
for combination in combinations:
  breedCombination = [*map(lambda combinationPart: breeds[combinationPart[1] - 1], enumerate(combination))]
  combinationsCount += len([*filter(lambda combinationPart: breedCombination.count(combinationPart) == 1, breedCombination[1: -1])])

print(combinationsCount)
