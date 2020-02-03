#include<stdio.h>
#include"session5_sort.h"

#include<stdlib.h>
#include<time.h>
double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
    return t;
}


int main(){
        struct timespec start, end;
        long int n;
        scanf("%li",&n);
        Record *A = (Record*)malloc(sizeof(Record)*n);
        Record* B = (Record*)malloc(sizeof(Record)*n);
        Record *C = (Record*)malloc(sizeof(Record)*n);
        Record* D = (Record*)malloc(sizeof(Record)*n);
        for(long int i = 0;i < n;i++){
                scanf("%li %d",&(A[i].serialnumber),&(A[i].score));
                B[i] = A[i];
                C[i] = A[i];
                D[i]=A[i];
        }
        
        
        clock_gettime(CLOCK_REALTIME, &start); 
        long int a = InsertionSort(A,n);
        clock_gettime(CLOCK_REALTIME, &end);
        printf("InsertionSort :%li %lf\n",a,time_elapsed(start,end));
        
        clock_gettime(CLOCK_REALTIME, &start); 
        long int b = BubbleSort(B,n);
        clock_gettime(CLOCK_REALTIME, &end);
        printf("BubbleSort :%li %lf\n",b,time_elapsed(start,end));\
        
        clock_gettime(CLOCK_REALTIME, &start); 
        long int c = SelectionSort(C,n);
        clock_gettime(CLOCK_REALTIME, &end);
        printf("SelectionSort :%li %lf\n",c,time_elapsed(start,end));
        
        clock_gettime(CLOCK_REALTIME, &start); 
        long int d = BinaryInsertion(D,n);
        clock_gettime(CLOCK_REALTIME, &end);
        printf("BinaryInsertion Sort :%li %lf\n",d,time_elapsed(start,end));
        
        
        return 0;
        
}
