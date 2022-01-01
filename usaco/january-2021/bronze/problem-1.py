cowphabet = raw_input()
duplicated_cowphabet = cowphabet
heard = raw_input()
amount = 1

for char in heard:
  if char in duplicated_cowphabet:
    duplicated_cowphabet = duplicated_cowphabet[duplicated_cowphabet.find(char) + 1:]
  else:
    duplicated_cowphabet += cowphabet
    amount += 1
    duplicated_cowphabet = duplicated_cowphabet[duplicated_cowphabet.find(char) + 1:]

print(amount)
