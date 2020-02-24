#include<stdio.h>
#include<stdlib.h>


int* topoSort(int n,int graph[][n]){
    int source  = -1;
    int k = 0;
    int* ans = (int*)malloc(sizeof(int)*n);
    while(k<n){
        int bigFlag = 1;
        
        for(int i=0;i<n && bigFlag;i++){
            int flag = 0;
            for(int j=0;j<n;j++){
                if(j!=i && graph[i][j] == 1){
                    flag = 1;
                }
            }
            if(flag == 0){
                source = i;
                bigFlag = 0;
            }
        }
        if(flag == 1){
            printf("Not a DAG");
            for(int i=0;i<n;i++){
                ans[i] = -1;
            }
            return ans;
        }
        ans[k] = source;
        k++;
        for(int i=0;i<n;i++){
            graph[i][source] = 0;
        }
    }
    return ans;


}
