from html.parser import HTMLParser

def print_tag_and_attrs(tag, attrs):
    print (tag)
    for attr in attrs:
        print ("->", attr[0], ">", attr[1])

class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print_tag_and_attrs(tag, attrs)

html = str()
for i in range(int(input())):
    html += input().rstrip() + '\n'

parser = MyHTMLParser()
parser.feed(html)
parser.close()
