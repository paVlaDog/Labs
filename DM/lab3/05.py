import math

inp = input().split()
n = int(inp[0])
k = int(inp[1])
num = [""]*(k**n)
for i in range(k**n):
    for j in range(n, 0, -1):
        if ((i // k**j) % 2 == 0):
            num[i] += str((i // k**(j - 1)) % k)
        else:
            num[i] += str(k - 1 - (i // k**(j - 1)) % k)
print(*num, sep = "\n")