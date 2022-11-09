def myBin(numb):
    ans = ""
    while numb != 0:
        ans = str(numb % 2) + ans
        numb //= 2
    return ans

n = int(input())
for i in range(2**n):
    num = myBin(i)
    num = "0"*(n-len(num)) + num
    print(num)

