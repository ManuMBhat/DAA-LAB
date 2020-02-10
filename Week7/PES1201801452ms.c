#include<stdio.h>
#include"mergeSort.h"

void mergeSortedHalfs(int *a, int start, int mid, int end){
    int i,j,k;
    int n1 = mid -start+1;
    int n2 = end - mid;
    
    int Left[n1],Right[n2];

    for(i=0;i<n1;i++){
        Left[i] = a[start+i];
    }
    for(j=0;j<n2;j++){
        Right[j] = a[mid+j+1];
    }

    i =0;
    j =0;
    k = start;
    while(i<n1 && j<n2){
        if(Left[i] < Right[j]){
            a[k] = Left[i];
            i++;
        }
        else{
            a[k] = Right[j];
            j++;
        }
        k++;
    }
    while(j<n2){
        a[k] = Right[j];
        j++;
        k++;
    }

    while(i<n1){
        a[k] = Left[i];
        i++;
        k++;
    }

    
}


void mergeSort(int *a, int start, int end){
    if(start < end){
        int mid = (start+end)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        mergeSortedHalfs(a,start,mid,end);
    }
}


void insertionSort(int *a, int start, int end){
    int n= end - start;
    for(int i=1;i<n;i++){
        int temp = a[i];
        int j=i-1;

        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}


void selectiveMergeSort(int *a, int start, int end, int parameter){
    int n = end - start;
    if(n > parameter){
        mergeSort(a,start,end);
    }
    else{
        insertionSort(a,start,end);
    }
}