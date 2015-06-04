// djikstra's algorithm

#include <iostream>

using namespace std;

class Dijkstra {
private:
    static const int MAX = 100, NOT_DEF = MAX+1, INF = 1000000;
    int pq[MAX];
    int d[MAX];
    int p[MAX];
    int adj[MAX][MAX];
    int n;
    int f, r;
    int src;
    void minimize_pq();
    void insert_pq(int i);
    void update(int x);
    int delete_pq();
    void display(int i);
public:
    void read_input();
    void write_output();
    void shortest();
    Dijkstra() {
        f = 0;
        r = 0;
    }
};

void Dijkstra::display(int s) {
    if(s != NOT_DEF) {
            display(p[s]);
            cout << s << " -> ";
    }
}

void Dijkstra::write_output() {
    cout << "The paths from source to every other vertices are: "<< endl;
    for(int i = 0; i < n; i++) {
        if(i != src) {
            display(i);
            cout << "COST : " << d[i] << endl;
        }
    }
}

void Dijkstra::read_input() {
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix: ";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];
    cout << "Enter the source: ";
    cin >> src;
}

void Dijkstra::shortest() {
    d[src] = 0;
    p[src] = NOT_DEF;
    for(int i = 0; i < n; i++) {
        if(i != src) {
            d[i] = INF;
            p[i] = NOT_DEF;
        }
        insert_pq(i);
    }
    for(int i = 0; i < n; i++) {
        minimize_pq();
        int s = delete_pq();
        update(s);
    }
}

void Dijkstra::minimize_pq() {
    int m = f;
    for(int i = f+1; i < r; i++)
        if(d[pq[m]] > d[pq[i]])
            m = i;
    if(m != f) {
        int temp = pq[m];
        pq[m] = pq[f];
        pq[f] = temp;
    }
}

int Dijkstra::delete_pq() {
    return pq[f++];
}

void Dijkstra::insert_pq(int i) {
    pq[r++] = i;
}

void Dijkstra::update(int j) {
    for(int i = 0; i < n; i++)
        if(d[i] > d[j]+adj[j][i]) {
            d[i] = d[j]+adj[j][i];
            p[i] = j;
        }
}

int main(void) {
    Dijkstra d = Dijkstra();
    d.read_input();
    d.shortest();
    d.write_output();
    return 0;
}
