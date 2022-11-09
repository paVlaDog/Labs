import fractions

numOfSymb = int(input())

vecSymb = []
countSymb = []
countSymb = input().split()
sum = 0
for i in range(numOfSymb):
    vecSymb.append(chr(ord('a') + i))
    countSymb[i] = int(countSymb[i])
    sum += countSymb[i]

binX = input()
num = fractions.Fraction(0, 1)
for i in range(len(binX)):
    if (binX[i] == '1'):
        num += fractions.Fraction(1, 2**(i + 1))

#print(num)
#print(countSymb, binX)

chanceSymb = []
chanceSymbEnd = []
chanceSymbEnd.append(fractions.Fraction(0, 1))
for i in range(len(countSymb)):
    chanceSymb.append(fractions.Fraction(countSymb[i], sum))
    chanceSymbEnd.append(chanceSymbEnd[i] + chanceSymb[i])

#print(chanceSymbEnd)

leftBound = fractions.Fraction(0, 1)
rightBound = fractions.Fraction(1, 1)
for i in range(sum):
    factor = rightBound - leftBound
    for j in range(numOfSymb):
        newLeftBound = chanceSymbEnd[j] * factor + leftBound
        newRightBound = chanceSymbEnd[j + 1] * factor + leftBound
        if (num >= newLeftBound and num < newRightBound and chanceSymbEnd[j] != chanceSymbEnd[j + 1]):
            print(vecSymb[j], end = "")
            leftBound = newLeftBound
            rightBound = newRightBound


