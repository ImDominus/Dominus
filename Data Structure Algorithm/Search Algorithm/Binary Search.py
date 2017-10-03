# powerful search algorithm when list is sorted.
def binary_search(k, list, start = None, end = None):
    if start is None and end is None:
        start, end = 0, len(list) - 1
    if start == end and k != list[start]:
        return False
    else:
        mid = (start + end) // 2
        if list[mid] == k:
            return mid
        elif list[mid] > k:
            return binary_search(k, list, start, mid)
        else:
            return binary_search(k, list, mid + 1, end)

list = [3, 5, 6, 1, 2, 10, 53]
list.sort()
print(binary_search(10, list))
print(binary_search(13, list))

# time complexity = O(logn)
