def anagram(s1, s2):
    l_s1 = []
    l_s2 = []
    for i in range(len(s1)):
        if s1[i] == " ":
            continue
        else:
            l_s1.append(s1[i].upper())
    for i in range(len(s2)):
        if s2[i] == " ":
            continue
        else:
            l_s2.append(s2[i].upper())   # delete space
    l_s1.sort()
    l_s2.sort()
    if len(l_s1) != len(l_s2):
        return False
    else:
        for i in range(len(l_s1)):      # Compare, if same order, it is anagram
            if l_s1[i] != l_s2[i]:
                return False
    return True



print(anagram('dog','god'))
print(anagram('clint eastwood','old west action'))
print(anagram('aa','bb'))

##Time complexity : O(nlogn)
