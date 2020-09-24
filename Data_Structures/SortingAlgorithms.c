#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

//Sorting functions prototype
void countingsort(int array[], int n);
void radixsort(int array[], int n);
void shellsort(int array[], int n);
void bucketsort(int array[], int n);

//Supporting functions
void internalsort(int array[], int n, int x);
void insertionsort(int array[],int n);
void displayarray(int array[],int n);
int getcount(int array[], int x, int n);

int main()
{
	int inp[MAX_SIZE], x, i, size;

	menu:
	for(i=0;i<MAX_SIZE;i++)
	{
		inp[i] = -1;
	}
	printf("\nMenu: ");
	printf("\n1.Shell Sort");
	printf("\n2.Counting Sort");
	printf("\n3.Bucket Sort");
	printf("\n4.Radix Sort");
	printf("\n5.End");
	printf("\nEnter Sorting Option: ");
	scanf("%d",&x);

	switch(x)
	{
		case 1:
				system("cls");
				printf("----------SHELL SORT ALGORITHM----------");
				printf("\nEnter Number of Elements: ");
				scanf("%d",&size);
				printf("Enter Data for Array: ");
				for(i=0;i<size;i++)
				{
					scanf("%d",&inp[i]);
				}

				shellsort(inp,size);
				printf("Sorted Array After Shell Sort is: ");
				displayarray(inp,size);
				goto menu;

		case 2:
				system("cls");
				printf("----------COUNTING SORT ALGORITHM----------");
				printf("\nEnter Number of Elements (n): ");
				scanf("%d",&size);
				printf("Counting sort works for data in range [0,%d(n)]\n",size);
				printf("Enter Data for Array: ");
				for(i=0;i<size;i++)
				{
					scanf("%d",&inp[i]);
				}

				countingsort(inp,size);
				printf("Sorted Array After Counting Sort is: ");
				displayarray(inp,size);
				goto menu;
	
		case 3:
				system("cls");
				printf("----------BUCKET SORT ALGORITHM----------");
				printf("\nEnter Number of Elements: ");
				scanf("%d",&size);
				printf("Bucket Sort works for data in range [0,100]\n");
				printf("Enter Data for Array: ");
				for(i=0;i<size;i++)
				{
					scanf("%d",&inp[i]);
				}

				bucketsort(inp,size);
				printf("Sorted Array After Bucket Sort is: ");
				displayarray(inp,size);
				goto menu;

		case 4:
				system("cls");
				printf("----------RADIX SORT ALGORITHM----------");
				printf("\nEnter Number of Elements: ");
				scanf("%d",&size);
				printf("Radix Sort works for data in range [0,1000]\n");
				printf("Enter Data for Array: ");
				for(i=0;i<size;i++)
				{
					scanf("%d",&inp[i]);
				}

				radixsort(inp,size);
				printf("Sorted Array After Radix Sort is: ");
				displayarray(inp,size);
				goto menu;

		case 5:
				break;

		default:
				printf("Wrong Input!! Enter Again\n");
				goto menu;
	}

	return 0;
}

