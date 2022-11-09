inp = input().split()
n = int(inp[0])
a = int(inp[1])
b = int(inp[2])
w = int(inp[3])
h = int(inp[4])

l = 0
r = max(w, h)
while (l != r - 1):
    mid = (l + r) // 2
    n1 = (w // (a + 2 * mid)) * (h // (b + 2 * mid))
    n2 = (h // (a + 2 * mid)) * (w // (b + 2 * mid))
    if (n1 >= n or n2 >= n):
        l = mid
    else:
        r = mid
print(l)


