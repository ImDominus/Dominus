class binary_tree():
    def __init__(self, root):
        self.key = root
        self.leftchild = None
        self.rightchild = None

    def insertleft(self, new):                      ## insertleft -> t is one level down tree
        if self.leftchild is None:                 ## if 1 - 2 tree, and insert 3:
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

def preorder(root):                                         # find root first recursively.
    if root is not None:                                    # left first, right last.
        print (root.getrootval())
        preorder(root.getleftchild())
        preorder(root.getrightchild())

def inorder(root):                                          # find root after search left subtree recursively.
    if root is not None:
        inorder(root.getleftchild())
        print(root.getrootval())
        inorder(root.getrightchild())

def postorder(root):                                        # find root after search right subtree recursively.
    if root is not None:
        postorder(root.getleftchild())
        postorder(root.getrightchild())
        print(root.getrootval())

r = binary_tree('a')                                          #this tree is
r.insertleft('b')                                             #                           a
r.insertleft('c')                                             #                       c       1
r.getleftchild().insertright('d')                             #                     b   d   2   3
r.insertright(1)
r.getrightchild().insertleft(2)
r.getrightchild().insertright(3)

preorder(r)
inorder(r)
postorder(r)
