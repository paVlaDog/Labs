inp = input().split()
l = int(inp[0])
num = int(inp[1])

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

su = l
ma = 1
ans = ""

while (su > 0):
    #print(num, mas[su - ma][ma], su - ma, ma)
    if (su > ma and num >= mas[su - ma][ma]):
        num -= mas[su - ma][ma]
        ma += 1  
    else:
        ans += str(ma)
        ans += "+"
        #num -= mas[su][ma]
        su -= ma
        

print(ans[:len(ans) - 1])