
#include <iostream>
using namespace std;

class MaxHeap {
private:
    int a[100];
    int n;

public:
    MaxHeap() {
        n = 0;
    }

    void insert(int value) {
        if (n == 100) {
            cout << "Heap is full" << endl;
            return;
        }

        a[n] = value;
        int i = n;
        n++;

        while (i > 0) {
            int parent = (i - 1) / 2;

            if (a[parent] < a[i]) {
                int temp = a[parent];
                a[parent] = a[i];
                a[i] = temp;

                i = parent;
            }
            else {
                break;
            }
        }
    }

    void print() const {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    int keys[] = {10, 20, 15, 30, 40, 50, 25, 5};

    for (int i = 0; i < 8; i++) {
        h.insert(keys[i]);
        cout << "after " << keys[i] << ": ";
        h.print();
    }

    return 0;
}
