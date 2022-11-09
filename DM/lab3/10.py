def razb(n, st, maxi):
    if n == 0:
        print(st)
    for i in range(1, n + 1):
        if (i < maxi):continue
        if maxi < i: maxi = i
        if (st == ""):
            razb(n - i, st + str(i), maxi)
        else:
            razb(n - i, st + "+" + str(i), maxi)
 
n = int(input())
razb(n, "", 0)