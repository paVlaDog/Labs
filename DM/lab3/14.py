n = int(input())
inp = input().split()
fact = [1] * (n + 1)
buffer = []
ans = 0
for i in range(1, n + 1):
    fact[i] = fact[i - 1]*i
    buffer.append([i, 0])
num = []
for i in range(n - 1):
    nomer = 0
    for j in range(len(buffer)):
        if (buffer[j][0] == int(inp[i])): 
            ans += fact[n - i - 1]*nomer
            buffer[j][1] = 1
            break
        if (buffer[j][1] == 0):
            nomer+=1
print(ans)