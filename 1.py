
sum = 0

for i in range(10):
    if not i % 3:
        sum += i

    if not i % 5 and i % 3:
        sum+= i

print(sum)