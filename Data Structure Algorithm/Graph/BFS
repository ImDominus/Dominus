from collections import deque

class Vertex:
    def __init__(self, key):
        self.id = key
        self.connectedto = {}

    def addneighbor(self, nbr, weight = 0):
        self.connectedto[nbr] = weight
        #self.vertlist[fr].addneighbor(self.vertlist[to], weight)

    def getconnections(self):
        return self.connectedto.keys()

    def getid(self):
        return self.id

    def getweight(self, nbr):
        return self.connectedto[nbr]

    def __str__(self):
        return str(self.id) + ' -> ' + str([x.id for x in self.connectedto])

class graph:
    def __init__(self):
        self.vertlist = {}
        self.verticesnum = 0

    def addvertex(self, key):
        self.verticesnum += 1
        new = Vertex(key)
        self.vertlist[key] = new
        return new

    def getvertex(self, key):
        if key in self.vertlist:
            return self.vertlist[key]
        else:
            return None

    def addedge(self, fr, to, weight = 0):
        if fr not in self.vertlist:
            nv = self.addvertex(fr)
        if to not in self.vertlist:
            nv = self.addvertex(to)
        self.vertlist[fr].addneighbor(self.vertlist[to], weight)

    def getvertices(self):
        return self.vertlist.keys()

    def __iter__(self):
        return iter(self.vertlist.values())

def bfs(graphlist, fr, to):
    p = deque()
    k = str(fr)
    p.append((graphlist.vertlist[fr], k))
    while len(p) != 0:
        c, k = p.popleft()
        for i in c.connectedto.keys():
            if i.id == to:
                return k + ' -> ' + str(i.id)
            p.append((graphlist.vertlist[i.id], k + ' -> ' + str(i.id)))
    return 'Impossible'

g = graph()
for i in range(6):
    g.addvertex(i)
g.addedge(0,1,2)
g.addedge(1,2,2)
g.addedge(2,3,0)
g.addedge(3,5,1)
g.addedge(3,4,1)
g.addedge(5,4,1)
print(bfs(g, 0, 4))
