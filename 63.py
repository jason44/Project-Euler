ncounts = {}

for pow in range(1, 50):
    ncounts[pow] = 0
    for i in range(1, 10000):
        p = str(i**pow)
        if len(p) > pow: break
        if len(p) == pow:
            ncounts[pow] += 1

for k, v in ncounts.items():
    print(f"{k} : {v}") 

print("SUM:", sum(ncounts.values()))