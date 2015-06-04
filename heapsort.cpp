// heap sort

#include <iostream>
#include <ctime>

using namespace std;

class HEAP {
private:
    static const int MAX = 200001;
    int heap[MAX];
    int heapsize;
    double time_taken;
    inline int right(int a) { return 2*a+1;}
    inline int left(int a) { return 2*a;}
    void max_heapify(int i);
    void build_max_heap(void);
    void exchange(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }

    void heapsort();
public:
    void read_data(void);
    void write_data(void);
};

void HEAP::max_heapify(int i) {
    int largest = i;
    if(left(i) <= heapsize && heap[left(i)] > heap[largest])
        largest = left(i);
    if(right(i) <= heapsize && heap[right(i)] > heap[largest])
        largest = right(i);
    if(largest != i) {
        exchange(heap[i], heap[largest]);
        max_heapify(largest);
    }

}

void HEAP::build_max_heap(void) {
    for(int s = heapsize/2; s >= 1; s--)
        max_heapify(s);
}

void HEAP::heapsort(void) {
    build_max_heap();
    int t_size = heapsize;
    for(int i = heapsize; i > 1; i--) {
        exchange(heap[i], heap[1]);
        heapsize--;
        max_heapify(1);
    }
    heapsize = t_size;
}

void HEAP::read_data(void) {
    cout << "Enter the size of the heap: ";
    cin >> heapsize;
    cout << "Enter the elements: " << endl;
    for(int i = 1; i <= heapsize; i++)
        cin >> heap[i];
    clock_t start = clock();
    heapsort();
    clock_t stop = clock();
    time_taken = 1000.0*(stop-start)/CLOCKS_PER_SEC;
}

void HEAP::write_data(void) {
    cout << "Sorted elements are:" << endl;
    for(int i = 1; i <= heapsize; i++)
        cout << heap[i] << endl;
    cout << "Time taken: " << time_taken << endl;
}

int main(void) {
    HEAP h = HEAP();
    h.read_data();
    h.write_data();
    return 0;
}
