Q7: Dijkstra’s Algorithm to Find Shortest Path from a Source

Overview:
This program implements Dijkstra’s algorithm to find the shortest distance from a given source node to all other nodes in a weighted graph.

Data Structures Used:
- A 2D array (adjacency matrix) is used to represent the graph.
- dist[]: stores the shortest known distance from the source to each node.
- visited[]: tracks which nodes have been finalized.

Functions:

minDistance:
- Scans the dist array and returns the index of the unvisited node with the smallest distance.

dijkstra:
- Updates shortest distances using the core logic of Dijkstra’s algorithm.
- For every node, it checks all its neighbors and updates their distance if a shorter path is found.

Main Function:
- Defines a graph with 5 nodes and various weights.
- Calls the dijkstra function starting from node 0.

How to Compile and Run:
gcc prog_7.c -o prog_7  
./prog_7

Sample Output:
Shortest distances from node 0:  
To 0: 0  
To 1: 10  
To 2: 50  
To 3: 30  
To 4: 60


