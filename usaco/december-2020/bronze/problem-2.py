def getCombinations(amount, lst):
  if amount == len(lst):
    return [lst]
  elif amount == 1:
    return map(lambda valueToBeList: [valueToBeList], lst)
  combinations = []
  for index, value in enumerate(lst):
    if index + amount <= len(lst):
      combinations.append(lst[index : index + amount])
  return combinations

n = int(raw_input())
petals = map(lambda part: int(part), raw_input().split())

overallCombinations = []
for amount in range(1, n):
  overallCombinations.extend(getCombinations(amount, petals))

print(len(filter(lambda combination: sum(combination) / float(len(combination)) in combination, overallCombinations)))
