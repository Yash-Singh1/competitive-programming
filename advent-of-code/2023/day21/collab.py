from collections import deque

content = open(0, "r").read()
max = 64
width = 2*max+1
import math
grid = [[cell for cell in row] for row in content.split("\n")]
width, height = (len(grid[0]), len(grid))
times = math.ceil(max*3/len(grid[0]))
grid = [row * times for row in grid] * times

x, y = (0, 0)

for i in range((height + 2) * ((times - 1) // 2), len(grid)):
    for j in range((width + 2) * ((times - 1) // 2), len(grid[0])):
        if grid[i][j] == 'S':
            x, y = (i, j)
            break
    else:
        continue
    break

for i in range(len(grid)):
    for j in range(len(grid[0])):
        if grid[i][j] == 'S':
            grid[i][j] = '.'

q = deque([[x, y]])
stepsin = [[-1 for _ in row] for row in grid]

mx = [1, 0, -1, 0]
my = [0, 1, 0, -1]

while len(q) > 0:
    x, y = q.popleft()
    if stepsin[x][y] == max: continue
    for k in range(4):
        nx = x + mx[k]
        ny = y + my[k]
        if nx < 0 or nx >= len(grid[0]) or ny < 0 or ny >= len(grid): continue
        if grid[nx][ny] == '#' or stepsin[nx][ny] != -1: continue
        stepsin[nx][ny] = stepsin[x][y] + 1
        q.append([nx, ny])

ans = 0
for row in range(len(grid)):
    outputed_line = ""
    for column in range(len(grid[0])):
        if stepsin[row][column] != -1 and stepsin[row][column] % 2 == max % 2:
            ans += 1
            if (row, column) == (x, y):
                outputed_line += 'S'
            else:
                outputed_line += 'O'
        else:
            outputed_line += grid[row][column]
    print(outputed_line)

print(ans)

# def check_grid(x, y):
#     if x < 0:
#         x %= len(grid[0])
#         if x < 0:
#             x = (len(grid[0]) - abs(x))%len(grid[0])
#     if y < 0:
#         y %= len(grid)
#         if y < 0:
#             y = (len(grid) - abs(y))%len(grid)
#     if x >= len(grid[0]): x %= len(grid[0])
#     if y >= len(grid): y %= len(grid)
#     if grid[x][y] == '#': return False
#     else: return True
# tot = 0
# for dy in range(width // 2 + 1):
#     sy = y + dy
#     sx = x - (width // 2) + dy
#     for dx in range(0, width - dy*2, 2):
#         val = check_grid(sx+dx, sy)
#         if val: tot += 1

# for dy in range(1, width // 2 + 1):
#     sy = y - dy
#     sx = x - (width // 2) + dy
#     for dx in range(0, width - dy*2, 2):
#         val = check_grid(sx+dx, sy)
#         if val: tot += 1
# print(tot - 1)
