

sum = 0
for n in range(1, 1000 + 1): 
    sum += n**n
sum = str(sum)
print(sum)
print(sum[-10:])