

seq = [9, 8, 7, 6, 5, 4, 3, 2, 1]
places = [100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1]


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

def D(d, remaining, p):
    tmp_d = d
    if (p == len(places) - 1):
        assert(len(remaining) == 1)
        tmp_d += remaining[0] * places[p]
        print(tmp_d)
        if is_prime(tmp_d):
            print("PRIME:", tmp_d)
            exit(0)

    for offset in range(len(remaining)):
        tmp_d += remaining[offset] * places[p]
        D(tmp_d, remaining[offset+1:]+remaining[:offset], p+1)
        tmp_d = d


for i in range(0, 9):
    D(0, seq[i:], i)