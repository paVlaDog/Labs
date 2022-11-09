#DM7
from math import log, ceil

n = int(input())
num = input().split()
maxNum  = 0
trash = int(input())
num.append(trash)

for i in range(n + 1):
    num[i] = int(num[i])
    maxNum = max(num[i], maxNum)


lenVec = 33
binNum = [[0]*lenVec for i in range(n + 1)]

for i in range(n + 1):
    a = bin(num[i])[2:]
    for j in range(1, lenVec + 1):
        if (len(a) >= j):
            binNum[i][lenVec - j] = int(a[len(a) - j])
        else:
            binNum[i][lenVec - j] = 0
            #binNum[i][lenVec - j] = -1



impossible = 0
for i in range(lenVec):
    for j in range(i + 1, lenVec):
        numA = 0
        numB = 0
        #onlyMinusOne = 1
        for k in range(n):
            if (binNum[k][i] == 1):
                numA += 2**k
            if (binNum[k][j] == 1):
                numB += 2**k
            #if (binNum[k][i] != -1):
            #    onlyMinusOne = 0
        #if (onlyMinusOne and binNum[n][i] == 1):
        #    impossible = 1
        if (numA == numB and max(binNum[n][i],binNum[n][j]) == 1 and min(binNum[n][i], binNum[n][j]) != 1):
            impossible = 1
if (impossible):
    print("Impossible")
else:
    firstMonom = 1
    s = ""
    for i in range(lenVec):
        if (binNum[n][i] == 1):
            if (not(firstMonom)):
                s = s + "|"
            if (n > 1):
                s = s + "("
            for j in range(n):
                if (binNum[j][i] == 1):
                    s = s + str(j + 1)
                else:
                    s = s + "~" + str(j + 1) 
                if (j != n - 1):
                    s = s + "&"
                firstMonom = 0
            if (n > 1):
                s = s + ")"
    if (s == ""):
        s = "1&~1"
    print(s)

