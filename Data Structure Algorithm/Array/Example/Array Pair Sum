# To find unique pairs sum up to k
# So the input:pair_sum([1,3,2,2],4)
# would return 2 pairs:
# (1,3)
# (2,2)

def pair_sum(uniq, k):
    check_list = set()                 # set => s in x -> O(1), best way to reducing time complexity.
    answer = set()

    for i in uniq:
        m = k - i
        if m not in check_list:
            check_list.add(i)
        else:
            answer.add((min(i, m), max(i, m)))
    return answer

print(pair_sum([1,9,2,8,3,7,4,6,5,5,13,14,11,13,-1],10))
pair_sum(list(range(10000)), 4000)
print(pair_sum([1,2,3,1],3))


## Time Complexity = O(n)
