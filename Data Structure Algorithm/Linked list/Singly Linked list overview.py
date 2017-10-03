# We have an ordered list of items as individual Nodes that have pointers to other Nodes.

class node:

    def __init__(self, value):
        self.value = value
        self.node = None

    def connect(self, another):
        self.node = another.value


a = node(1)
b = node(2)
c = node(3)

a.connect(b)
b.connect(c)

print(a.value, a.node)
print(b.value, b.node)
print(c.value, c.node)

# In a Linked List the first node is called the head and the last node is called the tail. 

# Pros
# Linked Lists have constant-time insertions and deletions in any position, 
# in comparison, arrays require O(n) time to do the same thing.


# Linked lists can continue to expand without having to specify their size ahead of time


# cons
# To access an element in a linked list, you need to take O(k) time to go from the head of the list to the kth element.
# In contrast, arrays have constant time operations to access elements in an array.
