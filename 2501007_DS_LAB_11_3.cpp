
#include <iostream>
using namespace std;

class Heap {
private:
    int a[100];
    int n;
    bool isMax;

    void bubbleUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;

            if (isMax ? a[i] > a[p] : a[i] < a[p]) {
                swap(a[i], a[p]);
                i = p;
            } else {
                break;
            }
        }
    }

    void bubbleDown(int i) {
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int best = i;

            if (left < n &&
                (isMax ? a[left] > a[best] : a[left] < a[best])) {
                best = left;
            }

            if (right < n &&
                (isMax ? a[right] > a[best] : a[right] < a[best])) {
                best = right;
            }

            if (best == i)
                break;

            swap(a[i], a[best]);
            i = best;
        }
    }

public:
    Heap(bool maxHeap) {
        n = 0;
        isMax = maxHeap;
    }

    void insert(int key) {
        a[n] = key;
        bubbleUp(n);
        n++;
    }

    void print() const {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    int top() const {
        return a[0];
    }

    bool isEmpty() const {
        return n == 0;
    }

    int extract() {
        if (n == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }

        int root = a[0];
        a[0] = a[n - 1];
        n--;

        if (n > 0)
            bubbleDown(0);

        return root;
    }
};

int main() {
    int keys[] = {10, 20, 15, 30, 40, 50, 25, 5};

    Heap mx(true), mn(false);

    for (int i = 0; i < 8; i++) {
        mx.insert(keys[i]);
        mn.insert(keys[i]);
    }

    cout << "Max-heap: ";
    mx.print();

    cout << "Top: " << mx.top() << endl;

    for (int k = 0; k < 3; k++) {
        int r = mx.extract();
        cout << "Removed " << r << ": ";
        mx.print();
    }

    cout << "Rest in order: ";
    while (!mx.isEmpty())
        cout << mx.extract() << " ";
    cout << endl;

    cout << "Min-heap: ";
    mn.print();

    cout << "All in order: ";
    while (!mn.isEmpty())
        cout << mn.extract() << " ";
    cout << endl;

    mn.extract();

    return 0;
}
