n = int(input())
st = input().split()
l = len(st)
#print(st)

for i in range(len(st)):
    st[i] = int(st[i])

ans = [0]*n


for i in range(l - 2, -1, -1):
    if st[i + 1] > st[i]:
        mini = i + 1
        for j in range (i + 1, l):
            if (st[j] <= st[mini]) and (st[j] > st[i]):
                mini = j
        st[i], st[mini] = st[mini], st[i]
        st = st[:i + 1] + st[:i:-1]
        ans = st
        break

print(*ans)