f = open('22_names.txt', 'r')

names = f.read().split(',')
names = [name[1:-1] for name in names]
names.sort()
print(names)

values = {
    'A' : 1,
    'B' : 2,
    'C' : 3,
    'D' : 4,
    'E' : 5,
    'F' : 6,
    'G' : 7,
    'H' : 8,
    'I' : 9,
    'J' : 10,
    'K' : 11,
    'L' : 12,
    'M' : 13,
    'N' : 14,
    'O' : 15,
    'P' : 16,
    'Q' : 17,
    'R' : 18,
    'S' : 19,
    'T' : 20,
    'U' : 21,
    'V' : 22,
    'W' : 23,
    'X' : 24,
    'Y' : 25,
    'Z' : 26,
}

assert(len(values.keys()) == 26)

total_values = 0
for i, name in enumerate(names):
    name_value = 0
    for c in name:
        name_value += values[c]
    name_value *= i + 1
    print(name, i+1, name_value)
    total_values += name_value

print(total_values)
