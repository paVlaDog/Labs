def psp(op, cl, st, n):
    if op + cl == n:
        print(st)
    else:
        if op < n // 2:
            psp(op + 1, cl, st + "(", n)
        if op > cl:
            psp(op, cl + 1, st + ")", n)

n = int(input())
psp(0, 0, "", 2*n)
