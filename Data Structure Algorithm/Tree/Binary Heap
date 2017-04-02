class minheap(object):
    def __init__(self):
        self.heap = [0]

    def insert(self, number):
        self.heap.append(number)
        k = len(self.heap) - 1
        while k >= 2:
            if self.heap[k] < self.heap[k // 2]:
                self.swap(k, k // 2)
                k = k // 2
            else:
                break

    def delete(self):
        self.swap(1, -1)
        p = self.heap.pop()
        q = len(self.heap) - 1
        k = 1
        while True:
            if 2 * k < q and 2 * k + 1 <= q:
                if self.heap[k] > self.heap[2 * k] or self.heap[k] > self.heap[2 * k + 1]:
                    if self.heap[2 * k] > self.heap[2 * k + 1]:
                        self.swap(2 * k + 1, k)
                        k = 2 * k + 1
                    else:
                        self.swap(2 * k, k)
                        k = 2 * k
                else:
                    break
            elif 2 * k == q:
                if self.heap[k] > self.heap[2 * k]:
                    self.swap(2 * k, k)
                    break
                else:
                    break
            else:
                break
        return p

    def swap(self, a, b):
        temp = self.heap[a]
        self.heap[a] = self.heap[b]
        self.heap[b] = temp

a = minheap()
a.insert(1)
a.insert(3)
a.insert(4)
a.insert(6)
a.insert(-1)
a.insert(-2)
a.insert(-9)
a.insert(3)
a.insert(10)
print(a.heap)
a.delete()
print(a.heap)
a.delete()
print(a.heap)
a.delete()
print(a.heap)
a.delete()
print(a.heap)
a.delete()
print(a.heap)
a.delete()
print(a.heap)
a.delete()
print(a.heap)
a.delete()
print(a.heap)
