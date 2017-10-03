# Given a string of opening and closing parentheses, check whether it’s balanced. 
# We have 3 types of parentheses: round brackets: (), square brackets: [], and curly brackets: {}.
# Assume that the string doesn’t contain any other character than these, no spaces words or numbers.
# As a reminder, balanced parentheses require every opening parenthesis to be closed in the reverse order opened. 
# For example ‘([])’ is balanced but ‘([)]’ is not.


class stacks:                                   #To solve the prob, use the stacks (first in, last out)
    def __init__(self):
        stacks.data = []

    def add(self, k):
        stacks.data = stacks.data + [k]

    def remove(self):
        stacks.data = stacks.data[:-1]

    def top(self):
        return stacks.data[-1]

def find(c):
    a = stacks()
    for i in c:
        print(a.data)
        if i == "(" or i == "[" or i == "{":
            a.add(i)
        elif i == ")" or i == "]" or i == "}":
            if i == close(a.top()):
                a.remove()
            else:
                return False
    if len(a.data) == 0:
        return True
    else:
        return False

def close(c):
    if c == "(":
        return ")"
    elif c == "[":
        return "]"
    elif c == "{":
        return "}"

c = "[{{{(())}}}]((()))"

print(find(c))
