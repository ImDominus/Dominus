class Vertex:
    def __init__(self, key):
        self.id = key
        self.connectedto = {}

    def addneighbor(self, nbr, weight = 0):
        self.connectedto[nbr] = weight

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

g = graph()
for i in range(6):
    g.addvertex(i)
g.addedge(0,1,2)

for i in g:
    print(i)
