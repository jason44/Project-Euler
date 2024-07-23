
req = range(2, 21)

def factorize(x):
    for i in req:
        x /= i
        for j in req: 
            if x % j:
                x *= i
    print(x)
    return x

if __name__ == "__main__":
    candidate = 1
    for i in req:
        candidate *= i

    factorize(candidate)
    
    cmp = 1
    for i in req:
        cmp *= i

    print(cmp)