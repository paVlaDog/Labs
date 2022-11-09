def myBin(numb):
    ans = ""
    while numb != 0:
        ans = str(numb % 2) + ans
        numb //= 2
    return ans

n = int(input())
fib = [0] * (n+2)
fib[0] = 1
fib[1] = 1
for i in range(2, n + 2):
    fib[i] = fib[i - 1] + fib[i - 2]
print(fib[n + 1])
for i in range(2**n):
    num = myBin(i)
    flag = 0
    for j in range(len(num) - 1):
        if (num[j] == "1" and num[j + 1] == "1"):
            flag = 1
            break
    if (flag == 0):
        print("0"*(n - len(num)) + num)