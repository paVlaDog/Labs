

inp = input().split()
n = int(inp[0])
k = int(inp[1])
#m = int(inp[2])
comb = input().split()


paskal = [[0] * (k + 1) for i in range(n + 1)]
for i in range(n + 1):
    for j in range(k + 1):
        if (i <= j):
            paskal[i][j] = 1
        elif (j == 0):
            paskal[i][j] = 1
        else:
            paskal[i][j] = paskal[i - 1][j] + paskal[i - 1][j - 1]
#for i in range(n  + 1):
#    for j in range(k + 1):
#        print(paskal[i][j], end = " ")
#    print()


n1 = n
k1 = k
ans = 0
nowNum = 0
index = 0
for i in range(len(comb)):
    nowNum+=1
    n1 = n1 - 1
    k1 = k1 - 1
    while (nowNum != int(comb[index])):
        nowNum+=1
        ans += paskal[n1][k1]
        #print(n1, k1, ans, nowNum, comb[index])
        n1 -= 1
    index+=1
print(ans)





#n1 = n
#k1 = k
#ans = []
#maxi = 1
#while(m > 0 or k1 > 0):
#    ans.append(maxi)
#    n1 -= 1
#    k1 -= 1
#    while (m >= paskal[n1][k1] and n1 > k1):
#        #print("!", paskal[n1][k1])
#        m -= paskal[n1][k1]
#        ans[len(ans) - 1] += 1
#        n1 -= 1
#    maxi = ans[len(ans) - 1] + 1
#print(*ans)
