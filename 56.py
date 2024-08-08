max_sum = 0
for a in range(2, 100):
    for b in range(1, 100):
        p = str(a**b)
        digit_sum = 0
        for c in p:
            digit_sum += int(c)
        print(digit_sum)
        if digit_sum > max_sum:
            max_sum = digit_sum

print("FOUND:", max_sum)


