#include<stdio.h>
#include<stdlib.h>

int* kMergeSort(int k,int** a,int n){
    int index[k];
    for(int i=0;i<k;i++){
        index[k]=0;
    }
    int finIndex = 0;
    int finarray[n*k];
    while(finIndex<n*k){
        int min=a[0][index[0]];
        int pos = 0;
        for(int i=1;i<k;i++){
            if(index[i] < n && min<a[i][index[i]]){
                min = a[i][index[i]];
                pos = i;
            }
        }
        finarray[finIndex] = min;
        index[pos]++;
        finIndex++;
    }
}

