from statistics import mean

amount = int(input())
arr = [int(x) for x in input().split(' ')]
arr.remove(min(arr))
print(round(mean(arr), 1))
