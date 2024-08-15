import cpp_utils

f = open('primes.txt').read().split(' ')
primes = f
primes.remove('')

print(primes[-1])
best = 999999 
stop_idx = len(primes) // 12

def D(prime_set):
    global best
    print(prime_set)
    pint = [int(_p) for _p in prime_set]
    if (pint[0] >= best): 
        print("BEST: ", best)
        exit()
    if sum(pint) > best: return
    if len(prime_set) == 5:
        if sum(pint) < best:
            print(pint)
            best = sum(pint)
            print("CURRENT BEST:", best)
        return 
    for p in primes[:stop_idx]:
        all_prime = True
        for n in prime_set:
            front = p + n
            back = n + p
            if not cpp_utils.is_prime2(int(back)) or not cpp_utils.is_prime2(int(front)):
                all_prime = False
                break
        if all_prime:
            tmp_set = prime_set
            tmp_set.append(p)
            D(tmp_set)

for p in primes[:stop_idx]:
    D([p])




