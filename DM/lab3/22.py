st = input().split("+")
l = len(st)
#print(st)

l = 0
for i in range(len(st)):
    st[i] = int(st[i])
    l += st[i]


mas = [[0]*(l + 1) for i in range(l + 1)]

for i in range(l + 1):
    for j in range(l, -1, -1):
        if (i == j):
            mas[i][j] = 1
        elif (i < j):
            mas[i][j] = 0
        else:
            mas[i][j] = mas[i][j + 1] + mas[i - j][j]
#for i in range(l):
#    for j in range(l):
#        print(mas[i][j], end = " ")
#    print()

ans = 0
ma = 1

#print(l)
i = 0
while (l != 0):
    #print(st[i], ma)
    if (st[i] != ma):
        ans += mas[l - ma][ma]
        ma+=1
    else:
        l -= st[i]
        i+=1
        
print(ans)