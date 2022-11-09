import math

n = int(input())
num = [""]*(3**n)
for i in range(3**n):
    for j in range(n, 0, -1):
        num[i] += str(((i % 3) + (i // 3**j)) % 3)
print(*num, sep = "\n")