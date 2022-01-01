n = int(input())

constraints = []

for i in range(n):
  constraints.append(input().split(' must be milked beside '))

cows = ['Bessie', 'Buttercup', 'Belinda', 'Beatrice', 'Bella', 'Blue', 'Betsy', 'Sue']

def getCombinations(arr):
  if len(arr) == 1:
    return [arr]
  else:
    results = [*map(lambda element: [element, getCombinations([*filter(lambda otherElement: otherElement != element, arr)])], arr)]
    combinations = []
    for result in results:
      for subCombination in result[1]:
        combinations.append([result[0], *subCombination])
    return combinations

def cowCombinationUnderConstraint(cowCombination):
  for constraint in constraints:
    constraintIndex = cowCombination.index(constraint[0])
    if not((constraintIndex != 0 and cowCombination[constraintIndex - 1] == constraint[1]) or (constraintIndex != len(cows) - 1 and cowCombination[constraintIndex + 1] == constraint[1])):
      return False
  return True

cowCombinations = [*filter(cowCombinationUnderConstraint, getCombinations(cows))]

cowCombinationStrings = [*map(lambda cowCombination: '\n'.join(cowCombination), cowCombinations)]
cowCombinationStrings.sort()

print(cowCombinationStrings[0])
