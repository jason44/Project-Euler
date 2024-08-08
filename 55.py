lychrel_nums = 0
palindromic_nums = 0

for n in range(1, 10000):
    # n and n_rev obviously approach a palindrome within the same number of iterations
    lychrel = True
    cur = n
    cur_rev = int(str(cur)[::-1])
    for _ in range(50):
        cur = cur + cur_rev
        cur_rev = int(str(cur)[::-1])
        if str(cur) == str(cur)[::-1]:
            lychrel = False
            palindromic_nums += 1
            print(n)
            break
    if lychrel == True:
        lychrel_nums += 1
        #print(n)

print("TOTAL:", lychrel_nums)  
print("Palindromic:", palindromic_nums)  
assert(lychrel_nums + palindromic_nums == 10000-1)







