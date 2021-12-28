def divisors(n):
    return [1] + [x for x in range(2, n) if n % x == 0]


print(divisors(4))
print(divisors(12))


def apply_to_all(map_fn, s):
    return [map_fn(x) for x in s]

def my_map_fn(val: int):
    return val * 2

arr = [1, 2, 3, 4, 5]
print(apply_to_all(my_map_fn, arr))


s = """The Zen of Python
claims, Readability counts.
Read more: import this."""

print(s)

from unicodedata import lookup
suits = ['heart', 'diamond', 'spade', 'club']
print([lookup('WHITE ' + s.upper() + ' SUIT') for s in suits])



def make_withdraw(blance):
    def withdraw(amount):
        nonlocal blance
        if amount > blance:
            return 'Insufficient funds'
        blance = blance - amount
        return blance
    return withdraw

withdraw_ = make_withdraw(100)
print(withdraw_(25))
print(withdraw_(25))
print(withdraw_(70))
print(withdraw_(15))