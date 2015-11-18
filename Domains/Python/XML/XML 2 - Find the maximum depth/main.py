import xml.etree.ElementTree as etree

def maximumdepth(node, depth):
    if len(node) == 0:
        return depth
    else:
        maximum = depth
        for child in node:
            maximum = max(maximumdepth(child, depth + 1), maximum)
        return maximum

xml = str()

for _ in range(int(input())):
    xml += input().strip()

tree = etree.ElementTree(etree.fromstring(xml))

print (maximumdepth(tree.getroot(), 0))
