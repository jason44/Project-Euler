import numpy as np
from math import *

def is_square(n):
    start = 0
    if (n & 1): start = 3
    else: start = 2
    for d in range(start, n//2 + 1, 2):
        q = n // d
        if q == d and d*(q) == n:
            return True
    return False


# upper limit:
# c = 500, then c^2 = 250000 
# if a = 1, then a^2 = 1
# then b = sqrt(250000 - 1) ~= 500
# and p ~= 1001

counts = {}
for c in range(1, 500):
    csq = c**2
    # a(b) = sqrt(c^2 - b^2) and b(a) = sqrt(c^2 - a^2). Clearly, b(a(x)) = x. 
    # Theorem: the change in a(b) is inverse and proportional to the change in b(a)
    # Proof: Let b(a+da) = b + db. Substituting, we get
    # a^2 + 2ada + da^2 + b^2 + 2bdb + db^2 = c^2
    # Since a^2 + b^2 = c^2, it follows that db = -da (or db=da=0).
    # Hence, we can stop counting at their intersection to avoid double counting
    for a in range(1, int(c/sqrt(2))+1):
        asq = a**2
        bsq = csq - asq
        b = int(sqrt(bsq))
        p = a + b + c
        if p > 1000: continue
        if is_square(bsq):
            if counts.get(p):
                counts[p] += 1
            else:
                counts[p] = 1
            print(f"[{c}, {a}, {b}]") 

counts = dict(sorted(counts.items(), key=lambda item: item[1]))
print(counts)
k, v = list(counts.items())[-1]
print(f"{k} appears {v} times")