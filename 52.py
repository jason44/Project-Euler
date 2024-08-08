n = 125874
while True:
    same = 0
    f = ''.join(sorted(str(n)))
    for m in range(2, 6 + 1):
        nm = n*m
        res = ''.join(sorted(str(nm)))
        if (res == f):
            same += 1
    if same == 5:
        print("FOUND:", n)
        break
    n += 1