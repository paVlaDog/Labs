mas = [[0]*6 for i in range(5)]
mas1 = [[0]*6 for i in range(5)]

for i in range(5):
    mas[i] = input().split()

for i in range(5):
    for j in range(6):
        mas[i][j] = int(mas[i][j])

for i in range(5):
    for j in range(6):
        print(mas[i][j], end = " ")
    print()

mas1[0][0] = mas[0][0]
for i in range(1, 5):
    mas1[i][0] = mas[i][0] + mas1[i - 1][0]

for j in range(1, 6):
    mas1[0][j] = mas[0][j]+ mas1[0][j - 1]

for i in range(1, 5):
    for j in range(1, 6):
        mas1[i][j] = mas[i][j] + min(mas1[i - 1][j], mas1[i][j - 1])
    print()

for i in range(5):
    for j in range(6):
        print(mas1[i][j], end = " ")
    print()

#a = 11
#p = 17
#print(24 * a % p % 6)
#print(26 * a % p % 6)
#print(54 * a % p % 6)
#print(63 * a % p % 6)