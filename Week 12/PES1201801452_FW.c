#include <stdio.h>
#include <stdlib.h>

#include "session12_WarshallsFloyds.h"

typedef struct ArrayHolder
{
    int tempArr[102][102];
} ArrayHolder;


void transitive_closure_warshalls(int **g, int n){
    ArrayHolder temp[n+1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[0].tempArr[i][j] = (g[i][j]);
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i <n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp[k].tempArr[i][j] = (temp[k - 1].tempArr[i][j] || (temp[k - 1].tempArr[i][k-1] && temp[k-1].tempArr[k-1][j]));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",temp[n].tempArr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void all_pairs_shortest_path_distances_floyds(int **g, int n){
    int arr[102][102];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = (g[i][j]);
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = ((arr[i][j]) < (arr[i][k] + arr[k][j])) ? arr[i][j] : (arr[i][k] + arr[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
    int n;
    scanf("%d", &n);
    int **arr_adj = (int **)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        arr_adj[i] = (int*)malloc(sizeof(int) * n);
    }

    int **arr_wt = (int **)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        arr_wt[i] = (int *)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr_adj[i][j]);
        }
    }
    transitive_closure_warshalls(arr_adj, n);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr_wt[i][j]);
        }
    }
    all_pairs_shortest_path_distances_floyds(arr_wt, n);
    return 0;
}