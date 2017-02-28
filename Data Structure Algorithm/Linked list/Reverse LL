class node:

    def __init__(self, value):
        self.value = value
        self.nextnode = None

    def connect(self, another):
        self.nextnode = another

def reverse(head):
    current = head
    previous = None
    future = None

    while current != None:
        future = current.nextnode
        current.nextnode = previous
        previous = current
        current = future
    return



a = node(1)
b = node(2)
c = node(3)
d = node(4)

a.connect(b)
b.connect(c)
c.connect(d)

print(reverse(a))
print(b.nextnode.value)
print(c.nextnode.value)
print(d.nextnode.value)
