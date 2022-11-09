#DM5

n = int(input())
count1, count0 = 0, 0

out1 = []
masVec = [[0]*(2**n) for i in range(2**n)]
for i in range(2**n):
    a = input().split()
    masVec[0][i] = int(a[1])
    out1.append(a[0])

for i in range(1, 2**n):
    for j in range(2**n - i):
        masVec[i][j] = (masVec[i - 1][j] + masVec[i - 1][j + 1]) % 2

for i in range(2**n):
    print(out1[i], masVec[i][0])
