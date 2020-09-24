#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	char data;
	struct node *next;
	struct node *prev;
}NODE; // Defining the Node structure for Queue Implementation

//Defining Various operations of Queue helpful for program implementation
void enQfront(NODE **fr, NODE **re, char a);  //To Enqueue data from front side
void enQrear(NODE **fr, NODE **re, char a);   //To Enqueue data from rear side
char deQfront(NODE **fr);					  //To Dequeue data from front side and retrun the data
char deQrear(NODE **re);					  //To Dequeue data from rear side and retuen the data
void printQ(NODE **fr, NODE **re);			  //To Print Queue

int main()
{
	NODE *front, *rear;
	int i, len;
	char c1, c2, word[25];

	// Initialising front and rear pointers to null  
	front = NULL;
	rear = NULL;

	// Taking input of word for palindrome checking and calculating the length
	printf("\nEnter a word: ");
	scanf("%s",word);
	len = strlen(word);

	// Storing Each letter of word in queue by enqueue from rear side
	// Could also be done by enqueue from front side by reversing the word 
	for(i=0;i<len;i++)
	{
		enQrear(&front,&rear,word[i]);
	}

	// Printing queue for verification of Above operation
	printf("Entering Data in Queue\n");
	printf("Queue is: ");
	printQ(&front,&rear);

	// Main Logic for palindrome 
	// Dequeue from both sides checking and applying conditions
	i = 0;
	while(1)
	{
		c1 = deQfront(&front);
		c2 = deQrear(&rear);
		if(c1 == c2)
		{
			i++;
			if(i == len/2)
			{
				break;
			}
		}
		else
		{
			break;
		}
	}

	// Verifying palindrome and Printing the result
	if(i == len/2)
	{
		printf("***** Word is a PALINDROME *****\n");
	}
	else
	{
		printf("***** Word is not a PALINDROME *****\n");
	}	

	return 0;
}

void enQfront(NODE **fr, NODE **re, char a)
{
	NODE *frcpy, *recpy, *newnode;
	frcpy = *fr;
	recpy = *re;
	newnode = (NODE *)malloc(sizeof(NODE));
	if(frcpy == NULL)
	{
		*fr = newnode;
		*re = newnode;
		newnode -> data = a;
		newnode -> next = NULL;
		newnode -> prev = NULL;
	}
	else
	{
		newnode -> data = a;
		newnode -> prev = NULL;
		newnode -> next = *fr;
		frcpy -> prev = newnode;
		frcpy = frcpy -> prev;
		*fr = frcpy;
	}
}

void enQrear(NODE **fr, NODE **re, char a)
{
	NODE *frcpy, *recpy, *newnode;
	frcpy = *fr;
	recpy = *re;
	newnode = (NODE *)malloc(sizeof(NODE));
	if(recpy == NULL)
	{
		*fr = newnode;
		*re = newnode;
		newnode -> data = a;
		newnode -> next = NULL;
		newnode -> prev = NULL;
	}
	else
	{
		newnode -> data = a;
		newnode -> next = NULL;
		newnode -> prev = *re;
		recpy -> next = newnode;
		recpy = recpy -> next;
		*re = recpy;
	}
}

char deQfront(NODE **fr)
{
	NODE *frcpy;
	frcpy = *fr;
	char a = '0';

	if(frcpy == NULL)
	{
		printf("Queue is Empty");
		return a;
	}
	else
	{
		if(frcpy -> next != NULL)
		{
			a = frcpy -> data;
			*fr = frcpy -> next;
			free(frcpy);
			frcpy = *fr;
			frcpy -> prev = NULL;
		}
		else
		{
			a = frcpy -> data;
			free(frcpy);
			frcpy = NULL;
		}
		return a;
	}
}

char deQrear(NODE **re)
{
	NODE *recpy;
	recpy = *re;
	char a = '0';
	if(recpy == NULL)
	{
		printf("Queue is Empty");
		return a;
	}
	else
	{
		if(recpy -> prev != NULL)
		{
			a = recpy -> data;
			*re = recpy -> prev;
			free(recpy);
			recpy = *re;
			recpy -> next = NULL;
		}
		else
		{
			a = recpy -> data;
			free(recpy);
			recpy = NULL;
		}
		return a;
	}
}

void printQ(NODE **fr, NODE **re)
{
	NODE *temp1, *temp2;
	temp1 = *fr;
	temp2 = *re;
	if(temp1 != NULL || temp2 != NULL)
	{
		while(temp1 != NULL) 
		{
			printf("%c",temp1 -> data);
			temp1 = temp1 -> next;
		}
		printf("\n");
	}
	else
	{
		printf("List is Empty\n");
	}
}

