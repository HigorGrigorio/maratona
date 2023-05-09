#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

template<typename T>
using Matrix = vector<vector<T>>;

struct Graph {
    Matrix<bool> matrix;
    int n_edges{0}, n_vertex{0};
};

int bfs(Graph &g, int start, vector<bool> &visited) {
    // Create a queue for BFS
    queue<int> q;
    int counter = 0;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    q.push(start);

    // Iterate until the queue is empty
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int u = q.front();
        counter++;
        // cout << u << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex u
        for (int v = 0; v < g.matrix.size(); v++) {
            // If an adjacent vertex is found and it has not been visited, mark it as visited and enqueue it
            if (g.matrix[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
                counter++;
            }
        }
    }

    return counter;
}

int main() {
    Graph graph;

    int t, n;

    cin >> t;

    while (t--) {
        cin >> n >> graph.n_vertex >> graph.n_edges;
        int a, b;

        graph.matrix = Matrix<bool>(graph.n_vertex, vector<bool>(graph.n_vertex, false));

        // 1 2 3 4

        //   1 2 3 4
        // 1 0 0 0 0
        // 2 0 0 1 0
        // 3 0 0 0 0
        // 4 0 1 3 0

        // 1 ->
        // 2 -> 3
        // 3 ->
        // 4 -> 2, 3

        for (int i = 0; i < graph.n_edges; i++) {
            cin >> a >> b;
            graph.matrix[a][b] = true;
            graph.matrix[b][a] = true;
        }

        // print
        //        for (int i = 0; i < graph.n_vertex; i++) {
        //            for (int j = 0; j < graph.n_vertex; j++)
        //                cout << ' ' << (int) graph.matrix[i][j];
        //            cout << endl;
        //        }

        auto visited = vector<bool>(graph.n_vertex, false);

        int r = bfs(graph, n, visited);
        cout << r - 1 << endl;
    }

    return 0;
}