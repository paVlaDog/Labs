inp = input().split()
n = int(inp[0])
m = int(inp[1])
vecM = [int(i) for i in input().split()]
vecC = [int(i) for i in input().split()]
vec = [[0]*(m+1) for i in range(n+1)]

for i in range(1, n+1):
    for j in range(m+1):
        vec[i][j] = vec[i - 1][j]
        if (j >= vecM[i - 1]):
            vec[i][j] = max(vec[i - 1][j], vec[i - 1][j - vecM[i - 1]] + vecC[i - 1])

ans = []
i = n
j = m
while (i != 0):
    if (j >= vecM[i - 1] and vec[i - 1][j - vecM[i - 1]] + vecC[i - 1] == vec[i][j]):
        ans.append(i)
        j -= vecM[i - 1]
        i -= 1
    else:
        i -= 1

print(len(ans))
for i in range(len(ans)):
    print(ans[len(ans) - i - 1], end = " ")

#for i in range(n+1):
#    for j in range(m+1):
#        print(vec[i][j], end = " ")
#    print()