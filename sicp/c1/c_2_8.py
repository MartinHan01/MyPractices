def fib(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fib(n - 2) + fib(n - 1)


def count_f(f):
    def counted(*args):
        counted.call_count += 1
        result = f(*args)
        return result

    counted.call_count = 0
    return counted


def space_f(f):
    def spaced(*args):
        spaced.deep += 1
        spaced.max_deep = max(spaced.deep, spaced.max_deep)
        result = f(*args)
        spaced.deep -= 1
        return result
    spaced.deep = 0
    spaced.max_deep = 0
    return spaced


print(fib(10))

# fib = count_f(fib)
# print(fib(19))
# print(fib.call_count)

fib = space_f(fib)
print(fib(25))
print(fib.deep)
print(fib.max_deep)
