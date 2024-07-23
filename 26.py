from math import *

best_len = 0
best_d = 0
best_rep = ''

for d in range(2, 1000):
    seen = {}
    num = 1
    rep = ''
    while num < d:
        num *= 10
    while True:
         m = num // d
         r = num - d*m 
         if r == 0 or seen.get(r) != None:
             cycle_len = len(seen.values())
             if cycle_len > best_len:
                 best_len = cycle_len
                 best_d = d
                 best_rep = rep
             break
         else:
             seen[r] = 1
         num = r*10
         while num < d:
            num = num * 10
            rep += '0'
            if seen.get(num) != None:
                seen[num] += 1
            else:
                seen[num] = 1
         rep += str(m)

    print(f"1/{d} | cycle length: {len(seen.values())} | {rep} \n {seen.values()}")
 
print(f"FINAL BEST: {best_d} | {best_rep} | cycle length: {best_len}")