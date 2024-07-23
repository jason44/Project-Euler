num_map = {
    0: 0,
    1: 3,
    2: 3,
    3: 5,
    4: 4,
    5: 4,
    6: 3,
    7: 5,
    8: 5,
    9: 4,
}

num_map_t = {
    0: 0,
    2: 6,
    3: 6,
    4: 6,
    5: 5,
    6: 5,
    7: 7,
    8: 6,
    9: 6
}

ten_map = {
    0: 3,
    1: 6,
    2: 6,
    3: 8,
    4: 8,
    5: 7,
    6: 7,
    7: 9,
    8: 8,
    9: 8
}

# 1-19 will be precalculated as they do not follow the form the rest of the numbers do. 
total = sum(num_map.values()) + sum(ten_map.values())

print(total)

# 20-99
for i in range(2, 10):
    for j in range(0, 10):
        total += num_map_t[i] + num_map[j]
        print(i, j)

print(total)

HUNDRED = 7
# 100-999
for i in range(1, 10):
    for j in range(0, 10):
        for k in range(0, 10):
            if (j == 1):
                total += num_map[i] + HUNDRED + 3 + ten_map[k]
                pass
            elif (j == 0 and k == 0):
                total += num_map[i] + HUNDRED
            else:
                total += num_map[i] + HUNDRED + 3 + num_map_t[j] + num_map[k]
            print(i, j, k)

print(total)

# 1000
THOUSAND = 8
total += num_map[1] + THOUSAND

print(total)

#print(sum(num_map.values()))
#print(ten_map.values())