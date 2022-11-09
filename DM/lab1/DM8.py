#DM8
n = int(input())
n = n - 1
s = "((A0|B0)|(A0|B0))"
for i in range(1, n + 1):
    s = "(" + s + "|((A" + str(i) + "|A" + str(i) + ")|(B" + str(i) + "|B" + str(i) + ")))"
    s = "(" + s + "|(A" + str(i) + "|B" + str(i) + "))"
print(s)