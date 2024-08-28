from math import *
import cpp_utils

largest = 0

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

def convergent(an, stop):
    numer = 1
    denom = an[stop]
    for a1 in reversed(an[:stop]):
        a_denom = denom
        a_numer = a1 * a_denom
        numer = numer + a_numer

        tmp = denom
        denom = numer
        numer = tmp
    return (denom, numer)

for N in range(1, 1000 + 1):
    if cpp_utils.is_square(N): continue
    def D():
        sqrtN = sqrt(N)
        a0 = int(sqrtN)
        an = [a0]
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
    an = an[:-1]
    if (len(an[1:]) & 1):
        an = an + an[1:]
    print(N, an, period)
    h, k = convergent(an, len(an)-2)
    print(f"D={N}, x={h}, y={k}")
    if h > largest:
        largest = h
        largest_d = N
        print("NEW LARGEST:", largest)
print("LARGEST x:", largest)
print("LARGEST D:", largest_d)