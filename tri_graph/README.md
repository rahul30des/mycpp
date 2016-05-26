Count triangles in an undirected graph specified in a text file.
A triangle is an ordered triplet of nodes (X, Y, Z) such that
X-Y, Y-Z and Z-X are edges of the graph.

Input file:
<number of nodes> <number of edges>
<node1> <node2>

Input:
5 5
0 1
4 3
1 2
3 1
0 2

Output:
Returns 1 because there is exactly one triangle: (0,1,2)
