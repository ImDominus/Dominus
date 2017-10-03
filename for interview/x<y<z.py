# Given 3 sorted arrays. Find(x, y, z)
# x, y, z is from each array, must x < y < z.
# len(each array) > 1

def serh(arr, k):
    start = 0
    end = len(arr) - 1
    mid = (start + end) // 2
    check_list = []
    while True:
        if mid == start == end and arr[mid] != k:
            if start == len(arr) - 1 and arr[start] < k:
                return len(arr) + 33
            elif start == 0 and arr[start] > k:
                return 0
            elif arr[start] > k and arr[start - 1] < k:
                return start
            elif arr[start] < k and arr[start + 1] > k:
                return start + 1
        elif arr[mid] < k:
            start = mid + 1
            mid = (start + end) // 2
        elif arr[mid] > k:
            end = mid
            mid = (start + end) // 2
        else:
            return mid + 1

def find_arrays(x, y, z):
    answer = []
    for i in range(len(x)):
        a = serh(y, x[i])
        for j in range(a, len(y)):
            b = serh(z, y[j])
            for k in range(b, len(z)):
                answer.append([x[i], y[j], z[k]])
    return answer

a = [1, 3, 5, 6, 8]
b = [2, 3, 6, 8, 11]
c = [-1, -1, -3, 33]

k = find_arrays(a, b, c)
for i in range(len(k)):
    print(k[i])


## Time Complexity => O(n^3(logn)^2)
