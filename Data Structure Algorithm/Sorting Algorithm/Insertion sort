def insertion(arr):
    for i in range(1, len(arr)):
        target = i
        j = i - 1
        while j >= 0 and arr[j] > arr[i]:
            swap(arr, i, j)
            i -= 1
            j -= 1
    return arr

def swap(arr, a, b):
    t = arr[a]
    arr[a] = arr[b]
    arr[b] = t

print(insertion([11, 4, 5, 2, 2, 11, 13,3,2,1,8,3]))
