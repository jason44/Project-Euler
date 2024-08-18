

perm_map = {}
perm_group = {}

for n in range(1, 6000):
    perm_map[n**3] = n

candidates = []
square_candidates = []

def permute(n, indices, remaining):
    if len(n) == len(indices):
        permutation = ''
        for i in indices:
            permutation += n[i]
        ip = int(permutation)
        if perm_map.get(ip) and perm_map[ip] not in square_candidates:
            candidates.append(permutation)
            square_candidates.append(perm_map[ip])
        return

    for i in remaining:
       tmp_indices = indices.copy()
       tmp_indices.append(i)
       tmp_rem = remaining.copy()
       tmp_rem.remove(i)
       permute(n, tmp_indices, tmp_rem)                  

#for c in list(perm_map.keys())[1026:]:
c = 5192
s = str(c)
candidates.append(s)
square_candidates.append(perm_map[c])
#sorted_s = ''.join(sorted(s))
#if perm_group.get(sorted_s): continue
#else: perm_group[sorted_s] = True
permute(s, [], list(range(len(s))))
for c in candidates:
    if c[0] == '0':
        candidates.remove(c)
if len(candidates) == 5:
    print(candidates)
    print(square_candidates)
    exit(0)
print(candidates)
print(square_candidates)
candidates.clear()
square_candidates.clear()


# (n-1 choose z)
# 