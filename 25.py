import math
import numpy as np


phi = (1 + math.sqrt(5)) / 2
psi = -0.6180339887
lpsi = math.log10(phi)
denom = math.sqrt(5)


# returns the approximate fibonacci number that approaches d digits
def growth(d):
    return d / lpsi

# returns the approximate number of d digits of the nth fibonacci number
def digits(n):
    return n * lpsi

def fib(n):
    #return (phi**n - psi**n) / denom
    return np.round(phi**n / denom)

for i in range(50, 80):
    f = str(int(fib(i)))
    d = len(f)
    g = growth(d)
    g_d = digits(i)
    err = i - g
    print(f"{f} | index: {i} | approx index {g:.2f} | error: {err:.2f} || digits {d} | approx digits {g_d:.2f} | digits err. {d-g_d:.2f}")


# from the graph above, we can see that the first occurence of a digit d occurs 
# approximately 2.5 fibonacci numbers away from the approximate fibonacci number given by growth(d)
approx1 = growth(1000)
print(approx1)
approx2 = approx1 - 2.5
print("final approx:", approx2)
#print(fib(approx))

