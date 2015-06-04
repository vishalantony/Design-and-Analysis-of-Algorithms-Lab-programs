// merge sort
/*
COMPILED USING GCC VERSION 4.7.1
WORKING PROGRAM
*/

#include <iostream>
#include <ctime>

using namespace std;

class MERGE_SORT {
private:
    static const int MAX = 200001;
    int n;
    int v[MAX];
    double timetaken;
public:
    void copy_arr(int *a, int *b, int, int s);
    void read(void);
    void display(void);
    void m_sort(int*, int);
    void merge_arr(int*, int, int*, int, int*);
};

void MERGE_SORT::copy_arr(int *a, int *b,int s, int num) {
    for(int i = s, j = 0; j < num; i++, j++)
        b[j] = a[i];
}

void MERGE_SORT::m_sort(int *a, int num) {
    if(num > 1) {
        int m = num/2;
        int b[m];
        int c[num-m];
        copy_arr(a, b, 0, m);
        copy_arr(a, c, m, num-m);
        m_sort(b, m);
        m_sort(c, num-m);
        merge_arr(b, m, c, num-m, a);
    }
}

void MERGE_SORT::merge_arr(int *b, int s1, int *c, int s2, int *a) {
    int i, j, k;
    for(i = 0, j = 0, k = 0; i < s1 && j < s2; k++)
        if(b[i] < c[j])
            a[k] = b[i++];
        else
            a[k] = c[j++];
    while(i < s1)
        a[k++] = b[i++];
    while(j < s2)
        a[k++] = c[j++];
}

void MERGE_SORT::read(void) {
    cout << "Enter the number of elements to sort: ";
    cin >> n;
    cout << "Enter " << n << " elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    clock_t start = clock();
    m_sort(v, n);
    clock_t stop = clock();
    timetaken = 1000000.0*(stop-start)/CLOCKS_PER_SEC;
}

void MERGE_SORT::display(void) {
    cout << "Sorted array is:" << endl;
    for(int i = 0; i < n; i++)
        cout << v[i] << endl;
    cout << "Time taken is: " << timetaken << " milliseconds" << endl;
 }

 int main(void) {
    MERGE_SORT s = MERGE_SORT();
    s.read();
    s.display();
    return 0;
}
