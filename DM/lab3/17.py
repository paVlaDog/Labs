inp = input().split()
l = 2 * int(inp[0])
num = int(inp[1])

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

num1 = num + 1
deep = 0
ans = ""
for i in range(l):
    #print(i, deep)
    if (mas[l - i - 1][deep + 1] < num1):
        ans += ')'
        num1 -= mas[l - i - 1][deep + 1]
        deep-=1
        
    else:
        deep+=1
        ans += '('
    
print(ans)