// insertion sort

#include <iostream>
#include <ctime>

using namespace std;

class ins{
private:
    static const int MAX = 30000;
    int x[MAX];
    int n;
    double time_taken;
    void isort(void);
public:
    void read_input(void);
    void write_output(void);
};

void ins::isort(void) {
    for(int i = 1; i < n; i++) {
        int k = x[i], j;
        for(j = i-1; j >= 0 && (x[j] > k); j--)
                x[j+1] = x[j];
        x[j+1] = k;
    }
}

void ins::read_input(void) {
    cout << "Enter the number of elements to sort: ";
    cin >> n;
    cout << "Enter the elements:" << endl;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    clock_t start = clock();
    isort();
    clock_t stop = clock();
    time_taken = 1000.00 * (stop - start)/CLOCKS_PER_SEC;
}

void ins::write_output(void) {
    cout << "Sorted elements are: " << endl;
    for(int i = 0; i < n; i++)
        cout << x[i] << endl;
    cout << "Time taken: " << time_taken << " ms" << endl;
}

int main(void) {
    ins i = ins();
    i.read_input();
    i.write_output();
    return 0;
}
