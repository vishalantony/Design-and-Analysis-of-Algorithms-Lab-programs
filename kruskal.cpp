// kruskal's algorithm

#include <iostream>

using namespace std;

class KRUSKAL {
private:
    static const int MAX = 100, INF = 10000000;
    int c[MAX*MAX][3]; // u v and cost
    int selected_edges[MAX-1][3];
    int p[MAX];
    int n, ne;
    bool solution_exists;
    void makeset();
    int find_set(int i);
    int find_least();
    void union_set(int a, int b);
    void mst();
public:
    void read_input();
    void write_output();
    KRUSKAL() {
        solution_exists = false;
    }
};

void KRUSKAL::makeset() {
    for(int i = 0; i < n; i++)
        p[i] = i;
}

int KRUSKAL::find_set(int i) {
    return p[i];
}

void KRUSKAL::union_set(int i, int j) {
    for(int k = 0; k < n; k++)
        if(p[k] == p[j] && k != j)
            p[k] = p[i];
    p[j] = p[i];
}

void KRUSKAL::read_input() {
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> ne;
    cout << "Enter each edge (u, v, edge weight):" << endl;
    for(int i = 0; i < ne; i++)
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    mst();
}

int KRUSKAL::find_least() {
    int min_val = INF, min_i = 0;
    for(int i = 0; i < ne; i++) {
        if(min_val > c[i][2]) {
            min_val = c[i][2];
            min_i = i;
        }
    }
    return min_i;
}

void KRUSKAL::mst() {
    makeset();
    int cnt = 0;
    while(cnt < n-1) {
        int i = find_least();
        int l = c[i][2];
        if(l != INF) {
            if(find_set(c[i][0]) != find_set(c[i][1])) {
                union_set(c[i][0], c[i][1]);
                selected_edges[cnt][0] = c[i][0];
                selected_edges[cnt][1] = c[i][1];
                selected_edges[cnt][2] = c[i][2];
                cnt++;
            }
            else {
                c[i][2] = INF;
            }
        }
        else
            break;
    }
    if(cnt == n-1) {
        solution_exists = true;
    }
}

void KRUSKAL::write_output() {
    if(solution_exists) {
        cout << "The edges of the MST are:" << endl;
        int sum = 0;
        for(int i = 0; i < n-1; i++) {
            cout << selected_edges[i][0] << " --> " << selected_edges[i][1] << " Weight: " << selected_edges[i][2] << endl;
            sum += selected_edges[i][2];
        }
        cout << "Total Weight is: " << sum << endl;
    }
    else
        cout << "Solution doesn't exist!" << endl;
}

int main(void) {
    KRUSKAL k = KRUSKAL();
    k.read_input();
    k.write_output();
    return 0;
}
