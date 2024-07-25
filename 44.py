import numpy as np
from math import *

best = ()
min = 99999999

pent_nums = []
for n in range(1, 4000):
    pent_nums.append((n*(3*n - 1)) // 2)

for i in range(len(pent_nums)):
    for j in range(i+1, len(pent_nums)):
        pent = True
        p1 = pent_nums[i]
        p2 = pent_nums[j]
        s = p1 + p2
        d = p2 - p1
        # P = n(3n - 1)/2
        # 3n^2 - n - 2P = 0
        # n = 1 + sqrt(1 - 4(3)(-2P))/2(3)
        # n = [sqrt(24P + 1) + 1]/6
        # if n is an integer, then P is an integer and hence Pentagonal
        ns = (sqrt(24*s + 1) + 1) / 6 
        nd = (sqrt(24*d + 1) + 1) / 6 
        pent &= ns.is_integer()
        pent &= nd.is_integer()
        if pent:
            if d < min:
                min = d
                best = (p1, p2)
            print(p1, p2)

print("BEST:", best)
            
