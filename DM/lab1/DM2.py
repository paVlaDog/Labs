#DM2.py
 
n = int(input())
f1 = []
classP = [1]*5
for i in range(n):
    f1.append(input().split())
 
for i in range(n):
    l = len(f1[i][1])
 
    if (f1[i][1][0] == '1'):
        classP[0] = 0
 
    if (f1[i][1][l - 1] == '0'):
        classP[1] = 0
 
    jump = l // 2
    while (jump != 0):
        for j in range(l):
            if ((j // jump) % 2 == 0):
                if (f1[i][1][j] > f1[i][1][j + jump]):
                    classP[2] = 0
        jump = jump // 2
 
    
    if (l == 1): classP[3] = 0
    for j in range(l//2):
        if (f1[i][1][j] == f1[i][1][l - j - 1]):
            classP[3] = 0
 
    jump = l // 2
    while (jump != 0):
        for j in range(l):
            if (j % (2 * jump) == 0):  
                flagDif = f1[i][1][j] != f1[i][1][j + jump]
            if (j % (2*jump) < jump):
                if (flagDif and f1[i][1][j] == f1[i][1][j + jump]):
                    classP[4] = 0
                if (not(flagDif) and f1[i][1][j] != f1[i][1][j + jump]):
                    classP[4] = 0
            j += jump
        jump = jump // 2
 
notBasis = 0
for i in range(5):
    if (classP[i] == 1):notBasis = 1
if (notBasis == 0):
    print("YES")
else:
    print("NO")
 
#print(*classP)