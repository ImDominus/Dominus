def anagram(s1, s2):
    s1 = s1.replace(" ", "").upper()
    s2 = s2.replace(" ", "").upper()
    if len(s1) != len(s2):
        return False
    else:
        dic1 = {}
        for i in s1:
            if i in dic1:
                dic1[i] += 1
            else:
                dic1[i] = 1
        for i in s2:
            if i in dic1:
                dic1[i] -= 1
            else:
                return False
        for k in dic1:
            if dic1[k] != 0:
                return False
    return True



print(anagram('dog','god'))
print(anagram('clint eastwood','old west action'))
print(anagram('aa','bb'))

## time complexity: O(n)
