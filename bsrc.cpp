// binary search

#include <iostream>
#include <ctime>


using namespace std;

class binsrc {
private:
    static const int MAX = 200000;
    int n;
    int v[MAX];
public:
    void read();
    int bsrc(int x);
};

void binsrc::read() {
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the numbers:" << endl;
    for(int i = 0; i < n; i++)
        cin >> v[i];
}

int binsrc::bsrc(int f) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(v[mid] == f) return mid+1;
        else if(v[mid] < f) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(void) {
    binsrc b = binsrc();
    b.read();
    cout << "Enter the element search: ";
    int f;
    cin >> f;
    clock_t start = clock();
    int i = b.bsrc(f);
    clock_t stop = clock();
    double tt = 1000.00*(stop-start)/CLOCKS_PER_SEC;
    if(i == -1) cout << "NOT FOUND!" << endl;
    else    cout << "FOUND AT " << i << endl;
    cout << "Time taken: " << tt << " ms" << endl;
    return 0;
}
