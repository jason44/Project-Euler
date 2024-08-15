from cpp_utils import *

figures_mask = [False, False, False, False, False, False]
figures = [is_triangle, is_square, is_penta, is_hexa, is_hepta, is_octa]

assert(len(figures_mask) == len(figures))
assert(is_triangle(6))
assert(is_square(9))
assert(is_penta(12))
assert(is_hexa(15))
assert(is_hepta(18))
assert(is_octa(40))

def match(nset):
    # generate preferences
    preferences = [[], [], [], [], [], []]
    for _n in nset:
        for i in range(len(figures)):
            if figures[i](_n):
                preferences[i].append(_n)
    
    for pref in preferences:
        if len(pref) == 0:
            return False

    # match
    for i in range(len(figures)):
        match = preferences[i][0]
        for pref in preferences:
            if match in pref:
                pref.remove(match)
        for pref in preferences[i+1:]:
            if len(pref) == 0:
                return False
    return True

def D(nset, fig_mask):
    n = nset[-1]
    a = nset[0]

    res = False
    for i in range(len(fig_mask)):
        if figures[i](n):
            fig_mask[i] = True
            res = True
    if not res: return

    print(nset)

    if len(nset) > 5: return

    if len(nset) == 5:
        first = str(n)[-2:]
        second = str(a)[:2]
        last = int(first + second)

        res = False
        for i in range(len(fig_mask)):
            if figures[i](last): 
                fig_mask[i] = True
                res = True
        if not res: return

        nset.append(last)
        if not match(nset): return

        print("FOUND:", nset)
        print("SUM:", sum(nset))
        exit(0)    

    for end in range(10, 100):
        first = str(n)[-2:]
        second = str(end)
        #if len(second) == 1: second = '0' + second
        tmp_set = nset.copy()
        tmp_mask = fig_mask.copy()
        tmp_set.append(int(first + second))
        D(tmp_set, tmp_mask)

for n in range(1000, 10000):
    if str(n)[2] == '0': continue
    D([n], figures_mask)