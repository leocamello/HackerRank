numbers = list()

for i in range(int(input())):
    numbers.append(input())

def mobile(function):
    def input(numbers):
        return sorted([function(number) for number in numbers])
    return input

@mobile
def standardize(number):
    return "+91" + " " + number[-10:-5] + " " + number[-5:]

print (('\n').join(standardize(numbers)))
