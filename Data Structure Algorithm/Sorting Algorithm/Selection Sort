def selection(arr):
    for i in range(len(arr)):
        min = arr[i]
        target = i
        for j in range(i, len(arr)):
            if arr[j] < min:
                target = j
                min = arr[j]
        swap(arr, i, target)
    return arr

def swap(arr, a, b):
    t = arr[a]
    arr[a] = arr[b]
    arr[b] = t

print(selection([3,2,1,8,3]))
