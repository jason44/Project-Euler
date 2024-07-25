
seq = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
places = [1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1]
checks = [2, 3, 5, 7, 11, 13, 17]
total = 0


def D(d, remaining, p):
    global total
    tmp_d = d
    if (p == len(places) - 1):
        assert(len(remaining) == 1)
        tmp_d += remaining[0] * places[p]
        tmp_d = str(tmp_d)
        if len(tmp_d) == 10: 
            divisible = 1
            for i, (x, y, z) in enumerate(zip(tmp_d[1:], tmp_d[2:], tmp_d[3:])):
                if not (int(x+y+z) % checks[i] == 0):
                    divisible = 0
            if divisible and len(tmp_d) == 10:
                total += int(tmp_d)
                print(tmp_d)
    tmp_d = d
    for offset in range(len(remaining)):
        tmp_d += remaining[offset] * places[p]
        D(tmp_d, remaining[offset+1:]+remaining[:offset], p+1)
        tmp_d = d


D(0, seq, 0)
print("TOTA:", total)