// depth first search
/*
COMPILED USING GCC VERSION 4.7.1
WORKING PROGRAM
*/

#include <iostream>

using namespace std;

class DFS_GRAPH {
    private:
        int nodes;
        int adj[100][100];
        int s[100];
        bool cyclic;
        bool connected;
        int v_stack[100];
        int top;
    public:
        DFS_GRAPH(int);
        void read_mat(void);
        void reach(void);
        void connectivity(void);
        void acyclicity(void);
        void dfs(int x);
		void isConnected(void);
};

DFS_GRAPH::DFS_GRAPH(int n) {
    nodes = n;
    top = 0;
    cyclic = 0;
	connected = true;
    for(int i = 0; i < n; i++)
        s[i] = 0;
}

void DFS_GRAPH::read_mat(void) {
    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j++)
            cin >> adj[i][j];
}

void DFS_GRAPH::dfs(int src) {
    s[src] = 1;
    v_stack[top++] = src;
    for(int i = 0; i < nodes; i++) {
        if(adj[src][i] == 1 && src != i && s[i] && top >= 2 && v_stack[top-2] != i) {	// undirected graph	
            cyclic = 1;
        }
        if(adj[src][i] == 1 && s[i] == 0) {
            dfs(i);
        }
    }
    top--;
}

void DFS_GRAPH::reach(void) {
    for(int i = 0; i < nodes; i++)
        if(s[i] == 0) {
            cout << "Node " << i+1 << " not reachable." << endl;
		}
        else
            cout << "Node " << i+1 << " reachable." << endl;
}

void DFS_GRAPH::isConnected(void) {
    for(int i = 0; i < nodes; i++)
        if(s[i] == 0) {
			connected = false;	
			return;
		}
}

void DFS_GRAPH::connectivity(void) {
	if(connected)
		cout << "The graph is connected!" << endl;
	else
		cout <<  "The graph is not connected!" << endl;
}

void DFS_GRAPH::acyclicity(void) {
    if(cyclic)
        cout << "Graph is cyclic!" << endl;
    else
        cout << "Graph is acyclic!" << endl;
}

int main(void) {
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    DFS_GRAPH g = DFS_GRAPH(n);
    g.read_mat();
	int src;
    cout << "Enter the source vertex: ";
    cin >> src;
    src = src-1;
    g.dfs(src);
	g.isConnected();
    g.connectivity();
    g.reach();
    g.acyclicity();
    return 0;
}
