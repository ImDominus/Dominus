class deque:
    def __init__(self):
        deque.data = []

    def addfront(self, k):
        deque.data = [k] + deque.data

    def addrear(self, k):
        deque.data = deque.data + [k]

    def removefront(self):
        deque.data = deque.data[1:]

    def removerear(self):
        deque.data = deque.data[:-1]

    def isEmpty(self):
        return len(deque.data) == 0

    def size(self):
        return len(deque.data)

a = deque()
print(a.data)
a.addfront(3)
a.addrear(4)
a.addfront(5)
a.addrear(36)
print(a.data)
a.removefront()
print(a.data)
a.removerear()
print(a.data)
print(a.isEmpty())
print(a.size())
