import re

for _ in range(int(input())):
    isvalid = "Invalid"
    creditcardnumber = input()
    validsingle = re.search(r'^([0-9]{16})$', creditcardnumber)
    validgroup = re.search(r'^([0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4})$', creditcardnumber)
    if validsingle != None or validgroup != None:
        numbers = ("").join(creditcardnumber.split('-'))
        if numbers[0] == '4' or numbers[0] == '5' or numbers[0] == '6':
            if re.search(r'([0-9])\1{3}', numbers) == None:
                isvalid = "Valid"
    print (isvalid)
