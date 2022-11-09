a = input().split()

n = int(a[0])
k = int(a[1])

masVal = [[0]*n for i in range(k)]

for i in range(k):
    a = input().split()
    for j in range(n):
        masVal[i][j] = int(a[j])

correctCol = list(range(0, n, 1))
ansTrue = 0

while (len(masVal) != 0 and not(ansTrue)):
    singleNum = -1
    singleNumCol = -1

    for i in range(len(masVal)):
        coun = 0
        for j in correctCol:
            if (masVal[i][j] != -1):
                coun+=1
                singleNum = masVal[i][j]
                singleNumCol = j
        if (coun == 1):
            coun = -1
            break
    
    #print(singleNumCol)
    if (coun == -1):
        i = 0
        while (i < len(masVal)):
            if (masVal[i][singleNumCol] == singleNum):
                del masVal[i]
                i-=1
            elif (1 - masVal[i][singleNumCol] == singleNum):
                singleFalse = 1
                for j in correctCol:
                    if (masVal[i][j] != -1 and j != singleNumCol):
                        singleFalse = 0
                if (singleFalse):
                    ansTrue = 1
            i += 1
        correctCol.remove(singleNumCol)

    if (coun != -1):
        break

if (ansTrue):
    print("YES")
else:
    print("NO")

#print(*masVal)
#print()
#print(*correctCol)


