#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int coeff;
	int x;
	int y;
	int z;
	struct node *next;
}NODE;

void create(NODE **first, int n);
void display(NODE *first);
void polyadd(NODE **first, NODE **second, NODE **third);
void polysub(NODE **first, NODE **second, NODE **third);

int main()
{

	NODE *head1, *head2, *head3, *head4;
	int n1, n2;

	head1 = NULL;
	head2 = NULL;
	head3 = NULL;
	head4 = NULL;

	printf("Enter Number of Elements in Polynomial 1 : ");
	scanf("%d",&n1);
	create(&head1,n1);

	printf("\nEnter Number of Elements in Polynomial 2 : ");
	scanf("%d",&n2);
	create(&head2,n2);

	printf("\n\nFirst Polynomial is : ");
	display(head1);
	printf("\n\nSecond Polynomial is: ");
	display(head2);

	printf("\n\nAddition of Both Polynomials is : ");
	polyadd(&head1,&head2,&head3);
	display(head3);

	printf("\n\nSubtraction of Both Polynomials is : ");
	polysub(&head1,&head2,&head4);
	display(head4);

	free(head1);
	free(head2);
	free(head3);
	free(head4);
	return 0;
}

void create(NODE **first, int n)
{
	NODE *temp, *newnode;
	int c,d1,d2,d3,i;
	temp = (NODE *)malloc(sizeof(NODE));
	for(i=0;i<n;i++)
	{
		newnode = (NODE *)malloc(sizeof(NODE));
		if(i==0)
		{
			printf("Enter Coefficient of 1st term: ");
			scanf("%d",&c);
			temp -> coeff = c;
			printf("Enter Power of x: ");
			scanf("%d",&d1);
			temp -> x = d1;
			printf("Enter Power of y: ");
			scanf("%d",&d2);
			temp -> y = d2;
			printf("Enter Power of z: ");
			scanf("%d",&d3);
			temp -> z = d3;
			temp -> next = NULL;
			*first = temp;
		}
		else
		{
			if(i==1)
			{
				printf("Enter Coefficient of 2nd term: ");
				scanf("%d",&c);
				printf("Enter Power of x: ");
				scanf("%d",&d1);
				printf("Enter Power of y: ");
				scanf("%d",&d2);
				printf("Enter Power of z: ");
				scanf("%d",&d3);
			}
			else
			{
				if(i==2)
				{
					printf("Enter Coefficient of 3rd term: ");
					scanf("%d",&c);
					printf("Enter Power of x: ");
					scanf("%d",&d1);
					printf("Enter Power of y: ");
					scanf("%d",&d2);
					printf("Enter Power of z: ");
					scanf("%d",&d3);
				}
				else
				{
					printf("Enter Coefficient of %dth term: ",i+1);
					scanf("%d",&c);
					printf("Enter Power of x: ");
					scanf("%d",&d1);
					printf("Enter Power of y: ");
					scanf("%d",&d2);
					printf("Enter Power of z: ");
					scanf("%d",&d3);
				}
			}
			newnode -> coeff = c;
			newnode -> x = d1;
			newnode -> y = d2;
			newnode -> z = d3;
			newnode -> next = NULL;
			temp -> next = newnode;
			temp = temp -> next;
		}
	}
}

void display(NODE *first)
{
	NODE *p;
	p = first;
	while(p != NULL)
	{	
		if(p -> coeff > 0)
		{
			printf(" +%dx^%dy^%dz^%d ",p->coeff,p->x,p->y,p->z);
		}	
		if(p -> coeff < 0)
		{
			printf(" %dx^%dy^%dz^%d ",p->coeff,p->x,p->y,p->z);
		}
		p = p -> next;
	}
	printf("\n");
}

