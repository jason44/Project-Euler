import numpy as np

seq = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
places = [1000, 100, 10, 1]

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

seen = {}
pm = []

def D(digits, remaining):
    tmp_digits = list(digits)
    for i in range(len(remaining)):
        tmp_digits.append(seq[i])
        if len(tmp_digits) == 4:
            st = ''.join([str(s) for s in sorted(set(tmp_digits))])
            if seen.get(st):
                continue
            else:
                seen[st] = 1

            F(0, tmp_digits, 0)
            #print(tmp_digits)
            npm = list(sorted(set(pm)))
            if len(npm) > 2:
                print(npm)
                for i, p1 in enumerate(npm):
                    for j, p2 in enumerate(npm[i+1:]):
                        for k, p3 in enumerate(npm[j+1:]):
                            diff1 = p2 - p1
                            diff2 = p3 - p2
                            if diff1 == diff2:
                                if p1 < 1000 or p2 < 1000 or p3 < 1000: 
                                    continue
                                seqt = [p1, p2, p3]
                                print("seq:", seqt)
            pm.clear()
        else:
            D(tmp_digits, remaining[i+1:]+remaining[:i])
        tmp_digits = list(digits)


def F(d, remaining, p):
    prime = True
    tmp_d = d
    if (p == len(places) - 1):
        tmp_d += remaining[0] * places[p]
        if is_prime(tmp_d):
            pm.append(tmp_d)

    tmp_d = d
    for offset in range(len(remaining)):
        tmp_d += remaining[offset] * places[p]
        F(tmp_d, remaining[offset+1:]+remaining[:offset], p+1)
        tmp_d = d


D([], seq)