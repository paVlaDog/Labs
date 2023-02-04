
with open('muggers.in') as file:
    n, k = map(int, file.readline().split())
    vec = list(map(int, file.readline().split()))
# inp = input().split()
# n = int(inp[0])
# k = int(inp[1])
# vec = [int(i) for i in input().split()]
#vec = [0] + vec
ans = [0]*(len(vec) + 1)
ans[0] = 0

for i in range(1, n + 1):
    mini = ans[i - 1]
    for j in range(1, k + 2):
        if (i - j > -1):
            mini = min(ans[i - j], mini)
    ans[i] = mini + vec[i - 1]


mini = ans[n]
#for i in range(k):
#    mini = min(ans[n - k], mini)
#print(ans)
with open('muggers.out', 'w') as file1:
    file1.write(str(mini))
# print(mini)