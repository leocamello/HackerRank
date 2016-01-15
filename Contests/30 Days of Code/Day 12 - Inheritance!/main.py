class Student:
    def __init__(self,firstName,lastName,phone):
        self.firstName=firstName
        self.lastName=lastName
        self.phone=phone
    def display(self):
        print ("First Name:",self.firstName)
        print ("Last Name:",self.lastName)
        print ("Phone:",self.phone)
class Grade(Student):
    def __init__(self, firstName, lastName, phone, score):
        super().__init__(firstName, lastName, phone)
        self.score = score
    def calculate(self):
        if self.score < 40:
            return 'D'
        elif self.score < 60:
            return 'B'
        elif self.score < 75:
            return 'A'
        elif self.score < 90:
            return 'E'
        else:
            return 'O'

firstName=input().strip()
lastName=input().strip()
phone=int(input())
score=int(input())
stu=Grade(firstName,lastName,phone,score)
stu.display()
print ("Grade:",stu.calculate())
