#Down's Tusks
 
 
n = int(input())
mas = input().split()
for i in range(n):
    mas[i] = int(mas[i])
 
mas = sorted(mas)
index = 0
ans = -1
 
for i in range(0, n + 2):
    while(1):
        if index < len(mas) and i == mas[index]:
            break
        if index < len(mas) and i < mas[index] and ans == -1:
            ans = i
            break
        index+=1
        #print(i, index)
        if (index >= len(mas)):
            if (ans == -1):
                ans = i
            break
 
print(ans)
 
#print(*mas)