
def trace1(fn):
    def wrap(x):
        print("fn = ", fn, "---", x)
        return fn(x)

    return wrap


@trace1
def square_fun(x):
    return x * x


print("-----------")
hello = square_fun(5)
print(hello)
print("-----------")
square_fun_f = trace1(square_fun)
print(square_fun_f(6))
print("-----------")
