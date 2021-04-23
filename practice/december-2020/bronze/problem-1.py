# Do You Know Your ABCs?

inputValues = map(lambda x : int(x), raw_input().split())
highest = max(inputValues)
inputValues.remove(highest)
combinations = []
for index, value in enumerate(inputValues):
  if index <= 3:
    for index2, value2 in enumerate(inputValues[index + 1 : 4]):
      for index3, value3 in enumerate(inputValues[index2 + 1 : 5]):
        combinations.append([value, value2, value3])

def sort(arr):
  arr.sort()
  return arr

print(' '.join(map(str, sort(filter(lambda combination: sum(combination) == highest, combinations)[0]))))
