// Prim's algorithm

#include <iostream>

using namespace std;

class Prim {
private:
    int n;
    static const int  MAX = 100, INF = 10000, NOT_DEF = MAX+1;
    int adj_cost[MAX][MAX];
    int d[MAX][2];
    bool v[MAX];
    int src;
public:
    void mst(int src);
    void read();
    void write();
    Prim() {
        src = 0;
        for(int i = 0; i < MAX; i++) {
            v[i] = false;
            d[i][0] = INF;
            d[i][1] = NOT_DEF;
        }
    }
};

void Prim::read() {
    cout << "Number of nodes: ";
    cin >> n;
    cout << "Enter the matrix:" << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj_cost[i][j];
    mst(src);
}

void Prim::mst(int s) {
    for(int i = 0; i < n; i++) {							// the number of nodes to be visited is n. Hence running a loop n times to visit n nodes.
        v[s] = 1;											// current node is visited.
        int min_cost = INF, min_src = NOT_DEF;				// minimum cost is initialized to infinity to record the minimum cost using the next loops.
        for(int j = 0; j < n; j++) {						// scan through all the nodes to see which is the next node to be visited.
            if(v[j] == 0 && d[j][0] > adj_cost[s][j]) {		// if the recorded distance of the unvisited node is greater than the distance from the current node (the node just added), update the nearest distance.
                d[j][0] = adj_cost[s][j];
                d[j][1] = s;								// update the penultimate vertex
            }
            if(min_cost > d[j][0] && v[j] == 0) {			// if the minimum distance of the unvisited vertex is lesser than the minimum distance recorded so far, update the minimum distance.
                min_cost = d[j][0];
                min_src = j;								// nearest neighbor is also changed.
            }
        }
        s = min_src;										// change the nearest vertex and repeat the above procedure.
    }
}

void Prim::write() {
    cout << "The edges of the minimal spanning tree are:" << endl;
    for(int i = 0; i < n; i++)
        if(d[i][1] != NOT_DEF)
            cout << d[i][1] << " ----> " << i << " Edge weight : " << d[i][0] << endl;
    cout << "Total weight of the MST is : ";
    int sum = 0;
    for(int i = 0; i < n; i++)
        if(d[i][1] != NOT_DEF)
            sum += d[i][0];
    cout << sum << endl;
}

int main(void) {
    Prim p = Prim();
    p.read();
    p.write();
    return 0;
}
