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


num1 = num + 1
deep = 0
now = 0
ans = ""
vec = list()

for i in range(l):
    if (len(vec) == 0 or vec[len(vec) - 1] == "("):
        if (mas[l - i - 1][deep + 1] * (2 ** ((l - i - 1 - deep - 1)//2)) + mas[l - i - 1][deep - 1] * (2 ** ((l - i - 1 - deep + 1)//2)) < num1):
            ans += '['
            num1 -= mas[l - i - 1][deep + 1] * (2 ** ((l - i - 1 - deep - 1)//2)) + mas[l - i - 1][deep - 1] * (2 ** ((l - i - 1 - deep + 1)//2))
            deep += 1    
            vec.append("[")
        elif (mas[l - i - 1][deep + 1] * (2 ** ((l - i - 1 - deep - 1)//2)) < num1):
            ans += ')'
            num1 -= mas[l - i - 1][deep + 1]* (2 ** ((l - i - 1 - deep - 1)//2))
            deep -= 1  
            del vec[len(vec) - 1]
        else:
            ans += '('
            deep += 1
            vec.append("(")
    elif (vec[len(vec) - 1] == "["):
        #print(num1, mas[l - i - 1][deep + 1])
        if (mas[l - i - 1][deep + 1] * 2 * (2 ** ((l - i - 1 - deep - 1)//2)) < num1):
            ans += ']'
            num1 -= mas[l - i - 1][deep + 1] * 2 * (2 ** ((l - i - 1 - deep - 1)//2))
            deep -= 1   
            del vec[len(vec) - 1]
        elif (mas[l - i - 1][deep + 1] * (2 ** ((l - i - 1 - deep - 1)//2)) < num1):
            ans += '['
            num1 -= mas[l - i - 1][deep + 1] * (2 ** ((l - i - 1 - deep - 1)//2))
            deep += 1  
            vec.append("[")  
        else:
            ans += '('
            deep += 1
            vec.append("(")
    else:
        print("WTF???")
print(ans)