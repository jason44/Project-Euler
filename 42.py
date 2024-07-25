

values = {
    'A' : 1,
    'B' : 2,
    'C' : 3,
    'D' : 4,
    'E' : 5,
    'F' : 6,
    'G' : 7,
    'H' : 8,
    'I' : 9,
    'J' : 10,
    'K' : 11,
    'L' : 12,
    'M' : 13,
    'N' : 14,
    'O' : 15,
    'P' : 16,
    'Q' : 17,
    'R' : 18,
    'S' : 19,
    'T' : 20,
    'U' : 21,
    'V' : 22,
    'W' : 23,
    'X' : 24,
    'Y' : 25,
    'Z' : 26,
}

tri_nums = []
tri_words = 0
cumsum = 0
for i in range(50):
    cumsum += i
    tri_nums.append(cumsum)

f = open('words_42.txt', 'r').read()
words = f.split(',')
words = [word[1:-1] for word in words]
for word in words:
    value = 0
    for c in word:
        value += values[c]
    if value in tri_nums:
        print(word, value)
        tri_words += 1
print("Total:", tri_words)