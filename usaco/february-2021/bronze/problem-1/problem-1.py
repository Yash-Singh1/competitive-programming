n = int(raw_input())
zodiacs = ['Ox', 'Tiger', 'Rabbit', 'Dragon', 'Snake', 'Horse', 'Goat', 'Monkey', 'Rooster', 'Dog', 'Pig', 'Rat']
comparasions = {}
for i in range(n):
  newInput = raw_input().split()
  comparasions[newInput[0]] = {
    'with': newInput[-1],
    'before': newInput[3] == 'previous',
    'zodiac': newInput[4]
  }

def compareZodiacs(originalZodiac, newZodiac, before):
  if newZodiac == originalZodiac:
    return len(zodiacs)
  if before:
    if zodiacs.index(newZodiac) < zodiacs.index(originalZodiac):
      return zodiacs.index(newZodiac) - zodiacs.index(originalZodiac)
    else:
      return - (len(zodiacs) - (zodiacs.index(newZodiac) - zodiacs.index(originalZodiac)))
  else:
    if zodiacs.index(newZodiac) > zodiacs.index(originalZodiac):
      return zodiacs.index(newZodiac) - zodiacs.index(originalZodiac)
    else:
      return len(zodiacs) - (zodiacs.index(originalZodiac) - zodiacs.index(newZodiac))

for comparasion in enumerate(comparasions.items()):
  cowName = comparasion[1][0]
  if comparasion[1][1]['with'] == 'Bessie':
    comparasions[cowName]['num'] = compareZodiacs('Ox', comparasion[1][1]['zodiac'], comparasion[1][1]['before'])
  elif cowName:
    comparasions[cowName]['num'] = compareZodiacs(list(filter(lambda comparasion2: comparasion2[0] == comparasion[1][1]['with'], comparasions.items()))[0][1]['zodiac'], comparasion[1][1]['zodiac'], comparasion[1][1]['before'])

elsieComp = comparasions['Elsie']['with']
path = ['Elsie']

while elsieComp != 'Bessie':
  path.append(elsieComp)
  elsieComp = comparasions[elsieComp]['with']

print(abs(sum(map(lambda pathPart: comparasions[pathPart]['num'], path))))
