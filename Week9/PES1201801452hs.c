#include "heapSort.h"

Heap buildMaxHeap(int *const a, int n)
{
    Heap h;
    h.a = a;
    h.size = n;
    for (int i = ((n / 2) - 1); i >= 0; i--)
        maxHeapify(h, i);
    return h;
}

void maxHeapify(Heap h, int idx)
{
    int largest = idx;
    int c1 = 2 * idx + 1;
    int c2 = 2 * idx + 2;
    if (c1 < h.size && h.a[c1] > h.a[largest])
        largest = c1;
    if (c2 < h.size && h.a[c2] > h.a[largest])
        largest = c2;
    if (largest != idx)
    {
        int temp = h.a[idx];
        h.a[idx] = h.a[largest];
        h.a[largest] = temp;
        maxHeapify(h, largest);
    }
}

void heapSort(int *const a, int n)
{
    Heap h = buildMaxHeap(a, n);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = h.a[0];
        h.a[0] = h.a[i];
        h.a[i] = temp;
        h.size--;
        maxHeapify(h, 0);
    }
}
