t = int(input())
testCases = []

for i in range(t):
    testCases.append(list(map(int, input().split(' '))))

for testCase in testCases:
    print(max(testCase), end=' ')
    if testCase[0] == testCase[1]:
        print(3)
    else:
        print(1)
