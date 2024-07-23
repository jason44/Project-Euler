a = []
for i in range(2, 100 + 1):
    for j in range(2, 100 + 1):
        a.append(i**j)

print(len(set(a))) 


# Non brute force algorithm:
# start with total = 99*99
# for each number a there are 99 powers a**b
# consider the powers of n that are in [2, 100] 
# if a=n**k and p is the largest number such that k**p <= 100,
# then the interval [2, p] are all duplicates.
# hence we can subtract p-1 from the 99 differnt powers of a. 

# eg: for the interval [2, 6]
# 4 = 2**2. So we find that p=3 is the largest number such that k*p <= 6. 
# in this case, it is 2*3 = 6
# Hence, ever power 4**k for k in [2, p=3] is a duplicate of some power in 2. 
# That is, 16=4**2 is a duplicate of 16=2**4 and 64=4**3 is a duplicate of 64=2**6