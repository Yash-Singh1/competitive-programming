n = int(raw_input())
evenAndOddBreedIds = list(map(lambda num: num % 2 == 0, map(int, raw_input().split())))
totalGroups = 0
currentGroupType = True

while True:
  if currentGroupType:
    if True in evenAndOddBreedIds:
      evenAndOddBreedIds.pop(evenAndOddBreedIds.index(True))
    elif len(list(filter(lambda cow: not(cow), evenAndOddBreedIds))) >= 2:
      evenAndOddBreedIds.pop(evenAndOddBreedIds.index(False))
      evenAndOddBreedIds.pop(evenAndOddBreedIds.index(False))
    else:
      totalGroups -= 1
      break
    totalGroups += 1
  else:
    if False in evenAndOddBreedIds:
      evenAndOddBreedIds.pop(evenAndOddBreedIds.index(False))
      totalGroups += 1
    else:
      break
  currentGroupType = not(currentGroupType)

print(totalGroups)
