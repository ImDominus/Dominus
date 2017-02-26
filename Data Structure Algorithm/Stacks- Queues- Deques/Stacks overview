class stacks:
    def __init__(self):
        self.data = []

    def push(self, item):
        self.data = self.data + [item]

    def pop(self):
        self.data = self.data[:-1]

    def peek(self):
        return self.data[-1]

    def isEmpty(self):
        if len(self.data) > 0:
            return False
        else:
            return True

    def size(self):
        return len(self.data)


k = stacks()

print(k.isEmpty())
print(k.data)
print(k.push(3))
print(k.data)
print(k.push(5))
print(k.pop())
print(k.peek())
