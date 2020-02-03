#include<stdio.h>
#include"session5_sort.h"

long int InsertionSort(Record* A,int n){
    long int count = 0;
    for(long int i=1;i<n;i++){
        Record temp = A[i];
        long int j = i-1;
        
        while (j>=0 &&(++count)&& A[j].serialnumber > temp.serialnumber)
        {   
            A[j+1] = A[j];
            j--;
        }
        
        A[j+1] = temp;
        
    }
    return count;
}

long int BubbleSort(Record* A,int n){
    int flag = 1;
    long int count = 1;
    for(long int i = 1;i<n;i++){
        flag =1;
        for(long int j=0;j<i;j++){
            count++;
            if(A[j].serialnumber > A[j+1].serialnumber){
                Record temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 0;
            }
        }
        
    }
    return count;
}

long int SelectionSort(Record* A, int n){
    long int count = 0;
    for(long int i=0;i<n-1;i++){
        int min = i;
        for(long int j=i+1;j<n;j++){
            if(A[j].serialnumber < A[min].serialnumber){
                Record temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
        count+=n-i-1;

    }
    return count;
}


long int BinaryInsertion(Record* A,int n){
        long int count = 0;
        int flag =1;
        for(long int i=1;i<n;i++){
                flag =1;
            Record temp = A[i];
            long int j = i-1;  
            long int beg =0;
            long int end = j;
            long int mid = (j/2);
            while(mid!=beg && flag){
            count++;
                if(A[mid].serialnumber>temp.serialnumber){
                        end = mid-1;
                }
                else if(A[mid].serialnumber<temp.serialnumber){
                        beg = mid+1;
                }
                else{
                        for(long int k=j;k>=mid;k--){
                                A[k+1]=A[k];
                        }
                        A[mid] = temp;
                        flag = 0;
                }
                mid = (beg+end)/2;
            }  
        }       
        
        
        return count;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
}
