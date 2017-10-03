class queue:
    def __init__(self):
        queue.data = []

    def enqueue(self, k):
        queue.data = [k] + queue.data

    def dequeue(self):
        queue.data = queue.data[:-1]

    def isEmpty(self):
        return len(queue.data) == 0

    def size(self):
        return len(queue.data)

a = queue()
print(a.data)
a.enqueue(3)
a.enqueue(4)
a.enqueue(5)
a.enqueue(36)
print(a.data)
a.dequeue()
print(a.data)
print(a.isEmpty())
print(a.size())
