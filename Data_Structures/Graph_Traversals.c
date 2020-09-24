#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int data;
	struct node *next;
}NODE;

typedef struct Queue
{
	int data;
	struct Queue *next;
}QUEUE;

void insertend(NODE **first, int ele);
void display(NODE *first);
void dfs(NODE *first[], int sv);
void bfs(NODE *first[], int sv);

void enQrear(QUEUE **fr, QUEUE **re, int a);
int deQfront(QUEUE **fr, QUEUE **re);

int visited[10];

int main()
{
	int num, i, j, x, sve, ch;
	
	for(i=0;i<10;i++)
	{
		visited[i] = 0;
	}
	
	NODE *adjoint[10];
	for(i=0;i<10;i++)
	{
		adjoint[i] = NULL;
	}
	printf("Enter Number of Vertices: ");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		while(1)
		{
			printf("Enter Adjacent Node of %d (0 if No vertex left)\n",i);
			scanf("%d",&x);
			if(x != 0)
			{
				insertend(&adjoint[i],x);
			}
			else
			{
				break;
			}			
		}
	}
	printf("\n\nGraph is (Adjacency List):\n");
	for(i=1;i<=num;i++)
	{
		printf("%d: ",i);
		display(adjoint[i]);
		printf("\n");
	}

	menu:
	printf("\nMenu:");
	printf("\n1.Depth First Search\n2.Breadth First Search\n3.End\nEnter Option:");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
				printf("Enter Starting Vertex\n");
				scanf("%d",&sve);
				for(i=0;i<10;i++)
				{
					visited[i] = 0;
				}
				printf("Depth First Search of Graph is: ");
				dfs(adjoint,sve);
				printf("\n");
				goto menu;

		case 2:
				printf("Enter Starting Vertex\n");
				scanf("%d",&sve);
				for(i=0;i<10;i++)
				{
					visited[i] = 0;
				}
				printf("Breadth First Search of Graph is: ");
				bfs(adjoint,sve);
				printf("\n");
				goto menu;

		case 3:
				break;
	}

	return 0;
}

void enQrear(QUEUE **fr, QUEUE **re, int a)
{
	QUEUE *frcpy, *recpy, *newnode;
	frcpy = *fr;
	recpy = *re;
	newnode = (QUEUE *)malloc(sizeof(QUEUE));
	if(recpy == NULL && frcpy == NULL)
	{
		*fr = newnode;
		*re = newnode;
		newnode -> data = a;
		newnode -> next = NULL;
	}
	else
	{
		newnode -> data = a;
		newnode -> next = NULL;
		recpy -> next = newnode;
		recpy = recpy -> next;
		*re = recpy;
	}
}

int deQfront(QUEUE **fr, QUEUE **re)
{
	QUEUE *frcpy;
	frcpy = *fr;
	int x;
	if(frcpy == NULL)
	{
		return 0;
	}
	else
	{
		x = frcpy -> data;
		if(frcpy -> next != NULL)
		{
			*fr = frcpy -> next;
			free(frcpy);
		}
		else
		{
			*fr = NULL;
			*re = NULL;
		}
	}
	return x;
}

void insertend(NODE **first, int ele)
{
	NODE *temp,*p;
	temp=(NODE *)malloc(sizeof(NODE));
	temp -> data = ele;
	temp -> next = NULL;
	if(*first == NULL)
	{
		*first = temp;
	}
	else
	{
		p=*first;
		while(p->next!=NULL)
		{
			p = p -> next;
		}
		p -> next = temp;		
	}
}

void display(NODE *first)
{
	NODE *p;
	p=first;
	while(p!=NULL)
	{
		printf("%d ",p -> data);
		p = p -> next;		
	}
}


void dfs(NODE *first[], int sv)
{
	NODE *ptr;
	ptr = first[sv];
	printf("%d ",sv);
	visited[sv] = 1;	
	while(ptr != NULL)
	{
		if(visited[ptr -> data] == 0)
		{
			dfs(first,ptr->data);
			ptr = ptr -> next;	
		}
		else
		{
			ptr = ptr -> next;	
		}	
	}	
}

void bfs(NODE *first[], int sv)
{
	int a;
	QUEUE *front, *rear;
	NODE *ptr = NULL;
	front = rear = NULL;

	printf("%d ",sv);
	visited[sv] = 1;	
	enQrear(&front,&rear,sv);
	
	while(front != NULL)
	{
		a = deQfront(&front,&rear);
		ptr = first[a];
		while(ptr != NULL)
		{
			if(visited[ptr -> data] == 0)
			{
				printf("%d ",ptr -> data);
				visited[ptr -> data] = 1;
				enQrear(&front,&rear,ptr -> data);
			}
			ptr = ptr -> next;
		}
	}
}
