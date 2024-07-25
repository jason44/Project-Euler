import numpy as np

pandigital = '123456789'
best = 0
for n in range(1, 10000):
    out = ''
    pl = 1
    while len(out) < 9:
        out += str(n*pl)
        pl += 1

    if len(out) > 9: continue
    assert(len(out) == 9)

    sout = ''.join(sorted(out))
    if sout == pandigital:
        out = int(out)
        if out > best:
            best = out
            print("new best:", best, "from:", n)

print("best:", best)
    
