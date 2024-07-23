import sys
import math


pandigital = {}
pan_sum = 0
n = '123456789'

# 10 * 100 = 1000 => 9 digits
# 100 * 100 = 10000 => 11 digits
# 1 * 1000 = 1000 => 9 digits
# 1 * 10000 = 10000 => 11 digits
# ...
# so we only need to consider products of the following kind
# 2digits * 3digits = 4digits
# 1digits * 4digit = 4digits

for x in range(10, 100):
    for y in range(100, 1000):
        z = x * y
        if (len(str(z)) > 4):
            break
        zs = str(z) + str(x) + str(y)
        zs = ''.join(sorted(zs))
        if zs == n and not pandigital.get(z):
            pandigital[z] = 1
            pan_sum += z
            print(f"{x} * {y} = {z}")

for x in range(1, 10):
    for y in range(1000, 10000):
        z = x * y
        if (len(str(z)) > 4):
            break
        zs = str(z) + str(x) + str(y)
        zs = ''.join(sorted(zs))
        if zs == n and not pandigital.get(z):
            pandigital[z] = 1
            pan_sum += z
            print(f"{x} * {y} = {z}")

print("Pandigital Sum:", pan_sum)