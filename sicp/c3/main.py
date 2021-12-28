from scheme_reader import *


lines = ['(+ 1', '   (* 2.3 45))']
# expression = scheme_read(Buffer(tokenize_lines(lines)))
# print(repr(expression))

from scalc import *
read_eval_print_loop()

# scheme_read(['(+ 1 2)'])

# Pair('+', Pair(1, Pair(Pair('*', Pair(2.3, Pair(45, nil))), nil)))
# print(expression)
