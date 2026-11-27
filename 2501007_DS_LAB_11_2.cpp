
#include <iostream>
using namespace std;

class Heap {
private:
    int a[100];
    int n;
    bool isMaxHeap;

public:
    Heap(bool maxHeap) {
        n = 0;
        isMaxHeap = maxHeap;
    }

    int insert(int value) {
        if (n == 100) {
            cout << "Heap is full" << endl;
            return 0;
        }

        a[n] = value;
        int i = n;
        n++;

        int swaps = 0;

        while (i > 0) {
            int parent = (i - 1) / 2;

            bool shouldSwap;

            if (isMaxHeap) {
                shouldSwap = (a[i] > a[parent]);
            }
            else {
                shouldSwap = (a[i] < a[parent]);
            }

            if (shouldSwap) {
                int temp = a[i];
                a[i] = a[parent];
                a[parent] = temp;

                swaps++;
                i = parent;
            }
            else {
                break;
            }
        }

        return swaps;
    }

    void printLevels() const {
        int index = 0;
        int level = 0;
        int count = 1;

        while (index < n) {
            cout << "Level " << level << ": ";

            for (int j = 0; j < count && index < n; j++) {
                cout << a[index] << " ";
                index++;
            }

            cout << endl;

            count = count * 2;
            level++;
        }
    }
};

int main() {
    int keys[] = {10, 20, 15, 30, 40, 5, 25};

    Heap mx(true), mn(false);

    cout << "Max-heap swaps: ";
    for (int i = 0; i < 7; i++)
        cout << mx.insert(keys[i]) << " ";

    cout << endl;
    mx.printLevels();

    cout << "Min-heap swaps: ";
    for (int i = 0; i < 7; i++)
        cout << mn.insert(keys[i]) << " ";

    cout << endl;
    mn.printLevels();

    Heap w(true);
    int total = 0;

    for (int i = 1; i <= 7; i++)
        total += w.insert(i);

    cout << "Increasing keys 1 to 7 in a max-heap: "
         << total << " swaps" << endl;

    w.printLevels();

    return 0;
}
