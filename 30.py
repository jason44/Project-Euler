

numbers = []

def D(x):
    sx = str(x)
    total = 0
    for c in sx:
        total += int(c)**5
    return total

# Conjecture:
# let D(x) be the function that represents the sum of the digits of x raised to the 5th power.
# at some point x=n, it will always be the case that x > D(x) for x >= n

# choosing '9' for all digits of x has the benefit that 
# if y has the same number of digits as x but different digits,
# then the inequality D(y) < D(x) < x holds. 
# so if we let the stop, y, be D(x) then we retain the inequality D(y) < y.
mp = 9**5
d = 1
stop = 0 
while stop == 0:
    if int('9'*d) > mp*d:
        stop = int(mp*d)
    d += 1
print(stop)

assert(stop > D(stop))

for n in range(3, stop):
    if D(n) == n:
        numbers.append(n)

print(numbers)
print("SUM:", sum(numbers))