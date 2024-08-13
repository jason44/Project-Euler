f = open('primes.txt').read().split(' ')
primes = f
primes.remove('')
primes_map = {}
for p in primes:
    primes_map[p] = True

print(primes[-1])
best = 9999999999
stop_idx = 0
while len(primes[stop_idx]) <= len(primes[-1]) // 2: stop_idx += 1
print(stop_idx)
print(primes[stop_idx])

def D(prime_set):
    global best
    print(prime_set)
    if len(prime_set) == 5:
        pint = [int(_p) for _p in prime_set]
        if sum(pint) < best:
            print(pint)
            best = sum(pint)
            print("CURRENT BEST:", best)
        return prime_set
    start_idx = primes.index(prime_set[-1])
    for p in primes[start_idx:stop_idx]:
        all_prime = True
        for n in prime_set:
            front = p + n
            back = n + p
            if not primes_map.get(back) or not primes_map.get(front):
                all_prime = False
                break
        if all_prime:
            tmp_set = prime_set
            tmp_set.append(p)
            D(tmp_set)

for p in primes[:stop_idx]:
    D([p])

print("BEST: ", best)




