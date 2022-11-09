import os
os.system("g++ -o gen.exe gen.cpp")
os.system("g++ -o correct.exe correct.cpp")
os.system("g++ -o stupid.exe stupid.cpp")
test = 1
ans = 0
while ans != 1:
    print(test)
    test += 1
    os.system("gen.exe > input.txt")
    os.system("correct.exe < input.txt > correct.txt")
    os.system("stupid.exe < input.txt > stupid.txt")
    ans = os.system("fc correct.txt stupid.txt")