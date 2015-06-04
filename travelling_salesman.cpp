// travelling salesman problem
// uses branch and bound and backtracking

#include <iostream>


using namespace std;

class tsp {
private:
    const static int MAX = 100;
    const static int INF = 100000000;
    int n;
    int soln;
    bool visited[MAX];
    int adj[MAX][MAX];
    int v_stack[MAX];
    int copy_stack[MAX];
    int top;
    void push(int a);
    void stackcopy();
    int pop(void);
    int len;
    int min_cost;
public:
    tsp() {
        for(int i = 0; i < MAX; i++)
            visited[i] = false;
        top = 0;
        len = 0;
        min_cost = INF;
        soln = 0;
    }
    void travel(int src, int p);
    void read_ip();
    void write_op();
};

void tsp::push(int a) {
    v_stack[top++] = a;
}

int tsp::pop(void) {
    return v_stack[--top];
}

void tsp::write_op(void) {
    if(soln == 1) {
        cout << "Minimum path length is : " << min_cost << endl;
        cout << "Path is: " << endl;
        for(int i = 0; i <= n; i++)
            cout << copy_stack[i] << endl;
        cout << endl;
    }
    else
        cout << "Solution doesn't exist!" << endl;
}

void tsp::read_ip() {
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency cost matrix:" << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if(adj[i][j] == 0)
                adj[i][j] += INF;
        }
    cout << "Enter the source vertex: ";
    int src;
    cin >> src;
    travel(src, src);
}

void tsp::travel(int src, int p) {
    visited[src] = true;
    push(src);
    if(p != src)
        len = len + adj[src][p];
    for(int i = 0; i < n; i++)
        if(visited[i] == false && adj[src][i] != INF)
            if(len+adj[src][i] < min_cost)
                travel(i, src);
    int i;
    for(i = 0; i < n && visited[i]; i++);
    if(i == n) {        // all vertices are visited
        if(len+adj[src][v_stack[0]] < min_cost) {
            min_cost = len+adj[src][v_stack[0]];
            push(v_stack[0]);
            stackcopy();
            pop();
            soln = 1;
        }
    }
    if(p != src)
        len = len-adj[src][p];
    pop();
    visited[src] = false;
}

void tsp::stackcopy() {
    for(int i = 0; i < top; i++)
        copy_stack[i] = v_stack[i];
}

int main(void) {
    tsp t = tsp();
    t.read_ip();
    t.write_op();
    return 0;
}
