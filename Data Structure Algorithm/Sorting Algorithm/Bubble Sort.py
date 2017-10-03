def bubble(arr):
    for n in range(len(arr) - 1, 0, -1):
        for k in range(n):
            if arr[k] > arr[k + 1]:
                swap(arr, k, k + 1)
    return arr

def swap(arr, a, b):
    t = arr[a]
    arr[a] = arr[b]
    arr[b] = t

print(bubble([3,2,1,8,3]))

##bad algorithm
