mas = input().split()
mas[0] = int(mas[0])
mas[1] = int(mas[1])
masRab = [0]*(mas[0]*mas[1])
for i in range(mas[0]*mas[1]):
    masRab[i] = int(input())
 
masRab.sort()
maxNeyd = 0
 
for i in range(mas[0]):
    neyd = masRab[(i + 1)*mas[1] - 1] - masRab[i*mas[1]]
    maxNeyd = max(neyd, maxNeyd)
 
print(maxNeyd)