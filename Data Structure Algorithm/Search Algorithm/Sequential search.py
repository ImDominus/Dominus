def sequential_search(k, list):
    for i, value in enumerate(list):
        if k == value:
            return i
    return False

list = [3, 5, 6, 1, 2, 10]
print(sequential_search(3, list))
print(sequential_search(13, list))

# Time complexity => O(n)
