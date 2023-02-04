s1 = input()
s2 = input()
vec = [[0]*(len(s2) + 1) for i in range(len(s1) + 1)]

for j in range(1, len(s2) + 1):
    vec[0][j] = vec[0][j - 1] + 1

for i in range(1, len(s1) + 1):  
    vec[i][0] = vec[i - 1][0] + 1       
    for j in range(1, len(s2) + 1):
        if (s1[i - 1] == s2[j - 1]):
            vec[i][j] = vec[i - 1][j - 1]                 
        else: 
            vec[i][j] = min(vec[i - 1][j - 1] + 1, vec[i][j - 1] + 1, vec[i - 1][j] + 1)

print(vec[len(s1)][len(s2)])
#print(vec)