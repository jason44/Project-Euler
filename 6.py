
nums = range(1, 101)


def sum_sqrs():
    ret = 0
    for i in nums:
        ret += i**2
    return ret

def sqr_sum():
    sum = 0 
    for i in nums:
        sum += i
    return sum ** 2

if __name__ == "__main__":
    res = abs(sum_sqrs() - sqr_sum())
    
    print(f"{sqr_sum()} - {sum_sqrs()} = {res}") 