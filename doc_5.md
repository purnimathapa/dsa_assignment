Q5: Graph Traversal (BFS and DFS) Using Adjacency Matrix

Overview:
This program demonstrates how to use an adjacency matrix to represent an undirected graph and perform BFS and DFS traversal.

Data Structures Used:
- adj[10][10]: A 2D matrix to represent edges between nodes.
- visited[10]: Tracks which nodes have been visited during traversal.

Functions:

bfs:
- Breadth-first search using a queue.
- Explores neighbors level by level.

dfsUtil:
- A helper function for depth-first search using recursion.

dfs:
- Sets up the visited array and starts the recursive DFS.

Main Function:
- A graph is created with 5 nodes.
- Edges are added manually:
  - 0 connected to 1 and 2
  - 1 connected to 3
  - 2 connected to 4
- BFS and DFS are both called starting from node 0.

How to Compile and Run:
gcc prog_5.c -o prog_5  
./prog_5

Sample Output:
BFS traversal: 0 1 2 3 4  
DFS traversal: 0 1 3 2 4

Notes:
- This uses a fixed graph, but you can change the edges in code to try different examples.
- The nodes are indexed from 0 to n-1.
