// Breadth  first search

#include <iostream>

using namespace std;

class Graph {
private:
    static const int MAX = 100;
    int n;
    int q[MAX];
    int f, r;
    bool v[MAX];
    bool adj[MAX][MAX];
    void bfs(int);
    bool q_empty();
    int dequeue();
    void enqueue(int x);
public:
    void read_data();
    void write_data();
    Graph() {
        for(int i = 0; i < MAX; i++)
            v[i] = false;
        f = r = 0;
    }
};

bool Graph::q_empty() {
    return f == r;
}

int Graph::dequeue() {
    return q[f++];
}

void Graph::enqueue(int x) {
    q[r++] = x;
}

void Graph::read_data() {
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix:" << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];
    int src;
    cout << "Enter the source: ";
    cin >> src;
    bfs(src);
}

void Graph::write_data(void) {
    for(int i = 0; i < n; i++)
        if(v[i])
            cout << "Node " << i << " reachable" << endl;
        else
            cout << "Node " << i << " not reachable" << endl;
}

void Graph::bfs(int src) {
    v[src] = true;
    enqueue(src);
    while(!q_empty()) {
        src = dequeue();
        for(int i = 0; i < n; i++) {
            if(adj[src][i] == 1 && v[i] == false) {
                enqueue(i);
                v[i] = true;
            }
        }
    }
}

int main(void) {
    Graph b = Graph();
    b.read_data();
    b.write_data();
    return 0;
}
