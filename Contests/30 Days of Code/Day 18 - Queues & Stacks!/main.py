from collections import deque

class Palindrome:
    def __init__(self):
        self.queue = deque()
        self.stack = deque()
    def enqueueCharacter(self, ch):
        self.queue.append(ch)
    def dequeueCharacter(self):
        return self.queue.popleft()
    def pushCharacter(self, ch):
        self.stack.append(ch)
    def popCharacter(self):
        return self.stack.pop()

# read the string s
W=input()
#Create the Palindrome class object
p=Palindrome()

l=len(W)
# push all the characters of string s to stack
for i in range(l):
    p.pushCharacter(W[i])
#enqueue all the characters of string s to queue
for i in range(l):
    p.enqueueCharacter(W[i])
f=True
'''
pop the top character from stack
dequeue the first character from queue
compare both the characters
'''
for i in range(l):
    if p.popCharacter()!=p.dequeueCharacter():
        f=False
        break
#finally print whether string s is palindrome or not.
if f:
    print ("The word, "+W+", is a palindrome.")
else:
    print ("The word, "+W+", is not a palindrome.")
