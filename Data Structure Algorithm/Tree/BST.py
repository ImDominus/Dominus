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

def isbinarytree(root):
    if root.leftchild is not None:
        if root.leftchild.key > root.key:
            return False
        else:
            isbinarytree(root.leftchild)
    if root.rightchild is not None:
        if root.rightchild.key < root.key:
            return False
        else:
            isbinarytree(root.rightchild)
    return True

def treelevelorder(current):
    que = []
    que.append(current)
    count1 = 1
    count2 = 0
    while len(que) != 0:
        current = que.pop(0)
        count1 -= 1
        print(current.key, end = " ")
        if current.leftchild:
            que.append(current.leftchild)
            count2 += 1
        if current.rightchild:
            que.append(current.rightchild)
            count2 += 1
        if count1 == 0:
            print('\n')
            count1, count2 = count2, 0


a = binary_tree(5)
a.insertleft(3)
a.leftchild.insertright(4)
a.leftchild.insertleft(2)
a.insertright(6)
a.insertright(7)
a.rightchild.insertleft(8)
a.leftchild.leftchild.insertright(9)
treelevelorder(a)
