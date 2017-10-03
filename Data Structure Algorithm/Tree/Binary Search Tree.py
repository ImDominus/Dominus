class node(object):
    def __init__(self, key, value, parent = None, leftchild = None, rightchild = None):
        self.key = key
        self.value = value
        self.parent = parent
        self.leftchild = leftchild
        self.rightchild = rightchild

class bst(object):
    def __init__(self):
        self.root = None
        self.size = 0

    def insert(self, key, value):
        self.size += 1
        if self.root is None:
            newnode = node(key, value)
            self.root = newnode
        else:
            self.insertnode(self.root, key, value)

    def insertnode(self, nowkey, key, value):
        if nowkey.key >= key:
            if nowkey.leftchild is None:
                newnode = node(key, value, nowkey)
                nowkey.leftchild = newnode
            else:
                self.insertnode(nowkey.leftchild, key, value)
        else:
            if nowkey.rightchild is None:
                newnode = node(key, value, nowkey)
                nowkey.rightchild = newnode
            else:
                self.insertnode(nowkey.rightchild, key, value)

    def delete(self, key):
        target = self.find(key)
        if target is None:
            return
        else:
            self.size -= 1
            if target.leftchild is None and target.rightchild is None:
                if target.parent is None:
                    self.root = None
                elif target.parent.leftchild == target:
                    target.parent.leftchild = None
                else:
                    target.parent.rightchild = None
            elif target.leftchild is None or target.rightchild is None:
                if target.parent is None:
                    if target.leftchild is None:
                        self.root = target.rightchild
                        target.rightchild.parent = None
                    else:
                        self.root = target.leftchild
                        target.leftchild.parent = None
                elif target.parent.leftchild == target:
                    if target.leftchild is None:
                        target.parent.leftchild = target.rightchild
                        target.rightchild.parent = target.parent
                    else:
                        target.parent.leftchild = target.leftchild
                        target.leftchild.parent = target.parent
                else:
                    if target.leftchild is None:
                        target.parent.rightchild = target.rightchild
                        target.rightchild.parent = target.parent
                    else:
                        target.parent.rightchild = target.leftchild
                        target.leftchild.parent = target.parent
            else:
                newing = self.findmin(target.rightchild)
                if target.parent is not None:
                    if target.rightchild == newing:
                        if target.parent.leftchild == target:
                            target.parent.leftchild = newing
                            newing.leftchild = target.leftchild
                        else:
                            target.parent.rightchild = newing
                            newing.leftchild = target.leftchild
                        newing.parent = target.parent
                    else:
                        newing.parent.leftchild = newing.rightchild
                        try:
                            newing.rightchild.parent = target.parent
                        except:
                            pass
                        newing.parent = target.parent
                        newing.leftchild = target.leftchild
                        newing.rightchild = target.rightchild
                        if target.parent.leftchild == target:
                            target.parent.leftchild = newing
                        else:
                            target.parent.rightchild = newing
                else:
                    if target.rightchild == newing:
                        newing.parent = target.parent
                        self.root = newing
                    else:
                        newing.parent.leftchild = newing.rightchild
                        try:
                            newing.rightchild.parent = target.parent
                        except:
                            pass
                        newing.parent = target.parent
                        newing.leftchild = target.leftchild
                        newing.rightchild = target.rightchild
                        self.root = newing

    def find(self, key, now = None):
        if now is None:
            now = self.root
        if now.key > key:
            if now.leftchild is None:
                return None
            else:
                return self.find(key, now.leftchild)
        elif now.key < key:
            if now.rightchild is None:
                return None
            else:
                return self.find(key, now.rightchild)
        else:
            return now

    def findmin(self, now = None):
        if now.leftchild is None:
            return now
        else:
            return self.findmin(now.leftchild)
