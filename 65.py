from math import *
from decimal import Decimal, getcontext
from mpmath import mp

mp.prec = 155
mp.dps = 155
print(mp)

N = mp.mpf(mp.exp(1))
print(N)
k = 1
m = int(N)

S = 100

# avoid floating point precision errors
numer = mp.mpf(k)
denom = mp.mpf(N - m)

def next_value(an, numer, denom, N):
    #print(numer, denom)
    ai = int(numer / denom)
    an.append(ai)
    numer -= mp.mpf(ai) * denom
    return (denom, numer)

an = [m]
for _ in range(S-1):
    numer, denom = next_value(an, numer, denom, N)
print(an)

for stop in reversed(range(1, S+1)):
    numer = 1
    denom = an[-stop]
    for a1 in reversed(an[:-stop]):
        a_denom = denom
        a_numer = a1 * a_denom
        numer = numer + a_numer

        tmp = denom
        denom = numer
        numer = tmp
    print(f"{denom} / {numer}")

    numer = str(denom)
    _sum = 0
    for c in numer:
        _sum += int(c)
    print("SUM:", _sum)