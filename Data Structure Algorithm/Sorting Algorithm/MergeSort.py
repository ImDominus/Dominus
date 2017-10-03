def mergere(arr):
    if len(arr) == 1 or len(arr) == 0:
        return arr
    else:
        A = mergere(arr[:len(arr) // 2])
        B = mergere(arr[len(arr) // 2:])
        p = merging(A, B)
        return p

def merging(arrA, arrB):
    i = 0
    j = 0
    arr = []
    while True:
        try:
            if arrA[i] <= arrB[j]:
                arr.append(arrA[i])
                i += 1
            else:
                arr.append(arrB[j])
                j += 1
        except:
            if i == len(arrA):
                arr = arr + arrB[j:]
            else:
                arr = arr + arrA[i:]
            break
    return arr

print(mergere([1,3,5,1,3,2,5,8,9,12,13,15,11,12]))

# Time complexity = O(nlogn). Very very important sorting algorithm.
