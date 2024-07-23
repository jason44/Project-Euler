text = """
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
"""

graph = []
for line in text[1:].splitlines():
    nums = line.split(' ')
    row = [int(i) for i in nums]
    graph.append(row) 

[print(row) for row in graph]

dist_graph = []
for i in range(len(graph)):
    row = [0 for _ in range(i+1)]
    dist_graph.append(row)
dist_graph[0][0] = 75
[print(row) for row in dist_graph]

# Bellman-Ford to find the maximum path to all 15 of the bottom-most nodes.
def traverse():
    currents = [0]
    relaxes = 0
    for i in range(1, len(graph)):
        tmp_currents = []
        for current in currents:
            left = current
            right = current + 1
            if graph[i][left] + dist_graph[i-1][current] > dist_graph[i][left]:
                dist_graph[i][left] = graph[i][left] + dist_graph[i-1][current]
                tmp_currents.append(left)
                relaxes += 1

            if graph[i][right] + dist_graph[i-1][current] > dist_graph[i][right]:
                dist_graph[i][right] = graph[i][right] + dist_graph[i-1][current]
                tmp_currents.append(right)
                relaxes += 1
            currents = tmp_currents

    if relaxes == 0:
        print("Stopped traversing at", i, "out of", sum([len(row) for row in graph])) 
        return False
    return True



v = sum([len(row) for row in graph])
for _ in range(v):
    if not traverse():
        break


[print(row) for row in dist_graph]

print("Best:", max(dist_graph[-1]))