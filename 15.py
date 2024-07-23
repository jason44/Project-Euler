import numpy as np
# Assuming that start has exactly 1 path, 
# the number of paths from start to some node N in the graph is equal to the sum of 
# paths from start to the node above N and paths from start to the node left of N
# Clearly, there is only one path from start to a node in the left or top boundary.
# Furthermore, there is a symmetry about the diagonal. 
#
# For a 4x4 lattice path
# 01 01 01 01 01
# 01 02 03 04 05
# 01 03 06 10 15
# 01 04 10 20 35
# 01 05 15 35 70
#
# we can exploit the symmetry and structure to simplify calculations
# In short, every entry with a 1 in any position, [x, 1] or [1, x] is a boundary and thus have only one path from start
# So, [2, 2] = [1, 2] + [2, 1] can be rewritten as [1, 1] + [1, 2], the sum of the first two entries of row 1.
# Also, [2, 3] = 3 = [1, 3] + [2, 2]. By our previous result, we get [1, 3] + [1, 2] + [1, 2]
# which is really just the sum of the first three entries of row 1.
# Similarly, [3, 3] = 6 can be rewritten as the sum of the first three entries of row 2, as follows
# [2, 3] is its above node. It's left node [3, 2] can be rewritten as [3, 1] + [2, 2].
# and the structure of a lattice lets us substitute [3, 1] with [2, 1], for a total sum [3, 3] = [2, 3] + [2, 2] + [2, 1]
# In general, [i, j] = sum([i-1, :j])


def lattice_path(n):
    n_nodes = n+1
    paths = [[1 for _ in range(n_nodes)]]
    for i in range(n_nodes -1): # first row was created at initialization
        line = []
        for k in range(n_nodes):
            line.append(sum(paths[i][:k+1]))
        paths.append(line)
    print(np.matrix(paths))


lattice_path(20)
            