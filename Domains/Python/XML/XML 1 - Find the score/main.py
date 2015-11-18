import xml.etree.ElementTree as etree

def score(node):
    if len(node) == 0:
        return len(node.attrib)
    else:
        sum = len(node.attrib)
        for child in node:
            sum += score(child)
        return sum

xml = str()

for _ in range(int(input())):
    xml += input().strip()

tree = etree.ElementTree(etree.fromstring(xml))

print (score(tree.getroot()))
