#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct node
{
	char data;
	int value;
	struct node *next;
}STACK;

void infix_to_postfix(char exp1[], char exp2[], STACK **first);
int prec_stack(char ch);
void push(char ch, STACK **first);
char pop(STACK **first);
void pushvalue(int c, STACK **first);
int popvalue(STACK **first);
void char_to_value(char exp[]);
int evaluate(char exp[], STACK **first);

int main()
{
	int answer;
	char infix_exp[50], postfix_exp[50];
	STACK *head;
	head = NULL;

	printf("Enter Infix Expression: ");
	scanf("%s",infix_exp);
	infix_to_postfix(infix_exp, postfix_exp, &head);

	printf("\nPostfix Expression is: %s\n\n",postfix_exp);
	char_to_value(postfix_exp);

	printf("\nPostfix Expression after putting values is: %s",postfix_exp);

	answer = evaluate(postfix_exp,&head);
	printf("\nEvaluating Postfix Expression.......");
	printf("\nFinal Answer: %d",answer);
	free(head);
	return 0;
}

void infix_to_postfix(char exp1[], char exp2[], STACK **first)
{
	char a, b;
	int i = 0, j = 0, k = 0, z, checktop, checkpre;
	STACK *temp;
	temp = *first;
	while(exp1[i] != '\0')
	{
		if( (exp1[i] >= 65 && exp1[i] <= 90) || (exp1[i] >= 97 && exp1[i] <= 122))
		{
			exp2[j] = exp1[i];
			j++;
		}

		else if( (exp1[i]=='+') || (exp1[i]=='-') || (exp1[i]=='*') || (exp1[i]=='/') || (exp1[i]=='%') || (exp1[i]=='^') ) 
		{
			if( temp != NULL)
			{
				a = temp -> data;
				checktop = prec_stack(a);
			}
			else
			{
				checktop = -1;
			}
			checkpre = prec_stack(exp1[i]);

			while(checkpre < checktop)
			{
				exp2[j] = pop(first);
				j++;
				temp = *first;
				if( temp != NULL)
				{
					a = temp -> data;
					checktop = prec_stack(a);
				}
				else
				{
					checktop = -1;
				}
				checkpre = prec_stack(exp1[i]);
			}
			
			if( checkpre > checktop)
			{
				push(exp1[i], first);
			}
			else if( checkpre == checktop)
			{
				exp2[j] = pop(first);
				temp = *first;
				push(exp1[i],first);
				j++;
			}
		}

		else if(exp1[i] == '(')
		{
			push(exp1[i],first);
		}

		else if(exp1[i] == ')')
		{
			while( temp -> data != '(')
			{
				exp2[j] = pop(first);
				j++;
				temp = *first;
			}
			b = pop(first);
		}

		temp = *first;
		i++;
	}
	while(temp != NULL)
	{
		exp2[j]=pop(first);
		j++;
		temp = *first;
	}
	exp2[j]='\0';
}

void push(char ch, STACK **first)
{
	STACK *newnode;
	newnode = (STACK *)malloc(sizeof(STACK));
	newnode -> data = ch;
	newnode -> next = *first;
	*first = newnode;
}

void pushvalue(int c, STACK **first)
{
	STACK *newnode;
	newnode = (STACK *)malloc(sizeof(STACK));
	newnode -> value = c;
	newnode -> next = *first;
	*first = newnode;
}

int popvalue(STACK **first)
{
	int val;
	STACK *newnode;
	newnode = *first;
	val = newnode -> value;
	newnode = newnode -> next;
	*first = newnode;
	return val;
}

char pop(STACK **first)
{
	char x;
	STACK *ptr;
	ptr = *first;
	x = ptr -> data;
	ptr = ptr -> next;
	*first = ptr;
	return x;	
}

void char_to_value(char exp[])
{
	int i = 0, x;
	while(exp[i] != '\0')
	{
		if( (exp[i] >= 65 && exp[i] <= 90) || (exp[i] >= 97 && exp[i] <= 122) )
		{
			printf("Enter Value of %c (0 to 9) : ",exp[i]);
			scanf("%d",&x);
			exp[i] = (char)x + '0';
		}
		i++;
	}
}

int prec_stack(char ch)
{
	if(ch == '(')
	{
		return 0;
	}
	else if( (ch == '+') || (ch == '-') )
	{
		return 1;
	}
	else if( (ch == '*') || (ch == '/') || (ch == '%') )
	{
		return 2;
	}
	else if(ch == '^')
	{
		return 3;
	}
}

int evaluate(char exp[], STACK **first)
{
	int a;
	a = (int)exp[0]-'0';
	pushvalue(a,first);
	int i = 1;
	int x, y, z;
	while(exp[i] != '\0')
	{
		if ( (exp[i] >= 40) && (exp[i] <= 47) || exp[i] == '^' || exp[i] == '%' )
		{
			y = popvalue(first);
			x = popvalue(first);
			if(exp[i] == '+')
			{
				z = (x+y);
			}
			else if( exp[i] == '-')
			{
				z = (x-y);
			}
			else if( exp[i] == '*')
			{
				z = (x*y);
			}
			else if( exp[i] == '/')
			{
				z = (x/y);
			}
			else if( exp[i] == '%')
			{
				z = (x%y);
			}
			else if( exp[i] == '^')
			{
				z = pow(x,y);
			}
			pushvalue(z,first); 
		}
		else if( (exp[i] >= 48) && (exp[i] <= 57))
		{
			a = (int)exp[i]-'0';
			pushvalue(a,first);
		}
		i++;
	}
	return popvalue(first);
}