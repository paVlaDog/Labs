#DM4

n = int(input())
count1, count0 = 0, 0


masVec = []
for i in range(2**n):
    masVec.append(input().split())
    if (masVec[i][1] == "1"):
        count1 += 1
    else:
        count0 += 1

arrEdge = []
for i in range(n):
    a = [1, i + 1]
    arrEdge.append(a)

if (count1 == 0):
    a = [2, 1, n + 1]
    arrEdge.append(a)
elif (count0 == 0):
    a = [3, 1, n + 1]
    arrEdge.append(a)
elif (n == 1 and masVec[0][1] == "0"):
    a = [1, 2]
    arrEdge.append(a)
else:
    if (count1 > count0):
        countCon = 0
        for i in range(2**n):
            if (masVec[i][1] == "0"):
                countCon += 1
                for j in range(1, n):
                    a = [3, len(arrEdge) + n]
                    if (masVec[i][0][j] == "0"):
                        a.append(j + 1)
                    else:
                        a.append(n + j + 1)
                    if (j == 1):
                        if (masVec[i][0][0] == "0"):
                            a[1] = 1
                        else:
                            a[1] = n + 1
                    arrEdge.append(a)
                if (countCon >= 2):
                    a = [2, len(arrEdge) + 1, len(arrEdge) + n]
                    arrEdge.append(a)

    else:
        countDiz = 0
        for i in range(2**n):
            if (masVec[i][1] == "1"):
                countDiz += 1
                for j in range(1, n):
                    a = [2, len(arrEdge) + n]
                    if (masVec[i][0][j] == "1"):
                        a.append(j + 1)
                    else:
                        a.append(n + j + 1)
                    if (j == 1):
                        if (masVec[i][0][0] == "1"):
                            a[1] = 1
                        else:
                            a[1] = n + 1
                    arrEdge.append(a)
                if (countDiz >= 2):
                    a = [3, len(arrEdge) + 1, len(arrEdge) + n]
                    arrEdge.append(a)

print(len(arrEdge) + n)
for i in range(len(arrEdge)):
    print(*arrEdge[i])
