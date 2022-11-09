l = int(input())
st = input().split()
#print(st)

for i in range(len(st)):
    st[i] = int(st[i])

st1 = st.copy()
ans = [0]*len(st)

for i in range(l - 2, -1, -1):
    if (st1[i] > st1[i + 1]):
        maxi = i + 1
        for j in range(i + 1, l):
            if (st1[j] > st1[maxi]) and (st1[j] < st1[i]):
                maxi = j
        st1[i], st1[maxi] = st1[maxi], st1[i]
        st1 = st1[:i + 1] + st1[:i:-1]
        ans = st1.copy()
        break

print(*ans)
ans = [0]*len(st)


for i in range(l - 2, -1, -1):
    if st[i + 1] > st[i]:
        mini = i + 1
        for j in range (l - 1, i, -1):
            if (st[j] < st[mini]) and (st[j] > st[i]):
                mini = j
        st[i], st[mini] = st[mini], st[i]
        st = st[:i + 1] + st[:i:-1]
        ans = st
        break

print(*ans)