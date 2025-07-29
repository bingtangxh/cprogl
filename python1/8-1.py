import random

def generateMatrix(m,n):
    return [[random.randint(0,20) for x in range(n)] for y in range(m)]

m = int(input())
n = int(input())
r = generateMatrix(m,n)
p = True
for i in range(m):
    for j in range(n):
        if r[i][j] > 20:
            p = False
            break
if m > 3 and n > 3:
    if r[0][0] == r[2][2] and r[1][1] == r[1][2] and r[0][2] == r[3][0]:
        p = False

print(p)

