# fibonacci numbers


def fib():
    fi = 1
    bo = 2
    na = 2
    sum = 0
    #0x3d0900
    while (na < 0x3d0900):
        print(na)
        if not na % 2:
            sum += na
        na = fi + bo
        fi = bo
        bo = na

    return sum

print(f"fib is {fib()}")