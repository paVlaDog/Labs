st = input()

bal = []
b = 0
for i in range(len(st)):
    if(st[i] == '('):
        b += 1
        bal.append(b)
    if(st[i] == ')'):
        b -= 1
        bal.append(b)

dp = [[[0]*2 for i in range(len(st) + 1)] for j in range(len(st) + 1)]
dp[0][1][0] = 1
dp[0][1][1] = 1

for i in range(1, len(st)):
    for j in range(len(st)):
        for k in range(2):
            if (st[i] == '('):
                dp[i][j][k] = dp[i - 1][j][1]
                dp[i][j][k] %= 2012
                if (j > 0):
                    dp[i][j][k] += dp[i - 1][j - 1][0] 
                    dp[i][j][k] %= 2012
            else:
                if (j < len(st)):
                    dp[i][j][k] += dp[i - 1][j + 1][0]
                    dp[i][j][k] %= 2012
                if(bal[i] - j >= 0):
                    dp[i][j][k] += dp[i - 1][j][1]
                    dp[i][j][k] %= 2012
            
print((dp[len(st) - 1][0][1]+ dp[len(st) - 1][0][0]) % 2012)
