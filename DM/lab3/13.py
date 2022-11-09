inp = input().split()
n = int(inp[0])
k = int(inp[1])
fact = [1] * (n + 1)
buffer = []
for i in range(1, n + 1):
    fact[i] = fact[i - 1]*i
    buffer.append([i, 0])
num = []
for i in range(n, 0, -1):
    nomer = k % fact[i] // fact[i - 1]
    for j in range(len(buffer)):
        if (nomer == 0 and buffer[j][1] == 0): 
            nomer = j
            buffer[j][1] = 1
            break
        if (buffer[j][1] == 0):
            nomer-=1
    num.append(buffer[nomer][0])
print(*num)