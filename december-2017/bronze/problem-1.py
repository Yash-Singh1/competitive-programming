import sys

def main():
  b1x1, b1y1, b1x2, b1y2 = map(int, sys.stdin.readline().split())
  b2x1, b2y1, b2x2, b2y2 = map(int, sys.stdin.readline().split())
  tx1, ty1, tx2, ty2 = map(int, sys.stdin.readline().split())

  print(
    (((b1x2 - b1x1) * (b1y2 - b1y1)) -
      (
        (max(min(b1x2, tx2) - max(b1x1, tx1), 0)) *
        (max(min(b1y2, ty2) - max(b1y1, ty1), 0))
      )) + (((b2x2 - b2x1) * (b2y2 - b2y1)) -
      (
        (max(min(b2x2, tx2) - max(b2x1, tx1), 0)) *
        (max(min(b2y2, ty2) - max(b2y1, ty1), 0))
      ))
  )

main()
