numbers = list()

for i in range(int(input())):
    number = input()
    ncount = len(number)
    numbers.append("+91 " + number[ncount - 10 : ncount - 5] + " " + number[ncount - 5 : ncount])

for number in sorted(numbers):
    print (number)
    
