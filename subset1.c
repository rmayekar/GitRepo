#include<stdio.h>
#include<stdlib.h>

void subset(int,int,int[]);

int main(int argc, char **argv[])
{
	int s[10],n,d,i;

	printf("\nEnter the number of elements in the set: ");
	scanf("%d",&n);

	printf("\nEnter the elements in the increasing order:\n\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d",&s[i]);
	}

	printf("\nEnter the sum of the subset: ");
	scanf("%d",&d);

	subset(n,d,s);

	return 0;
}

void subset(int n, int d, int s[])
{
	int sum = 0,found = 0;
	int i,k,selected[30];

	for(i = 0; i < n; i++)
	{
		selected[i] = 0;
	}
	
	k = 0;
	selected[k] = 1;

	printf("\nThe subsets are:\n");
	printf("{");
	while(1)
	{
		if(k < n && selected[k] == 1)
		{
			if(sum+s[k] == d)
			{
				found = 1;
				for(i = 0; i < n; i++)
				{
					if(selected[i] == 1)
					{
						printf("%d\t",s[i]);
					}
				}
				printf("}\n\n{");
				selected[k] = 0;
			}
			
			else if(sum+s[k] < d)
			{
				sum = sum+s[k];
			}

			else
			{
				selected[k] = 0;
			}
		}

		else
		{
			k--;
			while(k >= 0 && selected[k] == 0)
			{
				k--;
			}
	
			if(k < 0)
			{
				break;
			}

			selected[k] = 0;
			sum = sum-s[k];
		}
		
		k++;
		selected[k] = 1;
	}

	if(!found)
	{
		printf("\n\nThe solution does not exist\n\n");
	}
}

/* Output

Enter the number of elements in the set: 4

Enter the elements in the increasing order:

5 7 8 10

Enter the sum of the subset: 15

The number of subsets are:
{5	10	}

{7	8	}


Enter the number of elements in the set: 3

Enter the elements in the increasing order:

1 2 3

Enter the sum of the subset: 10

The subsets are:

The solution does not exist
*/















	
