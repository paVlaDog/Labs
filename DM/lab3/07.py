n = int(input())
buffer = []
fact = [1] * (n + 1)
for i in range(1, n + 1):
    fact[i] = fact[i - 1]*i
    buffer.append([i, 0])
#print(fact[n])
num = []
for i in range(fact[n]):
    for j in range(n, 0, -1):
        nomer = i % fact[j] // fact[j - 1]
        for k in range(len(buffer)):
            if (nomer == 0 and buffer[k][1] == 0): 
                nomer = k
                #print(nomer)
                buffer[k][1] = 1
                break
            if (buffer[k][1] == 0):
                nomer-=1
        num.append(buffer[nomer][0])
    print(*num)
    num = []
    for j in range(len(buffer)):
        buffer[j][1] = 0