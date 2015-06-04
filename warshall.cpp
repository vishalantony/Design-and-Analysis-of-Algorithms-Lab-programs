// warshall
/*
COMPILED USING GCC VERSION 4.7.1
WORKING PROGRAM
*/

#include <iostream>

using namespace std;

class WARSHALL{
private:
    static const int MAX = 100;
    int n;
    int mat[MAX][MAX];
    void trans_closure();
public:
    void read();
    void write();
};

void WARSHALL::read() {
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the matrix:" << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    trans_closure();
}

void WARSHALL::write() {
    cout << "The transitive closure of the matrix is:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void WARSHALL::trans_closure() {
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
}

int main(void) {
    WARSHALL w = WARSHALL();
    w.read();
    w.write();
    return 0;
}
