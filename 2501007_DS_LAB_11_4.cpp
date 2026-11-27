
#include <iostream>
using namespace std;

void printArray(const int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int bubbleDown(int a[], int n, int i) {
    int swaps = 0;

    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && a[left] > a[largest])
            largest = left;

        if (right < n && a[right] > a[largest])
            largest = right;

        if (largest == i)
            break;

        swap(a[i], a[largest]);
        swaps++;
        i = largest;
    }

    return swaps;
}

int buildMaxHeap(int a[], int n) {
    int swaps = 0;

    for (int i = n / 2 - 1; i >= 0; i--)
        swaps += bubbleDown(a, n, i);

    return swaps;
}

void heapSort(int a[], int n, bool show) {
    buildMaxHeap(a, n);

    int round = 1;

    for (int last = n - 1; last >= 1; last--) {
        swap(a[0], a[last]);
        bubbleDown(a, last, 0);

        if (show) {
            cout << "Round " << round << ": ";
            printArray(a, n);
            round++;
        }
    }
}

int main() {
    int a[] = {10, 20, 15, 30, 40, 5, 25};

    cout << "Input: ";
    printArray(a, 7);

    int swaps = buildMaxHeap(a, 7);

    cout << "Build-heap: ";
    printArray(a, 7);

    cout << "Build-heap swaps: " << swaps << endl;

    heapSort(a, 7, true);

    cout << "Sorted: ";
    printArray(a, 7);

    int b[] = {9, 4, 7, 1, 8, 2, 6, 3, 5, 0};

    heapSort(b, 10, false);

    cout << "Second array: ";
    printArray(b, 10);

    int c[] = {7, 6, 5, 4, 3, 2, 1};

    cout << "Decreasing keys 7 to 1, build-heap swaps: "
         << buildMaxHeap(c, 7) << endl;

    int d[] = {1, 2, 3, 4, 5, 6, 7};

    cout << "Increasing keys 1 to 7, build-heap swaps: "
         << buildMaxHeap(d, 7) << endl;

    return 0;
}
