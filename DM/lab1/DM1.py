def myInput(tabl):
    for i in range(n):
        row = input().split()
        for i in range(len(row)):
            row[i] = int(row[i])
        tabl.append(row)
    return tabl
    
def ref_aref(kind, tabl):
    for i in range(n):
        if (tabl[i][i] == 0):
            kind[0] = 0
        else:
            kind[1] = 0
    return kind
    
def sim_asim(kind, tabl):
    for i in range(n):
        for j in range(i):
            if (tabl[i][j] == tabl[j][i]):
                if (tabl[i][j] == 1):
                    kind[3] = 0
            else:
                kind[2] = 0
    return kind

def tranz(kind, tabl):
    for i in range(n):
        for j in range(n):
            if (tabl[i][j] == 1):
                for k in range(n):
                    if (tabl[j][k] == 1):
                        if (tabl[i][k] == 0):
                            kind[4] = 0
    return kind

n = int(input()) 
kind1 = list([1]*5)
kind2 = list([1]*5)
tabl1 = []
tabl2 = []

tabl1 = myInput(tabl1)
kind1 = ref_aref(kind1, tabl1)
kind1 = sim_asim(kind1, tabl1)
kind1 = tranz(kind1, tabl1)
tabl2 = myInput(tabl2)
kind2 = ref_aref(kind2, tabl2)
kind2 = sim_asim(kind2, tabl2)
kind2 = tranz(kind2, tabl2)

newTabl = [[0] * n for i in range(n)]
            
for i in range(5):
    print(kind1[i], end = " ")
print()
for i in range(5):
    print(kind2[i], end = " ")
print()

for i in range(n):
    for j in range(n):
        if (tabl1[i][j] == 1):
            for k in range(n):
                if (tabl2[j][k] == 1):
                    newTabl[i][k] = 1

for i in range(n):
    for j in range(n):
        print(newTabl[i][j], end = " ")
    print()