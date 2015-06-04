/*
knapsack problem
input:
number of items
weights and profit of each item
max weight

output: optimal solution and max profit
*/

/*
COMPILED USING GCC VERSION 4.7.1
WORKING PROGRAM
*/

#include <iostream>

using namespace std;

class knapsack{
private:
    static const int MAX_W = 100;
    static const int MAX_ITEM = 30;
    int max_weight;
    int n;
    int p[MAX_ITEM+1];
    int w[MAX_ITEM+1];
    int v[MAX_ITEM+1][MAX_W+1];
    int selected[MAX_ITEM+1];
    void opt(void);
    int maximum(int a, int b) {
        return (a>b)?a:b;
    }
public:
    void read(void);
    void write_data(void);
};

void knapsack::write_data(void) {
    cout << "The maximum value possible for the optimal knapsack configuration is: " << v[n][max_weight] << endl;
    cout << "Optimal knapsack configuration:" << endl;
    for(int i = 0; i <= n; i++)
        if(selected[i])
            cout << i << " ";
    cout << endl;
}

void knapsack::read(void) {
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the weight and profit of each item:" << endl;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> p[i];
    }
    cout << "Enter the maximum capacity of knapsack ";
    cin >> max_weight;
    opt();
}

void knapsack::opt(void) {
    for(int i = 0; i <= max_weight; i++)
        v[0][i] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= max_weight; j++) {
            if(w[i] > j)
                v[i][j] = v[i-1][j];
            else if(w[i] <= j)
                v[i][j] = maximum(v[i-1][j], p[i]+v[i-1][j-w[i]]);
        }
    }
    for(int i = 0; i <= n; i++)
        selected[i] = 0;

    for(int i = n, weight = max_weight; weight > 0; i--) {
        if(v[i][weight] != v[i-1][weight]) {
            selected[i] = 1;
            weight = weight-w[i];
        }
    }
}

int main(void) {
    knapsack k = knapsack();
    k.read();
    k.write_data();
    return 0;
}
