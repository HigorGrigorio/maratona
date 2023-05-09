# Marathon
- This repository contains the code for the Marathon project.

# Example bfs algorithm:
## python: 
```python
def bfs(graph, start):
    # Create a queue for BFS
    queue = []

    # Mark the current node as visited and enqueue it
    visited[start] = True
    queue.append(start)

    # Iterate until the queue is empty
    while queue:
        # Dequeue a vertex from queue and print it
        u = queue.pop(0)
        print(u, end=" ")

        # Get all adjacent vertices of the dequeued vertex u
        for v in range(len(graph[u])):
            # If an adjacent vertex is found and it has not been visited, mark it as visited and enqueue it
            if graph[u][v] == 1 and not visited[v]:
                visited[v] = True
                queue.append(v)
```

## c++:
```cpp
int bfs(Graph &g, int start, vector<bool> &visited) {
    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    q.push(start);

    // Iterate until the queue is empty
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int u = q.front();
        cout << u << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex u
        for (int v = 0; v < g.matrix.size(); v++) {
            // If an adjacent vertex is found and it has not been visited, mark it as visited and enqueue it
            if (g.matrix[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```