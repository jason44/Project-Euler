from math import *

# comb(n, k) is symmetric about n//2, so we only need to count half of the k possible values
total = 0
for n in range(1, 100 + 1):
    found = 0 
    if (n & 1):
        for k in range(n//2, 0, -1):
            c = comb(n, k)
            if (c < 1000000):
                break
            print(f"comb({n}, {k}) = {c}")
            found += 2
    else:
        for k in range(n//2, 0, -1):
            c = comb(n, k)
            if (c < 1000000):
                break
            print(f"comb({n}, {k}) = {c}")
            found += 2
        if found > 0:
            found -= 1
    total += found

print("TOTAL:", total) 



