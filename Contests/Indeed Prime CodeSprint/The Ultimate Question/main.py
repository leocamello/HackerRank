ops = ['+', '*']
a,b,c = input().strip().split()

isTheUltimateQuestion = False

for possibility in (a+op1+b+op2+c for op1 in ops for op2 in ops):
    result = eval(possibility)
    if result == 42:
        isTheUltimateQuestion = True
        print (possibility)

if not isTheUltimateQuestion:
    print ("This is not the ultimate question")
