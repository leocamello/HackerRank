from html.parser import HTMLParser

def print_attrs(attrs):
    for attr in attrs:
        print ("->", attr[0], ">", attr[1])

class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print ("Start :", tag)
        print_attrs(attrs)
    def handle_endtag(self, tag):
        print ("End   :", tag)
    def handle_startendtag(self, tag, attrs):
        print ("Empty :", tag)
        print_attrs(attrs)

html = str()
for i in range(int(input())):
    html += input().rstrip() + '\n'

parser = MyHTMLParser()
parser.feed(html)
parser.close()
