from collections import deque


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Node2:
    def __init__(self, data):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    def enqueue(self, data):
        new_node = Node2(data)

        if self.rear is None:
            self.front = self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node

    def dequeue(self):
        if self.front is None:
            print("Queue is Empty!")
        else:
            temp = self.front
            self.front = self.front.next
            if self.front is None:
                self.rear = None
            del temp

    def peek(self):
        if not self.is_empty():
            return self.front.data

        print("Queue is Empty!")
        return None

    def is_empty(self):
        return self.front is None

    def display(self):
        temp = self.front
        if temp is None:
            print("Empty")
            return

        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next


class BinaryTree:
    def __init__(self):
        self.root = None

    def create_tree(self):
        x = int(input("Enter data: "))

        if x == -1:
            return None

        new_node = Node(x)
        print(f"Enter left of {x}")
        new_node.left = self.create_tree()
        print(f"Enter right of {x}")
        new_node.right = self.create_tree()

        return new_node

    def build_from_level_order_traversal(self):
        data = int(input("Enter data: "))

        self.root = Node(data)
        q = deque()
        q.append(self.root)

        while q:
            temp = q.popleft()

            print(f"Enter left of {temp.data}")
            left = int(input())
            if left != -1:
                temp.left = Node(left)
                q.append(temp.left)

            print(f"Enter right of {temp.data}")
            right = int(input())
            if right != -1:
                temp.right = Node(right)
                q.append(temp.right)

    def level_order_traversal(self):
        q = Queue()
        q.enqueue(self.root)
        q.enqueue(None)

        while not q.is_empty():
            temp = q.peek()
            q.dequeue()

            if temp is None:  # using None as a separator
                print()
                if not q.is_empty():  # if there's another level
                    q.enqueue(None)
            else:
                print(temp.data, end=" ")

                if temp.left is not None:
                    q.enqueue(temp.left)

                if temp.right is not None:
                    q.enqueue(temp.right)

    def pre_order(self, root):
        if root is None:
            return

        print(root.data, end=" ")
        self.pre_order(root.left)
        self.pre_order(root.right)

    def post_order(self, root):
        if root is None:
            return

        self.post_order(root.left)
        self.post_order(root.right)
        print(root.data, end=" ")

    def in_order(self, root):
        if root is None:
            return

        self.in_order(root.left)
        print(root.data, end=" ")
        self.in_order(root.right)

    def build_tree_from_preorder_and_inorder(
        self, lb, ub, inorder, preorder, preorder_len
    ):
        if lb > ub:
            return None

        if lb == ub:
            new_node = Node(inorder[lb])
            return new_node

        min_index = 100
        index = 0

        for i in range(lb, ub + 1):
            for j in range(preorder_len + 1):
                if inorder[i] == preorder[j]:
                    if j < min_index:
                        min_index = j
                        index = i
                    break

        new_node = Node(inorder[index])

        new_node.left = self.build_tree_from_preorder_and_inorder(
            lb, index - 1, inorder, preorder, preorder_len
        )
        new_node.right = self.build_tree_from_preorder_and_inorder(
            index + 1, ub, inorder, preorder, preorder_len
        )

        return new_node

    def build_tree_from_postorder_and_inorder(
        self, lb, ub, inorder, postorder, postorder_len
    ):
        min_index = -1
        index = 0

        if lb > ub:
            return None

        if lb == ub:
            print(" here")
            new_node = Node(inorder[lb])
            return new_node

        for i in range(lb, ub + 1):
            for j in range(postorder_len + 1):
                if inorder[i] == postorder[j]:
                    if j > min_index:
                        min_index = j
                        index = i
                    break

        print(inorder[index])

        new_node = Node(inorder[index])

        new_node.left = self.build_tree_from_postorder_and_inorder(
            lb, index - 1, inorder, postorder, postorder_len
        )
        new_node.right = self.build_tree_from_postorder_and_inorder(
            index + 1, ub, inorder, postorder, postorder_len
        )

        return new_node

    def insert(self, root, val):
        if root is None:
            root = Node(val)
        else:
            q = deque()
            q.append(root)

            while q:
                temp = q.popleft()

                if temp.left is None:
                    temp.left = Node(val)
                    break
                else:
                    q.append(temp.left)

                if temp.right is None:
                    temp.right = Node(val)
                    break
                else:
                    q.append(temp.right)

        return root

    def delete(self, root, val):
        if root is None:
            return None

        if root.data == val:
            return self.delete_node(root)

        root.left = self.delete(root.left, val)
        root.right = self.delete(root.right, val)

        return root

    def delete_node(self, root):
        if root.left is None and root.right is None:
            del root
            return None
        elif root.left is not None and root.right is None:
            temp = root.left
            del root
            return temp
        elif root.left is None and root.right is not None:
            temp = root.right
            del root
            return temp
        else:
            # This code is for deleting a node by swapping nodes
            prep = root
            pre = root.left

            while pre.right is not None:
                prep = pre
                pre = pre.right

            if prep != root:
                prep.right = pre.left
            else:
                prep.left = pre.right

            pre.right = root.right
            pre.left = root.left

            del root
            return pre

    def search(self, val):
        if self.root is None:
            print("Tree is empty!")
            return None

        q = deque()
        q.append(self.root)

        while q:
            temp = q.popleft()

            if temp.data == val:
                return temp

            if temp.left is not None:
                q.append(temp.left)

            if temp.right is not None:
                q.append(temp.right)

        return None

    def max(self, root):
        if root.right is None:
            return root

        return self.max(root.right)

    def find_height(self, root):
        if root is None:
            return 0

        left_height = self.find_height(root.left)
        right_height = self.find_height(root.right)

        if left_height > right_height:
            return left_height + 1
        else:
            return right_height + 1

    def get_size(self, root):
        if root is None:
            return 0

        left_no_of_nodes = self.get_size(root.left)
        right_no_of_nodes = self.get_size(root.right)

        return left_no_of_nodes + right_no_of_nodes + 1


def main():
    b = BinaryTree()

    # Example 1: Building from preorder and inorder
    # inorder = [8, 4, 10, 9, 11, 2, 5, 1, 6, 3, 7]
    # preorder = [1, 2, 4, 8, 9, 10, 11, 5, 3, 6, 7]
    # b.root = b.build_tree_from_preorder_and_inorder(0, 10, inorder, preorder, 10)
    # b.level_order_traversal()

    # Example 2: Building from postorder and inorder
    inorder = [9, 5, 1, 7, 2, 12, 8, 4, 3, 11]
    postorder = [9, 1, 2, 12, 7, 5, 3, 11, 4, 8]
    b.root = b.build_tree_from_postorder_and_inorder(0, 9, inorder, postorder, 9)
    b.level_order_traversal()


if __name__ == "__main__":
    main()
