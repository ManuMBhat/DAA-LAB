#include<stdio.h>
#include<stdlib.h>

void printbs(int* bs,int n)
{
    for(int i=0;i<n;i++)
        printf("%d",bs[i]);
    printf("\n");
}

void bitstring(int n, int* bs, int i)
{
    if(i==n)
        printbs(bs,n);
    else
    {       
        bs[i]=0;
        bitstring(n, bs, i+1);
        bs[i]=1;
        bitstring(n, bs, i+1);
    }
}

int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
    int* bs=(int*)calloc(n,sizeof(int));
	bitstring(n,bs,0);
    return 0;
}