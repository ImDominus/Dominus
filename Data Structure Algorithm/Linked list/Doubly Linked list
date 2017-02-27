class node:

    def __init__(self, value):
        self.value = value
        self.prevnode = None
        self.nextnode = None

    def connect(self, another):
        self.nextnode = another.value
        another.prevnode = self.value


a = node(1)
b = node(2)
c = node(3)

a.connect(b)
b.connect(c)

print(a.value, a.nextnode, a.prevnode)
print(b.value, b.nextnode, b.prevnode)
print(c.value, c.nextnode, c.prevnode)
