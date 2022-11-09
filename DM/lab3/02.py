import math

n = int(input())
num = ["0"]*(2**n)
sum = 1
ind = n - 1
num[0] = "0"*n
for i in range(1, 2**n):
    if (i > 1 and (abs(math.log2(i) - float(int(math.log2(i))))) < 0.00001):
        sum = i*2 - 1
        ind-=1
    num[i] = num[sum - i]
    num[i] = num[i][:ind:] + "1" + num[i][ind + 1::]
print(*num, sep = "\n")