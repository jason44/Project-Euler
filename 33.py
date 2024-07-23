import math
import numpy as np

def wrong_reduce(n, d):
    ns = str(n)
    ds = str(d)
    for c in ns:
        idx = ds.find(c)
        if idx != -1:
            ns = ns.replace(c, '')
            ds = ds.replace(ds[idx], '')
            return (int(ns), int(ds))

numerators = []
denominators = []

for x in range(1, 9+1):
    for y in range(1, 9+1):
        for z in range(1, 9+1):
            if x == z or x == y or z == y: continue
            n1 = x + y*10
            n2 = x*10 + y
            d1 = z + y*10
            d2 = z*10 + y
            for n in [n1, n2]:
                for d in [d1, d2]:
                    if n >= d: continue
                    nw, dw = wrong_reduce(n, d)
                    gcdc = np.gcd(n, d)
                    gcdw = np.gcd(nw, dw)
                    nc, dc = (n // gcdc, d // gcdc)
                    nw, dw = (nw // gcdw, dw // gcdw)
                    """
                    if n == 49 and d == 98:
                        print(nc, dc)
                        print(nw, dw)
                    """
                    if nc == nw and dc == dw:
                        print(f"{n}/{d} == {nc}/{dc} == {nw}/{dw}")
                        numerators.append(nc)
                        denominators.append(dc)

denom = 1
num = 1
for n, d in zip(numerators, denominators):
    num *= n
    denom *= d

gcd = np.gcd(num, denom)
denom = denom // gcd
print("Denominator:", denom)
