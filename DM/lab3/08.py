def getEl(num, multiset):
    for i in range(len(multiset)):
        if (nomer == 0 and multiset[i][1] == 0):
            multiset[i][1] = 1
            return multiset[i][0]

inp = input().split()
n = int(inp[0])
k = int(inp[1])
multiset = []
fact = [1] * (n + 1)
num = []
for i in range(1, n + 1):
    fact[i] = fact[i - 1]*i
    multiset.append([i, 0])
for i in range(1, k + 1):
    num.append(i)
print(*num)
for i in range(fact[n] // fact[k] // fact[n - k] - 1):
    for j in range(k - 1, -1, -1):
        if (num[j] <= n - k + j):
            num[j]+=1
            for ij in range(j + 1, len(num)):
                num[ij] = num[j] + ij - j
            break
    print(*num)


