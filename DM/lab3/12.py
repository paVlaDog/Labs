def mn(mas, masAns, maxi, count, numOfSet, maxNumOfSet):
    if (count == len(mas) and numOfSet == maxNumOfSet):
        for j in  range(len(masAns)):
            print(masAns[j])
        print()
    elif(numOfSet < maxNumOfSet):
        for j in range(len(mas)):
            if (mas[j][1] == 0):
                mas1 = mas.copy()
                mas1[j] = [mas1[j][0], 1]
                masAns1 = masAns.copy()
                masAns1.append(str(mas[j][0]) + " ")
                mn(mas1, masAns1, mas[j][0], count + 1, numOfSet + 1, maxNumOfSet)
                break
    for i in range(len(mas)):
        if (mas[i][1] == 0 and maxi <= mas[i][0]):
            mas1 = mas.copy()
            mas1[i] = [mas1[i][0], 1]
            masAns1 = masAns.copy()
            masAns1[numOfSet - 1] = masAns1[numOfSet - 1] + str(mas[i][0]) + " "
            mn(mas1, masAns1, mas[i][0], count + 1, numOfSet, maxNumOfSet)

inp = input().split()
n = int(inp[0])
k = int(inp[1])
mas = []
for i in range(n):
    mas.append([i + 1, 0])
mas1 = mas.copy()
mas[0][1] = 1
masAns = []
masAns.append("1 ")
mn(mas, masAns, 0, 1, 1, k)
