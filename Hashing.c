#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

int hash(int value, int no);						//Hash Function
int rehash(int ind, int k, int n);					//Rehash Function
void insertl(int ar[], int value, int no);			//Insertion using Linear Probing
void insertq(int ar[], int value, int no);			//Insertion using Quadratic Probing
void search(int ar[], int key, int no);				//Searching Element using Linear Probing
int collisionl = 0, collisionq = 0;

int main()
{
    int hash1[MAX_SIZE], hash2[MAX_SIZE], n, i, val, ele;
    //Initializing array values
    for(i=0;i<MAX_SIZE;i++)
    {
        hash1[i] = -1;
        hash2[i] = -1;
    }

    printf("Enter number of values: ");
    scanf("%d",&n);
    printf("Enter the values: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        insertl(hash1,val,n);
        insertq(hash2,val,n);
    }

    printf("\nLinear Probing:\n");
    printf("The elements inserted are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",hash1[i]);
    }
    printf("\nTotal Collisions: %d",collisionl);

    printf("\n\nQuadratic probing:\n");
    printf("The elements inserted are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",hash2[i]);
    }
    printf("\nTotal Collisions: %d\n",collisionq);

    printf("\nEnter the element to be searched: ");
    scanf("%d",&ele);
    search(hash1,ele,n);

    return 0;
}

int hash(int value,int no)
{
    int ind;
    ind = value % no;
    return ind;
}

int rehash(int ind, int k, int n)
{
    ind = (ind + k) % n;
    return ind;
}

void insertl(int ar[], int value, int no) //Linear Probing
{
    int index , count = 0;
    index = hash(value,no);

    if(ar[index] == -1)
    {
        ar[index] = value;
    }
    else
    {
        while(count != no)
        {
        	collisionl++;
            index = rehash(index,1,no);
            if(ar[index] == -1)
            {
                break;
            }
            count++;
        }
        ar[index] = value;
    }
}

void insertq(int ar[],int value,int no) //Quadratic Probing
{
    int index, ind, count=1;
    index = hash(value,no);
    if( ar[index] == -1)
    {
        ar[index] = value;
    }
    else
    {
        ind = index;
        while(1)
        {
        	collisionq++;
            index = rehash(ind,((count)*(count)),no);
            if(ar[index] == -1)
            {
                break;
            }
            count++;
        }
        ar[index] = value;
    }
}

void search(int ar[], int key, int no)//Search by linear probing
{
   int ind, count=0, flag=0;
   ind = hash(key,no);

   if(ar[ind] == key)
   {
        flag = 1;
        printf("Element found at index %d\n",ind);
   }
   else
   {
        while(count != no)
        {
            ind = rehash(ind,1,no);

            if(ar[ind] == key)
            {
                flag=1;
                printf("Element found at index %d\n",ind);
                break;
            }
            count++;
        }
   } 
   if(flag == 0)
   {
		printf("Element not found!\n");
   }
}