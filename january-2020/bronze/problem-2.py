import math

n = int(input())
b = [*map(int, input().split(' '))]

def permutations(arr):
  if len(arr) == 1:
    return [arr]
  return sum([
    *map(
      lambda value: [
        *map(
          lambda endValue: [value, *endValue],
          permutations([*filter(lambda innerValue: value != innerValue, arr)])
        )
      ],
      arr
    )
  ], [])

possiblePermutations = permutations(range(1, n + 1))

for possiblePermutation in possiblePermutations:
  valid = True
  
  for intIndex, integer in enumerate(b):
    if possiblePermutation[intIndex] + possiblePermutation[intIndex + 1] != integer:
      valid = False
  
  if valid:
    print(' '.join([*map(str, possiblePermutation)]))
    break
