import re

postalcode = input()
validrange = re.search(r'^[1-9]\d{5}$', postalcode)
alternatingdigits = re.search(r'(\d)(\d)\1\2', postalcode)
print (validrange != None and alternatingdigits == None
