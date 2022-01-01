import sys

def main():
  n = int(sys.stdin.readline())
  lineup = sys.stdin.readline()
  throwout = 0
  for length in range(3, n + 1):
    for pos in range(n - length + 1):
      substr = lineup[pos:pos + length]
      if substr.count('G') == 1 or substr.count('H') == 1:
        throwout += 1
  print(throwout)

main()
