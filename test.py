
primes = [2]
for n in range(3, 1000000, 2):
    for i in range(3, n//2, 2):
        if n % i == 0: primes.append(n)