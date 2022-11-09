import fractions

numOfSymb = int(input())
s = input()
vecSymb = []
countSymb = []
for i in range(numOfSymb):
    vecSymb.append(chr(ord('a') + i))
    countSymb.append(0)


for i in range(len(s)):
    countSymb[vecSymb.index(s[i])]+=1


chanceSymb = []
chanceSymbEnd = []
chanceSymbEnd.append(fractions.Fraction(0, 1))
for i in range(len(countSymb)):
    chanceSymb.append(fractions.Fraction(countSymb[i], len(s)))
    chanceSymbEnd.append(chanceSymbEnd[i] + chanceSymb[i])

#print(chanceSymbEnd)

leftBound = 0
rightBound = 1
for i in range(len(s)):
    index1 = vecSymb.index(s[i])
    factor = rightBound - leftBound
    rightBound = chanceSymbEnd[index1 + 1] * factor + leftBound
    leftBound = chanceSymbEnd[index1] * factor + leftBound

#print(leftBound, rightBound)

x = fractions.Fraction(0, 1)
binX = ""
while (x < leftBound or x > rightBound):
    y = fractions.Fraction(1, 2**(len(binX) + 1))
    if (x + y > rightBound):
        binX += "0"
    else:
        binX += "1"
        x = x + y
if (binX == ""):binX = 0


print(numOfSymb)
for i in countSymb:
    print(i, end = " ")
print()
print(binX)