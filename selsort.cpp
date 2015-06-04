// selection sort
/*
COMPILED USING GCC VERSION 4.7.1
WORKING PROGRAM
*/

#include <iostream>
#include <ctime>

using namespace std;

class selsort {
private:
    static const int MAX = 35000;
    int v[MAX];
    int n;
    double time_taken;
public:
    void read(void);
    void display(void);
    void sort_arr(void);
    void swap_val(int &a, int &b);
};

void selsort::swap_val(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selsort::read(void) {
    cout << "Enter the number of elements to sort: ";
    cin >> n;
    cout << "Enter " << n << " elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    clock_t start = clock();
    sort_arr();
    clock_t stop = clock();
    time_taken = 1.0*(stop-start)/CLOCKS_PER_SEC;
}
 void selsort::display(void) {
    cout << "Sorted array is:" << endl;
    for(int i = 0; i < n; i++)
        cout << v[i] << endl;
    cout << "Time taken is: " << time_taken*1000 << " milliseconds" << endl;
 }

void selsort::sort_arr(void) {
    int m;
    for(int i = 0; i < n-1; i++) {
        m = i;
        for(int j = i+1; j < n; j++) {
            if(v[m] > v[j])
                m = j;
        }
        swap_val(v[m], v[i]);
    }
}

int main(void) {
    selsort s = selsort();
    s.read();
    s.display();
    return 0;
}
