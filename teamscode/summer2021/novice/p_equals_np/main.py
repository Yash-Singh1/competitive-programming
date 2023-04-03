givenInput = input()
x = int(givenInput.split(' ')[0])
y = int(givenInput.split(' ')[1])

total = 0

for xVal in range(x + 1):
    for yVal in range(y + 1):
        if (xVal == 0 and yVal == 0) or xVal == 1 or yVal == 0:
            total += 1

print(total)
