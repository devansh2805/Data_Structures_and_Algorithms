#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}Tnode;

void inorder(Tnode *t);
void postorder(Tnode *t);
void preorder(Tnode *t);
void insert(Tnode **t, int ele);
int Findmin(Tnode *t);
int Findmax(Tnode *t);
void Findkmin(Tnode *t, int x);
void deleten(Tnode **t, int ele);
Tnode *search(Tnode *t, int ele);
Tnode *searchparent(Tnode *t, int ele);
int flag = 0;

int main()
{
	Tnode *root, *keyele;
	root = NULL;
	keyele = NULL;
	int i, x, n, key, delkey, k, in=0;

	printf("Enter Number of Entries: ");
	scanf("%d",&n);
	printf("Enter Data: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(&root,x);
	}

	printf("\nPrinting in INORDER format: ");
	inorder(root);
	printf("\nPrinting in PREORDER format: ");
	preorder(root);
	printf("\nPrinting in POSTORDER format: ");
	postorder(root);
	printf("\n");

	printf("\nMinimum value in tree is: %d", Findmin(root));
	printf("\nMaximum value in tree is: %d", Findmax(root));
	printf("\nEnter value of k: ");
	scanf("%d",&k);
	Findkmin(root,k);

	printf("\n\nEnter Element to be searched: ");
    scanf("%d",&key);
    keyele = search(root,key);
    if( keyele == NULL )
    {
        printf("Key Not Found in Binary Search Tree\n");
    }
    else
    {
            printf("Key Found in Binary Search Tree\n");
    }

    printf("\nEnter Element to be Deleted: ");
    scanf("%d",&delkey);
    if(	search(root,delkey) != NULL	)
    {
            deleten(&root, delkey);
            printf("\nPrinting in INORDER format after deleting %d: ",delkey);
            inorder(root);
            printf("\nPrinting in PREORDER format after deleting %d: ",delkey);
            preorder(root);
            printf("\nPrinting in POSTORDER format after deleting %d: ",delkey);
            postorder(root);
            printf("\n\n");
    }
    else
    {
        printf("Key Not Found in Binary Search Tree!! Cannot be Deleted\n");
    }

return 0;
}

void insert(Tnode **t, int ele)
{
	Tnode *newnode;
	newnode = (Tnode *)malloc(sizeof(Tnode));
	newnode -> data = ele;
	newnode -> lchild = NULL;
	newnode -> rchild = NULL;

	if(*t == NULL)
	{
		*t = newnode;
	}
	else
	{
		Tnode *p, *q;
		q =*t;
		p =*t;

		while(p != NULL)
		{
			if(p -> data <= ele)
			{
				q = p;
				p = p -> rchild;
			}
			else
			{
				q = p;
				p = p -> lchild;
			}
		}

		if(q -> data <= ele)
		{
			q -> rchild = newnode;
		}
		else
		{
			q -> lchild = newnode;
		}
	}
}

void Findkmin(Tnode *t, int x)
{
	if(t!=NULL)
	{
		Findkmin(t -> lchild,x);
		flag++;
		if(flag == x)
		{
			printf("Kth Smallest is: %d",t -> data);
		}
		Findkmin(t -> rchild,x);
	}
}

int Findmin(Tnode *t)
{
	if(t == NULL)
	{
		return -1;
	}
	else if(t -> lchild == NULL)
	{
		return t -> data;
	}
	else
	{
		return Findmin(t -> lchild);
	}
}

int Findmax(Tnode *t)
{
	if(t == NULL)
	{
		return -1;
	}
	else if(t -> rchild == NULL)
	{
		return t -> data;
	}
	else
	{
		return Findmax(t -> rchild);
	}
}

Tnode *search(Tnode *t, int ele)
{
	if(t == NULL)
	{
		return NULL;
	}
	else if(t -> data == ele)
	{
		return t;
	}
	else if(t -> data > ele)
	{
		return search(t -> lchild, ele);
	}
	else if(t -> data < ele)
	{
		return search(t -> rchild, ele);
	}
}

Tnode *searchparent(Tnode *t, int ele)
{

	if(t -> lchild != NULL && t -> lchild -> data == ele)
	{
		return t;
	}
	else if(t -> rchild != NULL && t -> rchild -> data == ele)
	{
		return t;
	}
	if(t -> data > ele)
	{
		return searchparent(t -> lchild, ele);
	}
	else if(t -> data <= ele)
	{
		return searchparent(t -> rchild, ele);
	}
}

void deleten(Tnode **t, int ele)
{
	Tnode *sr=NULL, *srp=NULL, *temp=NULL, *ins=NULL;
	temp = *t;
	ins = NULL;
	sr = search(temp,ele);

	if(sr == *t)
	{
		int x;
	    if(sr -> rchild != NULL)
        {
            ins = sr -> rchild;
            while(ins -> lchild != NULL)
            {
                ins = ins -> lchild;
            }
            x = ins -> data;
            deleten(t,x);
            sr -> data = x;
            return;
        }
        else
        {
        	if(sr -> lchild != NULL)
        	{
            	ins = sr -> lchild;
            	while(ins -> rchild != NULL)
            	{
                	ins = ins -> rchild;
            	}
            	x = ins -> data;
            	deleten(t,x);
            	sr -> data = x;
            	return;
            }
        }
	}

	else if( (sr -> lchild == NULL) && (sr -> rchild == NULL) )
	{
        srp = searchparent(temp,ele);
		if(srp -> lchild  == sr)
		{
			srp -> lchild = NULL;
		}
		else if(srp -> rchild == sr)
		{
			srp -> rchild = NULL;
		}
		free(sr);
		return;
	}

	else if(((sr -> lchild != NULL)&&(sr -> rchild == NULL))||((sr -> lchild == NULL)&&(sr -> rchild != NULL)))
	{
        srp = searchparent(temp,ele);
		if(srp -> lchild  == sr && sr -> lchild != NULL)
		{
			srp -> lchild = sr -> lchild;
		}

		else if(srp -> lchild  == sr && sr -> rchild != NULL)
		{
			srp -> lchild = sr -> rchild;
		}

		else if(srp -> rchild  == sr && sr -> lchild != NULL)
		{
			srp -> rchild = sr -> lchild;
		}

		else if(srp -> rchild  == sr && sr -> rchild != NULL)
		{
			srp -> rchild = sr -> rchild;
		}
		free(sr);
		return;
	}

	else if(sr -> lchild != NULL && sr -> rchild != NULL)
	{
		int x;
        ins = sr -> rchild;
        if(ins -> lchild != NULL)
        {
        	while(ins -> lchild != NULL)
        	{
            	ins = ins -> lchild;
        	}
        }

        x = ins -> data;
        deleten(t,x);
        sr -> data = x;
        return;
	}
}

void inorder(Tnode *t)
{
	if(t!= NULL)
	{
		inorder(t -> lchild);
		printf("%d ",t -> data);
		inorder(t -> rchild);
	}
}

void preorder(Tnode *t)
{
	if(t!= NULL)
	{
		printf("%d ",t -> data);
		preorder(t -> lchild);
		preorder(t -> rchild);
	}
}

void postorder(Tnode *t)
{
	if(t!= NULL)
	{
		postorder(t -> lchild);
		postorder(t -> rchild);
		printf("%d ",t -> data);
	}
}
