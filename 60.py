#from utils import is_prime2
import cpp_utils

f = open('primes.txt').read().split(' ')
primes = f
primes.remove('')

print(primes[-1])
best = 98003 # previous attempt 
start_idx = primes.index('3119') + 1 # previous attempt's start
stop_idx = len(primes) // 12

def D(prime_set):
    global best
    print(prime_set)
    if len(prime_set) == 5:
        pint = [int(_p) for _p in prime_set]
        if sum(pint) < best:
            print(pint)
            best = sum(pint)
            print("CURRENT BEST:", best)
            # exit and try the current result
            # it makes sense that the smallest result would appear earlier than later
            exit(0)
        return prime_set
    start_idx = primes.index(prime_set[-1])
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

for p in primes[start_idx:stop_idx]:
    D([p])

print("BEST: ", best)




