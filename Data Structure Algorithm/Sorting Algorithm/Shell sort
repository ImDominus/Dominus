def shell(arr):
    k = len(arr) // 2
    while k > 0:
        for i in range(k):
            insertion(arr, i, k)
        k = k // 2
    return arr

def insertion(arr, start, gap):
    for i in range(start + gap, len(arr), gap):
        currentvalue = arr[i]
        position = i
        while position >= gap and arr[position - gap] > currentvalue:
            arr[position] = arr[position - gap]
            position = position - gap
        arr[position] = currentvalue
    return arr


print(shell([1,3,5,1,3,2,5,8,9,12,13,15,11,12]))

#Time complexity is O(n**(3/2)) better than insertion. However, slower than O(nlogn)
