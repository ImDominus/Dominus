class binary_tree():
    def __init__(self, root):
        self.key = root
        self.leftchild = None
        self.rightchild = None

    def insertleft(self, new):                      ## insertleft -> t is one level down tree
        if self.leftchild is None:                  ## if 1 - 2 tree, and insert 3:
            self.leftchild = binary_tree(new)       ## result -> 1 - 3 - 2
        else:
            t = binary_tree(new)
            t.leftchild = self.leftchild
            self.leftchild = t

    def insertright(self, new):
        if self.rightchild is None:
            self.rightchild = binary_tree(new)
        else:
            t = binary_tree(new)
            t.rightchild = self.rightchild
            self.rightchild = t

    def getleftchild(self):
        return self.leftchild

    def getrightchild(self):
        return self.rightchild

    def setrootval(self, obj):
        self.key = obj

    def getrootval(self):
        return self.key

r = binary_tree('a')
print(r.getrootval())
r.insertleft('b')
print(r.getleftchild().getrootval())
