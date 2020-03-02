#include "quickSort.h"
#include <stdlib.h>
#include <stdio.h>

ptrPair divide(int *a, int n)
{
    ptrPair p;
    int index = (getPartitionIndex(a, n)) + 1;
    p.first = &a[0];
    p.second = a + index;
    p.firstLen = index;
    p.secondLen = n - index;
    return p;
}

int getPartitionIndex(int *a, int n)
{
    int x = a[0];
    int i = -1;
    int j = n;
    while (1)
    {
        do
            i++;
        while (a[i] < x);
        do
            j--;
        while (a[j] > x);
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
            return j;
    }
}

void conquer(int *a, int n)
{
    if (n <= 1)
        return;
    ptrPair p = divide(a, n);
    conquer(p.first, p.firstLen);
    conquer(p.second, p.secondLen);
}

void quickSort(int *a, int n)
{
    conquer(a, n);
}

int isSorted(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            return 0;
    }
    return 1;
}
