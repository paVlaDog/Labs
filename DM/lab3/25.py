inp = input().split()
n = int(inp[0])
k = int(inp[1])
flag = 0

soch = input().split()
for i in range(len(soch)):
    soch[i] = int(soch[i])

if (soch[len(soch) - 1] != n):
    soch[len(soch) - 1]+=1
    flag = 1
else:
    for i in range(len(soch) - 2, -1, -1):
        if (soch[i] + 2 <= soch[i + 1]):
            soch[i]+=1
            for j in range(i + 1, len(soch)):
                soch[j] = soch[j - 1] + 1
            flag = 1
            break

if (flag):
    print(*soch)
else:
    print(-1)