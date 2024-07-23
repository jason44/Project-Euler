import io

nums = []
fnums = []
if __name__ == "__main__":
    with open("8-data") as f:
        for i in f:
            for j in i:
                   nums.append(j)
        for i in range(nums.count('\n')):
            nums.remove('\n')
        for i in nums:
            fnums.append(int(i))
        print(fnums)
        best = 0
        for k in range(len(nums)-13):
            candidate = 1
            for i in range(k, k+13):
                candidate *= fnums[i]
            if candidate > best:
                best = candidate
        print(f"BEST: {best}")
        f.close()