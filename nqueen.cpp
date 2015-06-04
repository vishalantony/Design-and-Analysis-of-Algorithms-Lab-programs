// N queens problem

#include <iostream>

using namespace std;

class NQ {
private:
    const static int MAX = 100;
    int n;
    int numofsoln;
    int cols[MAX];
    void nqueen(int row);
    bool can_place(int r, int c);
public:
    void read(void);
    void printconfig(void);
    NQ() {
        numofsoln = 0;
    }
};


bool NQ::can_place(int r, int c) {
    for(int i = 0; i < r; i++)
        if(cols[i] == c || r-c == i-cols[i] || r+c == i+cols[i])
            return false;
    return true;
}

void NQ::printconfig(void) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if(j == cols[i]) cout << "Q";
            else cout << "#";
        cout << endl;
    }
    cout << endl << endl;
}

void NQ::nqueen(int r) {
    if(r < n) {
        int f = 0;
        for(int i = 0; i < n; i++) {
            if(can_place(r, i)) {
                cols[r] = i;
                f = 1;
                nqueen(r+1);
            }
        }
        if(r == n-1 && f == 1) {
            printconfig();
            numofsoln++;
        }
    }
}

void NQ::read() {
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "The solutions for n = " << n << " are:" << endl;
    nqueen(0);
    if(numofsoln == 0)
        cout << "For the given number of queens, solution doesn't exist!" << endl;
    cout << "Number of solutions: " << numofsoln << endl;
}

int main(void) {
    NQ q = NQ();
    q.read();
    return 0;
}
