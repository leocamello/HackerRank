import re

print (re.sub(r"\b[A-Za-z]+(['-A-Za-z0-9]+)?\b", lambda mo: mo.group(0)[0].upper() + mo.group(0)[1:].lower(), input()))
