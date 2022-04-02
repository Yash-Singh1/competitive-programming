import statistics
import math

t = int(input())
nums = [int(x) for x in input().split(" ")]
print(math.floor(statistics.mean(nums)))
print(math.floor(statistics.median(nums)))
print(math.floor(statistics.mode(nums)))