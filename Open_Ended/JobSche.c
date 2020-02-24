#include<stdio.h>
#include<stdlib.h>

void toposort(int v, int n, int* visited, int* arr, int* c, int graph[][n])
{
    visited[v]++;
    for(int i=0;i<n;i++)
    {
            if(!visited[i] && graph[v][i])
                toposort(i,n,visited,arr,c,graph);
    }
    arr[(*c)]=v;
    (*c)++;
}

int main()
{
    int n;
    printf("Enter no. of Jobs: ");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter dependency of Jobs (DAC, Source is 0):-\n");
    for (int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    int* arr=(int*)malloc(sizeof(int)*n);
    int* visited=(int*)calloc(n,sizeof(int));
    int c=0;
    for(int l=0;l<n;l++)
    {
        if(!visited[l])
            toposort(l,n,visited,arr,&c,graph);
    }
    for(int g=n-1;g>=0;g--)
        printf("Job %d \n",arr[g]);
    return 0;
}