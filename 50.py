import numpy as np

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

primes = []
primes_sum = 0
n = 2
while (primes_sum < 1000000):
    if is_prime(n):
        primes.append(n)
        primes_sum += n
    n += 1
primes_sum -= primes[-1]
primes = primes[:-1]
print(primes)

best_length = 0
for i in range(len(primes)-5):
    culm = np.cumsum(primes[i:]).tolist()
    if len(culm) < best_length:
        break
    for i, c in enumerate(reversed(culm)):
        print(culm)
        length = len(culm) - i
        if length > best_length and is_prime(c):
            if length > best_length:
                best_length = length
                print("BEST:", c, " LENGTH:", length)
        if length >= best_length:
            break