#!/usr/bin/env python3


class Node:

    def __init__(self, data):
        self.right = self.left = None
        self.data = data


class Solution:

    def insert(self, root, data):
        if root is None:
            return Node(data)
        else:
            cur = Node(data)
            if data <= root.data:
                cur = self.insert(root.left, data)
                root.left = cur
            else:
                cur = self.insert(root.right, data)
                root.right = cur
        return root

    def getHeight(self, root):
        height = 1
        if root.right is not None and root.left is not None:
            height += max(self.getHeight(root.left),
                          self.getHeight(root.right))
        elif root.right is not None:
            height += self.getHeight(root.right)
        elif root.left is not None:
            height += self.getHeight(root.left)
        return height

T = int(input())
myTree = Solution()
root = None
for i in range(T):
    data = int(input())
    root = myTree.insert(root, data)
height = myTree.getHeight(root)
print(height)
