def add_frac(n, frac_num, frac_denom):
    sum_num = n*frac_denom + frac_num # n*2/2
    sum_denom = frac_denom
    return (sum_num, sum_denom)

total = 0
n = 2
d = 1
for _ in range(1000):
    exp_num, exp_denom = add_frac(1, d, n)
    n, d = add_frac(2, d, n)
    #print(f"{exp_num}/{exp_denom}")
    if len(str(exp_num)) > len(str(exp_denom)):
        total += 1
        print(f"FOUND: {exp_num} / {exp_denom}")

print("TOTAL:", total)


