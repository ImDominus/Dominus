def bad_fibonnaci(n):
    if n == 1 or n == 2:
        return 1
    else:
        print(1)
        return bad_fibonnaci(n - 1) + bad_fibonnaci(n - 2)
## This is worst way to calculate fibonnaci -> Time complexity = O(2**n)
## if want calculate fibonnaci(n) -> cal fibo(n - 1), fibo(n - 2) -> cal 2 * fibo(n - 2) , fibo(n - 3)---- etc.

def memo_fibonnaci(n, c = {}):
    if n == 1 or n == 2:
        return 1
    elif n in c:
        return c[n]
    else:
        c[n] = memo_fibonnaci(n - 1, c) + memo_fibonnaci(n - 2, c)
        return c[n]
## if sacrifice O(n) memory, Time complexity will be O(n)
## Only calculate 1 times each n

def iter_fibonnaci(n):
    a1 = 1
    a2 = 1
    ak = 1
    for i in range(2, n):
        ak = a1 + a2
        a1 = a2
        a2 = ak
    return ak
## not recusion -> O(n)


def best_fibonnaci(n):
    return (1 / (5 ** (1 / 2))) * ((((1  + (5 ** (1 / 2))) / 2)) ** n - (((1 - (5 ** (1 / 2))) / 2)) ** n)
## Best case. only time complexity = O(1)