void displayarray(int array[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}

void shellsort(int array[], int n)
{
	int shell_size, interval, shell[MAX_SIZE][MAX_SIZE];
	int i, j, k = 0, k1 = 0;
	shell_size = 2;

	for(i=0;i<MAX_SIZE;i++)
	{
		for(j=0;j<MAX_SIZE;j++)
		{
			shell[i][j] = -1;
		}
	}

	while(shell_size <= n)
	{
		k = 0;
		interval = n/shell_size;
		for(i=0;i<interval;i++)
		{
			for(j=i;j<n;j+=interval)
			{
				shell[i][k] = array[j];
				k++;
			}
		}

		for(i=0;i<interval;i++)
		{
			insertionsort(shell[i],shell_size);
		}

		for(i=0;i<interval;i++)
		{
			k1 = i;
			for(j=0;j<n;j++)
			{
				if(shell[i][j] != -1)
				{
					array[k1] = shell[i][j];
					k1 += interval;
				}
			}		
		}

		for(i=0;i<MAX_SIZE;i++)
		{
			for(j=0;j<MAX_SIZE;j++)
			{
				shell[i][j] = -1;
			}
		}
		shell_size += 1;
	}
}

void countingsort(int array[], int n)
{
	typedef struct node
	{
		int index;
		int count;
		struct node *next;
	}NODE;

	NODE *head, *newnode, *temp;
	head = newnode = temp = NULL;
	int i, result[MAX_SIZE] = {0}, ind;
	for(i=0;i<=n;i++)
	{
		if(i==0)
		{
			newnode = (NODE *)malloc(sizeof(NODE));
			newnode -> next =  NULL;
			newnode -> index = i;
			newnode -> count = getcount(array,i,n);
			head = newnode;
			temp = newnode;
		}
		else
		{
			newnode = (NODE *)malloc(sizeof(NODE));
			newnode -> index = i;
			newnode -> count = getcount(array,i,n) + temp -> count;
			newnode -> next = NULL;
			temp -> next = newnode;
			temp = temp -> next;
		}
	}
	temp = head;
	for(i=0;i<n;i++)
	{
		temp = head;
		while(temp != NULL)
		{
			if(temp -> index == array[i])
			{
				ind = temp -> count;
				result[ind] = temp -> index;
				temp -> count -= 1;
			}
			temp = temp -> next;
		}
	}
	for(i=1;i<n+1;i++)
	{
		array[i-1] = result[i];
	}

	free(head);
	free(temp);
	free(newnode);
}

int getcount(int array[], int x, int n)
{
	int i, count = 0;
	for(i=0;i<n;i++)
	{
		if(array[i] == x)
		{
			count++;
		}
	}
	return count;
}

void bucketsort(int array[], int n)
{
	int bucket[MAX_SIZE][MAX_SIZE], count[MAX_SIZE] = {0}, i, j, k=0, val;
	for(i=0;i<MAX_SIZE;i++)
	{
		for(j=0;j<MAX_SIZE;j++)
		{
			bucket[i][j] = -1;
		}
	}

	for(i=0;i<n;i++)
	{
		val = array[i]/10;
		bucket[val][count[val]] = array[i];
		count[val]++;
	}
	for(i=0;i<n;i++)
	{
		insertionsort(bucket[i],count[i]);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(bucket[i][j] != -1)
			{
				array[k] = bucket[i][j];
				k++;
			}
			else
			{
				break;
			}
		}
	}
}


void radixsort(int array[], int n)
{
	int maxvalue = array[0];
	int bucket[MAX_SIZE][MAX_SIZE], count[MAX_SIZE];
	int i, j, k = 0, p, num_pass = 0, d = 1, q, r;

	for(i=0;i<MAX_SIZE;i++)
	{
		for(j=0;j<MAX_SIZE;j++)
		{
			bucket[i][j] = -1;
		}
	}

	for(i=1;i<n;i++)
	{
		if(maxvalue < array[i])
		{
			maxvalue = array[i];
		}
	}

	while(maxvalue > 0)
	{
		num_pass++;
		maxvalue /= 10;
	}

	for( p = 0 ; p < num_pass ; p++)
	{
		for(i=0;i<MAX_SIZE;i++)
		{
			for(j=0;j<MAX_SIZE;j++)
			{
				bucket[i][j] = -1;
			}
		}

		for(i=0;i<MAX_SIZE;i++)
		{
			count[i] = 0;
		}

		for(i=0;i<n;i++)
		{
			r = (array[i]/d)%10;
			bucket[r][count[r]] = array[i];
			count[r]++;
		}

		for(i=0;i<n;i++)
		{
			internalsort(bucket[i],count[i],d);
		}

		k = 0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<n;j++)
			{
				if(bucket[i][j] != -1)
				{
					array[k] = bucket[i][j];
					k++;
				}
				else
				{
					break;
				}
			}
		}
		d = d*10;
	}

}

void internalsort(int array[], int n, int x)
{
	int c, d, t;
  	for (c=1;c<=n-1;c++) 
  	{
    	d = c;
    	while(d>0 && ((array[d-1]/x)%10) > ((array[d]/x)%10))
    	{
      		t = array[d];
      		array[d] = array[d-1];
      		array[d-1] = t;
      		d--;
    	}
  	}
}

void insertionsort(int array[], int n)
{
	int c, d, t;
  	for (c = 1 ; c <= n - 1; c++) 
  	{
    	d = c;
    	while (d>0 && array[d-1] > array[d]) 
    	{
      		t = array[d];
      		array[d] = array[d-1];
      		array[d-1] = t;
      		d--;
    	}
  	}
}