razb = input().split("=")
n = razb[0]
st = razb[1].split("+")

for i in range(len(st)):
    st[i] = int(st[i])

if (len(st) == 1):
    print("No solution")
else:
    st[-2] += 1
    st[-1] -= 1
    while (len(st) > 1 and st[-2] * 2 <= st[-1]):
        if (st[-2] * 2 <= st[-1]):
            st.append(st[-1] - st[-2])
            st[-2] -= st[-1] 
    if (st[-2] > st[-1]):
            st[-2] += st[-1]
            del st[-1]
    print(n, "=", sep = "", end = "")
    for i in range(len(st)):
        if (i == len(st) - 1):
            print(st[i], sep = "", end = "")
        else:
            print(st[i], "+", sep = "", end = "")
    
    