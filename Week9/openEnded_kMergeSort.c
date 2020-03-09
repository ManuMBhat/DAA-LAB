#include<stdio.h>
#include<stdlib.h>

int* kMergeSort(int k,int** a,int n){
    int index[k];
    for(int i=0;i<k;i++){
        index[i]=0;
    }
    int finIndex = 0;
    int blyat = n*k;
    int* finarray=(int*)malloc(sizeof(int)*blyat);
    while(finIndex<blyat){
        int min=__INT16_MAX__;
        int pos = -1;
        for(int i=0;i<k;i++){
            if(index[i] < n && min > a[i][index[i]]){
                min = a[i][index[i]];
                pos = i;
            }
        }
        if(pos == -1){
            return finarray;
        }
        finarray[finIndex] = min;
        index[pos]++;
        finIndex++;
    }
    
    return finarray;
}


int main(){
    int k =4;
    int **a = (int**)malloc(sizeof(int*)*k);
    int n=5;
    int m=20;
    printf("Initialising\n");
    for(int i=0;i<k;i++){
        a[i] = (int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            a[i][j] = m;
            m+=3;
        }
    }
    printf("Done Initialising\n");

    int* fin = kMergeSort(k,a,n);
    for(int i=0;i<n*k;i++){
        printf("%d ",fin[i]);
    }
    printf("\n");
}
