st = input()
l = len(st)
 
mas = [[0]*(l + 2) for i in range(l)]
 
mas[0][0] = 1
for i in range(1, l):
    for j in range(l):
        if (j > 0):
            mas[i][j] = mas[i - 1][j - 1]
        if (j < l - 1):
            mas[i][j] += mas[i - 1][j + 1]
 
#for i in range(l):
#    for j in range(l):
#        print(mas[i][j], end = " ")
#    print()
     
ans = 0
balans = 0
for i in range(l):
    if (st[i] == '('):
        balans+=1
    else:
        ans += mas[l - i - 1][balans + 1]
        balans-=1
     
print(ans)