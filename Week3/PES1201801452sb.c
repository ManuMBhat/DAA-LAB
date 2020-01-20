#include<stdio.h>
#include"sort.h"

int isSorted(int *a, int n){
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1])
            return 0;
    }
    return 1;
}


void bubblePass(int *a, int n){
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            int temp = a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
}

void bubbleSort(int *a, int n){
    // while(!isSorted(a,n)){
    //     bubblePass(a,n);
    // }
    if(n==1 || isSorted(a,n))
        return;
    bubblePass(a,n);
    bubbleSort(a,n-1);
}

int numBubblePasses(int *a, int n){
    int count = 0;
    while(!isSorted(a,n)){
        count++;
        bubblePass(a,n);
    }
    return count;
}

int maxIndex(int *a, int n){
    int max = a[0];
    int pos = 0;
    for(int i = 0;i<n;i++){
        if(a[i] >= max){
            max = a[i];
            pos = i;
        }
    }
    return pos;
}


void swapWithMax(int *a, int n){
    int maxPos = maxIndex(a,n);
    int temp = a[maxPos];
    a[maxPos] = a[n-1];
    a[n-1] = temp;
}

void selectionSort(int *a, int n){
    if(n==1 || isSorted(a,n))
        return;
    swapWithMax(a,n);
    selectionSort(a,n-1);

}

int numSwaps(int *a, int n){
    int count = 0;
    int i = 0;
    while(!isSorted(a,n)){
        if(maxIndex(a,n-i) < (n-i-1)){
            count++;
            swapWithMax(a,n-i);
        }
            i++;
        
    }
    return count;
}