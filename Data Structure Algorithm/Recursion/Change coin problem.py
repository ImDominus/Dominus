## exchange the least coin, if 15, [1, 5, 10] -> return 2 (5, 10)
## Not just Greedy, because 17, [1, 3, 4, 5, 10] is return 3(3, 4, 10), not 4(1, 1, 5, 10).
## I use dynamic programming and recursion

def change_coin(n, arr, answer = None, d = {}, count = 0):
    if n in d:
        return d[n]
    if n == 0:
        return 0
    elif n != 0 and len(arr) == 0:
        return None
    else:
        for i, value in enumerate(arr):
            if n < arr[-1 - i]:
                continue
            else:
                c = arr[- 1 - i]
                count += n // c
                k = change_coin(n % c, arr[:-1], answer, d)
                if k is None:
                    count -= n // c
                    continue
                else:
                    count += k
                    if answer is None or answer >= count:
                        answer = count
                    count -= n // c + k
        d[n] = answer                                   ## memory my number
        return answer

print(change_coin(401, [5, 3, 100, 2, 9, 8, 45, 32]))   ## == 13
# Time complexity = O(n), memory complexity = O(n)
