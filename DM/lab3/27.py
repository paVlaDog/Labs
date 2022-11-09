st = input()
bal = 0
fl = 1
for i in range(len(st) - 1, -1, -1):
    if (st[i] == ')'): bal+=1
    if (st[i] == '('): bal-=1
    if (st[i] == '(' and bal > 0):
        print(st[:i], end = "")
        print(')', end = "")
        bal -= 1
        otkr = (len(st) - i  - 1 - bal) // 2
        for j in range(i + 1, len(st)):
            if (otkr > 0):
                print('(', end = "")
                otkr -= 1
            else:
                print(')', end = "")
        break
    if (i == 0):
        fl = 0

if (not(fl)):
    print("-")
#else:
#    print(newst)