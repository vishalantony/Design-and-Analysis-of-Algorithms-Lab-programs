// topological sort

#include <iostream>

using namespace std;

class TSORT {
private:
    int n;
    static const int MAX = 100;
    int adj[MAX][MAX];
    int inorder[MAX];
    int v_queue[MAX];
    void insert_q(int i);
    int delete_q();
    int f, r;
    void find_inorder();
    int find_null();
    void toposort();
public:
    void read();
    void write();
    TSORT() {
        f = 0;
        r = 0;
        for(int i = 0; i < MAX; i++)
            inorder[i] = 0;
    }
};

void TSORT::write() {
    if(r-f == n) {
        cout << "The topological ordering sequence is:" << endl;
        for(int i = 0; i < n; i++)
            cout << delete_q() << " ";
        cout << endl;
    }
    else
        cout << "Topological ordering sequence doesn't exist!";
}

void TSORT::read() {
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the adjacency matrix" << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];
    toposort();
}

void TSORT::find_inorder() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(adj[j][i])
                inorder[i]++;
}

int TSORT::find_null() {
    for(int i = 0; i < n; i++)
        if(inorder[i] == 0)
            return i;
    return -1;
}

void TSORT::insert_q(int i) {
    v_queue[r++] = i;
}

int TSORT::delete_q() {
    return v_queue[f++];
}

void TSORT::toposort() {
    find_inorder();
    int i = find_null();
    while(i != -1) {
		inorder[i] = -1;
        insert_q(i);
        for(int j = 0; j < n; j++)
            if(adj[i][j] != 0)
                --inorder[j];
        i = find_null();
        inorder[i] = -1;
    }
}

int main(void) {
    TSORT t = TSORT();
    t.read();
    t.write();
    return 0;
}
