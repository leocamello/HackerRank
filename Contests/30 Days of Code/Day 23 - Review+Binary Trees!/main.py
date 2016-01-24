import sys


class Node:

    def __init__(self, data):
        self.right = self.left = None
        self.data = data


class Solution:

    def insert(self, root, data):
        if root is None:
            return Node(data)
        else:
            if data <= root.data:
                cur = self.insert(root.left, data)
                root.left = cur
            else:
                cur = self.insert(root.right, data)
                root.right = cur
        return root

    def levelOrder(self, root):
        # Base Case
        if root is None:
            return

        # Create an empty queue for level order traversal
        queue = []
        orderedData = list()

        # Enqueue Root and initialize height
        queue.append(root)

        while(len(queue) > 0):
            # Print front of queue and remove it from queue
            # print(queue[0].data)
            node = queue.pop(0)
            orderedData.append(node.data)

            # Enqueue left child
            if node.left is not None:
                queue.append(node.left)

            # Enqueue right child
            if node.right is not None:
                queue.append(node.right)

        print(*orderedData)

T = int(input())
myTree = Solution()
root = None
for i in range(T):
    data = int(input())
    root = myTree.insert(root, data)
myTree.levelOrder(root)
