#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

void create(NODE **first, int n);
void reverse(NODE **first);
void display(NODE *first);
void intersection(NODE **first, NODE **second, NODE **third);
void concatenate(NODE **first, NODE **second);
int presence(NODE **third, int c);

int main()
{
	NODE *head1, *head2, *head3;
	int n1, n2;

	head1 = NULL;
	head2 = NULL;
	head3 = NULL;

	printf("Enter Number of Elements in List 1 : ");
	scanf("%d",&n1);
	create(&head1,n1);

	printf("\nEnter Number of Elements in List 2 : ");
	scanf("%d",&n2);
	create(&head2,n2);
	printf("\n\n");

	printf("\nFirst Linked List is : ");
	display(head1);
	printf("\nSecond Linked List is: ");
	display(head2);

	intersection(&head1, &head2, &head3);
	printf("\nIntersection of the Linked List's is : ");
	display(head3);

	concatenate(&head1, &head2);
	printf("\nConcatenation of the Linked List's is : ");
	display(head1);

	reverse(&head1);
	printf("\nReverse of Concatenated List is: ");
	display(head1);

	return 0;
}

void display(NODE *first)
{
	NODE *p;
	p = first;
	while(p != NULL)
	{
		printf("%d ",p -> data);
		p = p -> next;
	}
	printf("\n");
}

void create(NODE **first, int n)
{
	NODE *temp, *newnode;
	int d,i;
	temp = (NODE *)malloc(sizeof(NODE));
	for(i=0;i<n;i++)
	{
		newnode = (NODE *)malloc(sizeof(NODE));
		if(i==0)
		{
			printf("Enter 1st Value: ");
			scanf("%d",&d);
			temp -> data = d;
			temp -> next = NULL;
			*first = temp;
		}
		else
		{
			if(i==1)
			{
				printf("Enter 2nd Value: ");
				scanf("%d",&d);
			}
			else
			{
				if(i==2)
				{
					printf("Enter 3rd Value: ");
					scanf("%d",&d);
				}
				else
				{
					printf("Enter %dth Value: ",i+1);
					scanf("%d",&d);
				}
			}
			newnode -> data = d;
			newnode -> next = NULL;

			temp -> next = newnode;
			temp = temp -> next;
		}
	}
}

void intersection(NODE **first, NODE **second, NODE **third)
{
	NODE *p, *q, *Newnode, *temp;
	int x;
	p = *first;
	q = *second;
	temp = NULL;
	while(p != NULL)
	{
		while(q != NULL)
		{
			if( p -> data == q -> data )
			{
				if(temp == NULL)
				{
					temp = (NODE *)malloc(sizeof(NODE));
					temp -> data = p -> data;
					temp -> next = NULL;
					*third = temp;
					q = q -> next;
				}
				else
				{
					Newnode = (NODE *)malloc(sizeof(NODE));
					x = presence(third, p-> data);
					if(x==1)
					{ 
						Newnode -> data = p -> data;
						Newnode -> next = NULL;
						temp -> next = Newnode;
						temp = temp -> next;
					}
					q = q -> next;
				}
			}
			else
			{
				q = q -> next;
			}
		}
		q = *second;
		p = p -> next;
	}
}

void reverse(NODE **first)
{
	NODE *current, *p, *revhead;
	revhead = NULL;
	current = *first;
	p = *first;
	while(current != NULL)
	{
		current = current -> next;
		p -> next = revhead;
		revhead = p;
		p = current;
	}
	*first = revhead;
}

void concatenate(NODE **first, NODE **second)
{
	NODE *p;
	p = *first;
	if(p == NULL)
	{
		p -> next = *second;
	}
	else
	{
		while(p-> next != NULL)
		{
			p = p -> next;
		}
		p -> next = *second;
	}
}

int presence(NODE **third, int c)
{
	NODE *p;
	p = *third;
	while(p != NULL)
	{
		if( p-> data == c)
		{
			return 0;
		}
		p = p-> next;
	}
	return 1;
}









