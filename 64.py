from math import *
import cpp_utils
from collections import OrderedDict

# a is equal to sqrt(N)
def conjugate_product(a, b):
    return a - b**2

def next_value(an, k, m, sqrtN):
    denom = conjugate_product(N, m)
    g = gcd(k, denom)
    k //= g
    denom //= g
    numer_part = k*m
    ai = int((sqrtN + numer_part) / denom)
    #print(f"sqrt({N}) + {numer_part} / {denom}")
    numer_part = ai*denom - numer_part
    k = denom
    m = numer_part
    an.append(ai)
    return (k, m)

odd_periods = 0
for N in range(1, 10000 + 1):
    if cpp_utils.is_square(N): continue
    def D():
        sqrtN = sqrt(N)
        a0 = int(sqrtN)
        an = []
        k = 1
        m = a0
        idx = 0
        detrms = {}
        period = 0
        idx = 0
        while True:
            k, m = next_value(an, k, m, sqrtN)
            if detrms.get((k, m)):
                period = idx
                return (period, an)
            detrms[(k, m)] = True
            idx += 1
    period, an = D()  
    if period & 1:
        odd_periods += 1  
    print(N, an, period)
print("TOTAL: ", odd_periods)

