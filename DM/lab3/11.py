def mn(n, st, maxi):
    print(st)
    for i in range(maxi + 1, n + 1):
        mn(n, st + str(i) + " ", i)

n = int(input())
mn(n, "", 0)
