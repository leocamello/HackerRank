from abc import ABCMeta, abstractmethod
class Book(object, metaclass=ABCMeta):
    def __init__(self,title,author):
        self.title=title
        self.author=author
    @abstractmethod
    def display(): pass
class MyBook(Book):
    def __init__(self, title, author, price):
        super().__init__(title, author)
        self.price = price
    def display(self):
        print(("Title: {0}").format(self.title))
        print(("Author: {0}").format(self.author))
        print(("Price: {0}").format(self.price))