void polyadd(NODE **first, NODE **second, NODE **third)
{
	NODE *p, *q, *temp, *final;
	p = *first;
	q = *second;

	temp = (NODE *)malloc(sizeof(NODE));
	temp -> coeff = 0 ;
	temp -> x = 0 ;
	temp -> y = 0 ;
	temp -> z = 0 ;
	temp -> next = NULL;
	*third = temp;

	while( p != NULL && q != NULL )
	{
		final = (NODE *)malloc(sizeof(NODE));
		if( p -> x == q -> x )
		{
			if( p -> y == q -> y )
			{
				if( p -> z == q -> z )
				{
					final -> coeff = (p -> coeff) + (q -> coeff);
					final -> x = p -> x;
					final -> y = p -> y;
					final -> z = p -> z;
					final -> next = NULL;
					temp -> next = final;
					temp = temp -> next;
					p = p -> next;
					q = q -> next;
				}
				else
				{
					if(p -> z > q -> z)
					{
						final -> coeff = (p -> coeff);
						final -> x = p -> x;
						final -> y = p -> y;
						final -> z = p -> z;
						final -> next = NULL;
						temp -> next = final;
						temp = temp -> next;
						p = p -> next;
					}
					else
					{
						final -> coeff = (q -> coeff);
						final -> x = q -> x;
						final -> y = q -> y;
						final -> z = q -> z;
						final -> next = NULL;
						temp -> next = final;
						temp = temp -> next;
						q = q -> next;
					}
				}
			}
			else
			{
				if(p -> y > q -> y)
				{
					final -> coeff = (p -> coeff);
					final -> x = p -> x;
					final -> y = p -> y;
					final -> z = p -> z;
					final -> next = NULL;
					temp -> next = final;
					temp = temp -> next;
					p = p -> next;
				}
				else
				{
					final -> coeff = (q -> coeff);
					final -> x = q -> x;
					final -> y = q -> y;
					final -> z = q -> z;
					final -> next = NULL;
					temp -> next = final;
					temp = temp -> next;
					q = q -> next;
				}
			}
		}
		else
		{
			if(p -> x > q -> x)
			{
				final -> coeff = (p -> coeff);
				final -> x = p -> x;
				final -> y = p -> y;
				final -> z = p -> z;
				final -> next = NULL;
				temp -> next = final;
				temp = temp -> next;
				p = p -> next;
			}
			else
			{
				final -> coeff = (q -> coeff);
				final -> x = q -> x;
				final -> y = q -> y;
				final -> z = q -> z;
				final -> next = NULL;
				temp -> next = final;
				temp = temp -> next;
				q = q -> next;
			}
		}
	}
	while(p != NULL)
	{
		final = (NODE *)malloc(sizeof(NODE));
		final -> coeff = (p -> coeff);
		final -> x = p -> x;
		final -> y = p -> y;
		final -> z = p -> z;
		final -> next = NULL;
		temp -> next = final;
		temp = temp -> next;
		p = p -> next;
	}
	while(q != NULL)
	{
		final = (NODE *)malloc(sizeof(NODE));
		final -> coeff = (q -> coeff);
		final -> x = q -> x;
		final -> y = q -> y;
		final -> z = q -> z;
		final -> next = NULL;
		temp -> next = final;
		temp = temp -> next;
		q = q -> next;

	}
}

void polysub(NODE **first, NODE **second, NODE **third)
{
	NODE *p, *q, *temp, *final;
	p = *first;
	q = *second;

	temp = (NODE *)malloc(sizeof(NODE));
	temp -> coeff = 0 ;
	temp -> x = 0 ;
	temp -> y = 0 ;
	temp -> z = 0 ;
	temp -> next = NULL;
	*third = temp;

	while( p != NULL && q != NULL )
	{
		final = (NODE *)malloc(sizeof(NODE));
		if( p -> x == q -> x )
		{
			if( p -> y == q -> y )
			{
				if( p -> z == q -> z )
				{
					final -> coeff = (p -> coeff) - (q -> coeff);
					final -> x = p -> x;
					final -> y = p -> y;
					final -> z = p -> z;
					final -> next = NULL;
					temp -> next = final;
					temp = temp -> next;
					p = p -> next;
					q = q -> next;
				}
				else
				{
					if(p -> z > q -> z)
					{
						final -> coeff = (p -> coeff);
						final -> x = p -> x;
						final -> y = p -> y;
						final -> z = p -> z;
						final -> next = NULL;
						temp -> next = final;
						temp = temp -> next;
						p = p -> next;
					}
					else
					{
						final -> coeff = -(q -> coeff);
						final -> x = q -> x;
						final -> y = q -> y;
						final -> z = q -> z;
						final -> next = NULL;
						temp -> next = final;
						temp = temp -> next;
						q = q -> next;
					}
				}
			}
			else
			{
				if(p -> y > q -> y)
				{
					final -> coeff = (p -> coeff);
					final -> x = p -> x;
					final -> y = p -> y;
					final -> z = p -> z;
					final -> next = NULL;
					temp -> next = final;
					temp = temp -> next;
					p = p -> next;
				}
				else
				{
					final -> coeff = -(q -> coeff);
					final -> x = q -> x;
					final -> y = q -> y;
					final -> z = q -> z;
					final -> next = NULL;
					temp -> next = final;
					temp = temp -> next;
					q = q -> next;
				}
			}
		}
		else
		{
			if(p -> x > q -> x)
			{
				final -> coeff = (p -> coeff);
				final -> x = p -> x;
				final -> y = p -> y;
				final -> z = p -> z;
				final -> next = NULL;
				temp -> next = final;
				temp = temp -> next;
				p = p -> next;
			}
			else
			{
				final -> coeff = -(q -> coeff);
				final -> x = q -> x;
				final -> y = q -> y;
				final -> z = q -> z;
				final -> next = NULL;
				temp -> next = final;
				temp = temp -> next;
				q = q -> next;
			}
		}
	}
	while(p != NULL)
	{
		final = (NODE *)malloc(sizeof(NODE));
		final -> coeff = (p -> coeff);
		final -> x = p -> x;
		final -> y = p -> y;
		final -> z = p -> z;
		final -> next = NULL;
		temp -> next = final;
		temp = temp -> next;
		p = p -> next;
	}
	while(q != NULL)
	{
		final = (NODE *)malloc(sizeof(NODE));
		final -> coeff = -(q -> coeff);
		final -> x = q -> x;
		final -> y = q -> y;
		final -> z = q -> z;
		final -> next = NULL;
		temp -> next = final;
		temp = temp -> next;
		q = q -> next;

	}
}

























