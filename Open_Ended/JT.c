#include<stdio.h>

int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	johnson(n);
}

void johnson(int n)
{
	int* arr=(int*)malloc(sizeof(int)*n);
	int* dir=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		arr[i]=i+1;
		dir[i]=0;
	}
	int counter=1;
	int* mob=(int*)malloc(sizeof(int)*n);
	while(counter)
	{
		display(arr,dir,n,counter);
		counter++;
		int max_mob=0;
		for(int i=0;i<n && !max_mob;i++)
			if(arr[i]==1)
				max_mob=i;
		for(int i=0;i<n;i++)
		{
			if(i==0 && dir[i]==0)
				mob[i]=0;
			else if(i==n-1 && dir[i]==1)
				mob[i]=0;
			else
			{
				if(dir[i]==0)
				{
					if(arr[i]>arr[i-1])
						mob[i]=1;
					else
						mob[i]=0;
				}
				else
				{
					if(arr[i]>arr[i+1])
						mob[i]=1;
					else
						mob[i]=0;
				}
			}
			if(mob[i]==1 && arr[i]>arr[max_mob])
				max_mob=i;
		}
		if(mob[max_mob]==0)
			counter=0;
		else
		{
			if(arr[max_mob]<n)
			{
				for(int i=0;i<n;i++)
					if(arr[i]>arr[max_mob])
						dir[i]=!dir[i];
			}
			if(dir[max_mob]==0)
			{
				swap(&arr[max_mob], &arr[max_mob-1]);
				swap(&dir[max_mob], &dir[max_mob-1]);
			}

			else
			{
				swap(&arr[max_mob], &arr[max_mob+1]);
				swap(&dir[max_mob], &dir[max_mob+1]);
			}
		}
	}
}

void swap(int* a,int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void display(int* arr, int* dir, int n, int count)
{
	printf("Permutation %d)\n",count);
	for(int i=0;i<n;i++)
	{
		if(dir[i]==0)
			printf("<-- ");
		else
			printf("--> ");
	}
	printf("\n");
	for(int i=0;i<n;i++)
		printf(" %d  ",arr[i]);
	printf("\n");
}