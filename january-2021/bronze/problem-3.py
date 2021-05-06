n = int(raw_input())
heights = map(int, raw_input().split())
maxHeights = map(int, raw_input().split())

def permutations(lst):
  if len(lst) == 1:
    return [lst]
  permutationsLst = []
  for index, element in enumerate(lst):
    permutationsLst.extend(map(lambda permutation: [element] + permutation, permutations(lst[0 : index] + lst[index + 1 : len(lst)])))
  return permutationsLst

print(len(filter(lambda permutation: len(filter(lambda entryForPermutation: entryForPermutation[1] > maxHeights[entryForPermutation[0]], enumerate(permutation))) == 0, permutations(heights))))
