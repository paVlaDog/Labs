#Down's Tusks
 
 
n = int(input())
mas = input().split()
for i in range(n):
    mas[i] = int(mas[i])
 
mas = sorted(mas, key=lambda ob:str(ob)[-1])
 
print(*mas)