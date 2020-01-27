#include "tsp.h"
#include<stdio.h>
#include<stdlib.h>

int getCost(int n, int graph[][n], int *P){
    int cost = 0;
    for(int i=0;i<n-1;i++){
        cost += graph[P[i]][P[i+1]];
    }
    cost += graph[P[n-1]][P[0]];
    return cost;
}

int tsp(int n, int graph[][n]){
    int perm[n];
    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
    }
    int cost = 0;
    int Mincost = getCost(n,graph,perm);
    while(get_next_permutation(perm,n)){
        cost = getCost(n,graph,perm);
        if( cost < Mincost){
            Mincost = cost;
        }
    }
    return Mincost;
    
}

int* printPath(int n, int graph[][n]){
    int perm[n];
    int* MinPerm = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
    }

    int Mincost = getCost(n,graph,perm);
    int cost = Mincost;
    for(int i =0;i<n;i++){
        MinPerm[i]=perm[i];
    }
    while(get_next_permutation(perm,n)){
        cost = getCost(n,graph,perm);
        if( cost < Mincost){
            Mincost = cost;
            for(int i=0;i<n;i++){
                MinPerm[i] = perm[i];
            }
        }
    }
    return MinPerm;
    
}

