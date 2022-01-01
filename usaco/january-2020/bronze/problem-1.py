k = int(input().split(' ')[1])

words = input().split(' ')

currentLine = []

for word in words:
  currentLine.append(word)
  if len(''.join(currentLine)) > k:
    currentLine.pop()
    print(' '.join(currentLine))
    currentLine = [word]

print(' '.join(currentLine))
