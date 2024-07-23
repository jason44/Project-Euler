years = range(1901, 2001)
sequence = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
sequence_leap = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

assert(sum(sequence) == 365)
assert(sum(sequence_leap) == 366)

sundays = 0
# Jan. 1 1901 is a Tuesday, so the first sunday is on the sixth
current = 6
for year in years:
    months = []
    if year % 4 == 0 and year % 100 != 0:
        months = sequence_leap
        print("leap:", year)
    elif year % 400 == 0:
        months = sequence_leap
        print("leap:", year)
    else:
        months = sequence

    for i, month in enumerate(months):
        while current <= month:
            if current == 1:
                sundays += 1
                print(year, i+1, current)
            current += 7
        current -= month

print("There are", sundays, "sundays")