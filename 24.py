import math

# n is 0-indexed
# start and end are inclusive
def get_permutation(n, start=0, end=9):
    free = list(range(start, end+1))
    positions = []
    permutation = ''
    pos = 0
    for i in reversed(range(start, end+1)):
        f = math.factorial(i)
        p = math.floor((n - pos) / f)
        #print(p)

        permutation += str(free[p])
        free.pop(p)

        pos += p * f

    #print(pos)
    assert(pos == n)


    return permutation


permutation = get_permutation(1e6 - 1)
print(permutation)

"""
for i in range(6):
    get_permutation(i, start=0, end=2)
"""

