// QUICKSORT

/*
COMPILED USING GCC VERSION 4.7.1
WORKING PROGRAM
*/

#include <iostream>
#include <ctime>

using namespace std;

class QUICK_SORT {
    private:
        static const int MAX = 35000;
        int n;
        int val[MAX];
        double time_taken;
    public:
        void read(void);
        void quicksort(int *num, int down, int up);
        int part(int *, int, int);
        void display(void);
        void swap_num(int &a, int &b);
};

void QUICK_SORT::read(void) {
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements to sort:\n";
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }
    size_t start = clock();
    quicksort(val, 0, n-1);
    size_t stop = clock();
    time_taken = 1.0*(stop-start)/CLOCKS_PER_SEC;
}

void QUICK_SORT::display(void) {
    cout << "Sorted elements are:" << endl;
    for(int i = 0; i < n; i++) {
        cout << val[i] << " ";
    }
    cout << endl;
    cout << "Time taken: " << time_taken*1000 << " milliseconds" << endl;
}

void QUICK_SORT::swap_num(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int QUICK_SORT::part(int *a, int l, int u) {
        int x = a[l];
        int b = l, t = u;
        while(b < t) {
            while(b < u && a[b] <= x )
                b++;
            while(a[t] > x)
                t--;
            if(b < t) {
                swap_num(a[b], a[t]);
            }
        }
        swap_num(a[t], a[l]);
        return t;
}

void QUICK_SORT::quicksort(int *a, int low, int up) {
    if(low < up) {
        int j = part(a, low, up);
        quicksort(a, low, j-1);
        quicksort(a, j+1, up);
    }
}


int main(void) {
    QUICK_SORT S = QUICK_SORT();
    S.read();
    S.display();
    return 0;
}
