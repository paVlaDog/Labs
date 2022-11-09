n = int(input())
len = 2**n
num = []
se = set()
num.append("0"*n)
se.add(num[0])
for i in range(1, len):
    prefix = num[i - 1][1::]
    if (not((prefix + "1") in se)):
        num.append(prefix + "1")
        se.add(num[i])
    else:
        num.append(prefix + "0")
        se.add(num[i])
print(*num, sep = "\n")