
while(1):
    inp = input().split()
    n = int(inp[0])
    k = int(inp[1])
    if (n == 0 and k == 0): break
    mas = []
    for i in range(k):
        mas.append(list())
        mas[i] = input().split()
        for j in range(len(mas[i])):
            mas[i][j] = int(mas[i][j])

    buf = list()
    fl = 1
    i = len(mas) - 1
    while (i > -1 and fl):
        if (len(buf) != 0) and (max(buf) > mas[i][-1]):
            mini = max(buf)
            inmini = 0
            for j in range(len(buf)):
                if (buf[j] > mas[i][-1] and buf[j] <= mini):
                    mini = buf[j]
                    inmini = j
            mas[i].append(mini)
            del buf[inmini]
            break
        for j in range(len(mas[i]) - 1, -1, -1):
            if (len(buf) != 0) and (j != 0) and (max(buf) > mas[i][j]):
                mini = max(buf)
                inmini = 0
                for ij in range(len(buf)):
                    if (buf[ij] > mas[i][j] and buf[ij] <= mini):
                        inmini = ij
                        mini = buf[inmini]
                trash = mas[i][j]
                mas[i][j] = mini
                del buf[inmini]
                buf.append(trash)
                fl = 0
                break
            else:
                buf.append(mas[i][-1])
                del mas[i][-1]
                if len(mas[i]) == 0:
                    del mas[i]
        i-=1
    buf.sort()
    for i in range(0, len(buf)):
        mas.append([buf[i]])

    #print(mas)
    print(n, len(mas))
    for i in range(len(mas)):
        for j in range(len(mas[i])):
            print(mas[i][j], end = " ")
        print()

    tra = input()