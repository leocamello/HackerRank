from itertools import groupby
from operator import itemgetter

people = list()

for i in range(int(input())):
    people.append(input().strip().split())

def directory(function):
    def input(people):
        people.sort(key=itemgetter(2))
        return [function(item[0], item[1], item[3]) for elt, items in groupby(people, itemgetter(2)) for item in items]
    return input

@directory
def greetings(first_name, last_name, sex):
    if sex == 'M':
        return "Mr." + " " + first_name + " " + last_name
    else:
        return "Ms." + " " + first_name + " " + last_name

print (('\n').join(greetings(people)))
