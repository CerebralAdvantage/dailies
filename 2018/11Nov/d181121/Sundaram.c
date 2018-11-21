

#include <stdio.h>

int main()
{
	int n = 100;
	int target = n/2;
	int s = 0;
	int arr[1000];
	int i,j;
	for(i=0;i<1000;i++) arr[i] = 1;

	for (i=1; i+i+1+(2*i*(i+1)) < target; i++)	
		for (s=j=i; i+j+(2*i*j) < target; j++)
		{
			s = i+j+(2*i*j);
			arr[s] = 0;
		}
printf("%d %d really?\n", i, j);
	for (i=0;i<target;i++)
		if(arr[i] == 1)
			printf("%d ",2*i+1);
	printf("\n");
	return 0;
}
