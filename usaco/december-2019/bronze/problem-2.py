n = int(input())
chars = input()

for k in range(1, n):
  words = []
  for charStarting in range(0, n - k + 1):
    words.append(chars[charStarting: charStarting + k])
  if len(words) == len(set(words)):
    print(k)
    break
