import random


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

# theorem: any prime number > 3 can be written as the sum 6k +- 1
# theorem: no number has factors greater than its square root
# theorem: any number > 3 and divisible by 3 is not prime
def is_prime2(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True 

# miller-rabin
def is_prime_prob(n, k=10):
    if not (n & 1):
        return False
    d = n - 1
    s = 0
    while not (d & 1):
        d //= 2
        s += 1
    for _ in range(k):
        a = random.randint(2, n-2)
        x = (a**d) % n
        for _ in range(s):
            y = (x**2) % n
            if y == 1 and x != 1 and x != n-1:
                return False
            x = y
        if y != 1: 
            return False
    return True

"""
for i in range(5, 200):
    if is_prime(i):
        if not is_prime_detrm(i):
            print(i, "false positive")
        else:
            print(i, "is prime")
    else:
        if is_prime_detrm(i):
            print(i, "is NOT prime")
"""

for i in range(2847109, 2848159):
    #print(is_prime(i))
    print(is_prime2(i))


#print(is_prime(2847109))