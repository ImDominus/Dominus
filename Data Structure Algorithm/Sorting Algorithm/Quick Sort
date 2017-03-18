def quick(arr, first = 0, last = None):
    if last is None:
        last = len(arr) - 1
    if first < last:
        splitpoint = partition(arr, first, last)
        quick(arr, first, splitpoint - 1)
        quick(arr, splitpoint + 1, last)
    return arr

def partition(arr, first, last):
    pivot = arr[first]
    left = first + 1
    right = last
    done = False
    while not done:
        while left <= right and arr[left] <= pivot:
            left = left + 1
        while arr[right] >= pivot and right >= left:
            right = right - 1
        if right < left:
            done = True
        else:
            swap(arr, left, right)
    swap(arr, first, right)
    return right

def swap(arr, a, b):
    temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp

print(quick([1,3,5,1,3,2,5,8,9,12,13,15,11,12]))

## Most effcient sorting algorithm human knows, but worst case time complexity -> O(n**2) average(nlogn)
