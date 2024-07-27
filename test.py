
def is_prime(n):
    if n & 1 == 1:
        for i in range(3, n//2, 2):
            if n % i == 0:
                return False
    else:
        return False
    return True

primes = [2]
def find_primes(_primes):
    for n in range(3, 10000, 2):
        if is_prime(n):
            _primes.append(n)
            #print(n)

find_primes(primes)



test = [3019, 3119, 3229, 3449, 3559, 3779, 3889]
for t in test:
    assert(is_prime(t))