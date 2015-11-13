def isExtensionValid(extension):
    if len(extension) == 0:
        return False
    if len(extension) > 3:
        return False
    return True

def isWebsiteValid(website):
    websiteValid = set('abcdefghijklmnopqrstuvwxyz0123456789')
    if len(website) == 0:
        return False
    if len(set(website).difference(websiteValid)) > 0:
        return False
    return True

def isUsernameValid(username):
    usernameValid = set('_-abcdefghijklmnopqrstuvwxyz0123456789')
    if len(username) == 0:
        return False
    if len(set(username).difference(usernameValid)) > 0:
        return False
    return True

def isEmailValid(email):
    res = email.split('@')
    if len(res) != 2:
        return False
    if isUsernameValid(res[0]) != True:
        return False
    res = res[1].split('.')
    if len(res) != 2:
        return False
    if isWebsiteValid(res[0]) != True:
        return False
    if isExtensionValid(res[1]) != True:
        return False
    return True

N = int(input())

emails = list()
for i in range(0, N):
    emails.append(input())

emails.sort()

print (list(filter(lambda email : isEmailValid(email), emails)))
