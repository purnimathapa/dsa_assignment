#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];

void bfs(int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS traversal: ");
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfsUtil(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            dfsUtil(i, n);
    }
}

void dfs(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS traversal: ");
    dfsUtil(start, n);
    printf("\n");
}

int main() {
    int n = 5;

    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;

    bfs(0, n);
    dfs(0, n);
    return 0;
}
