from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
    def handle_comment(self, data):
        comments = data.split('\n')
        if len(comments) == 1:
            print (">>> Single-line Comment")
        else:
            print (">>> Multi-line Comment")
        for comment in comments:
            if comment != "\n":
                print (comment)
    def handle_data(self, data):
        if data != "\n":
            print (">>> Data")
            print (data)

html = str()
for i in range(int(input())):
    html += input().rstrip() + '\n'

parser = MyHTMLParser()
parser.feed(html)
parser.close()
