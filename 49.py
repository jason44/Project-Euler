import numpy as np
import scipy as sc

def is_prime(n):
    if n == 0: return False
    if n == 1: return False
    if n == 2: return True
    if n < 0:
        n *= -1
    if n & 1 == 1:
        for i in range(3, n//2, 2):
            if n % i == 0:
                return False
    else:
        return False
    return True

permutations = {}

for n in range(1001, 10000, 2):
    p = ''.join(sorted(str(n)))
    if is_prime(n):
        if permutations.get(p):
            permutations[p].append(n)
        else:
            permutations[p] = [n]

for permutation in permutations.values():
    for i, p1 in enumerate(permutation):
        for j, p2 in enumerate(permutation[i+1:]):
            for k, p3 in enumerate(permutation[j+1:]):
                diff1 = p2 - p1
                diff2 = p3 - p2
                if diff1 == diff2:
                    print(''.join([str(p1), str(p2), str(p3)]))


