
# 30.py finding the point where n x > D(x)
def D(x):
    sx = str(x)
    total = 0
    for c in sx:
        total += int(c)**5
    return total



for x in range(100000, 1000000):
    if x <= D(x):
        print(x, D(x))