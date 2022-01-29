import sys

a, b = map(int, sys.stdin.readline().split())
c, d = map(int, sys.stdin.readline().split())

print((b - a) + (d - c) - max(min(b, d) - max(a, c), 0))
