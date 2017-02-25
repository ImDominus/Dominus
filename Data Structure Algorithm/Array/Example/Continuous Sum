# find Largest continuous Sum
# if [-9,-3, 5, -2], anwser = 5
# [-1, -3, -5], anwser = -1
# [1,2,-1,-3,4,10,10,-10,-1]), anwser = 24


def continuous_sum(list):
    sum = None
    maximum = None
    for i in range(len(list)):                    #if list started under 0, delete started number
        if list[i] <= 0:
            if maximum is None:
                maximum = list[i]
            elif list[i] >= maximum:
                maximum = list[i]
        else:
            list = list[i:]
            maximum = None
            break
    if maximum is not None:
        return maximum
    for i in list:
        if sum == None and maximum == None:
            sum = i
            maximum = i
            continue
        sum += i
        if sum < 0:
            sum = 0
        elif sum >= maximum:
            maximum = sum
    return maximum

a = [-9,-3, 5, -2]
print(continuous_sum(a))


# time complexity = O(n)
