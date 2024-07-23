from math import *

g = factorial(100)
g = str(g)
digits = [int(c) for c in g]
print(sum(digits))