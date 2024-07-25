

end = 1000000

total = 0

for n in range(1, end):
    sn = str(n)
    sbinn = str(bin(n))[2:]
    sn_rev = sn[::-1]
    sbinn_rev = sbinn[::-1]
    if sn == sn_rev and sbinn == sbinn_rev:
        print(f"{sn} : {sbinn}")
        total += n

print("TOTAL:", total) 
