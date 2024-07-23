from math import *

start = 3
# let Fd(x) be the sum of the factorials of each digit of x
# let Fd9(x) be the sum of the factorials when each digit of x is 9
# Fd9(8) = 2903040 < 99999999
# hence, Fd(x) <= Fd9(8)= 2903040 for any x 8-digit or less
end = 2903040

total = 0
for n in range(start, end+1):
    ns = str(n)
    fact_sum = 0
    for d in ns:
       fact = factorial(int(d))
       fact_sum += fact
       if fact_sum == n:
           total += n
           print(n)

print("SUM: ", total)