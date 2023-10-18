#include<stdio.h>
#include<conio.h>
#include<malloc.h>
//#include<alloc.h>
#include<stdlib.h>
typedef struct Dlinklist
{
	int num;
	struct Dlinklist *prev;
	struct Dlinklist *next;	
}Node;

Node *start;

void insert();
void display();
void del();
void edit();
void count();
void sort();
void reverse();
void exit();
void atbeg();
void atbeg1();
void atend();
void atend1();
void before();
void before1();
void after();
void after1();
void atpos();
void atpos1();

int main()
{
	int ch1;
	char choice1 = 'y';
	start = NULL;
	system("cls");	
	do
	{
		printf("\n\n ##### Doubly LinkList Project #####\n");
		printf("\n 1. INSERT     ");
		printf("\n 2. DISPLAY    ");
		printf("\n 3. DELETE     ");
		printf("\n 4. EDIT       ");
		printf("\n 5. COUNT NODES");
		printf("\n 6. SORTING    ");
		printf("\n 7. REVERSE    ");
		printf("\n 8. EXIT       ");
		printf("\n\n Enter Your Choice = ");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				del();
				break;
			case 4:
				edit();
				break;
			case 5:
				count();
				break;
			case 6:
				sort();
				break;
			case 7:
				reverse();
				break;
			case 8:
				choice1 = 'n';
				break;
			default:
				printf("invalid choice");
		}
	}
	while(choice1 == 'y');
	return 0;
}

void insert()
{
	int ch2;
	char choice2;
	do
	{
		printf("\n 1. ATBEG");
		printf("\n 2. ATEND");
		printf("\n 3. BEFORE");
		printf("\n 4. AFTER");
		printf("\n 5. ATPOS1");
		printf("\n 6. EXIT");
		printf("\n\n Enter Your Choice = ");
		scanf("%d",&ch2);
		switch(ch2)
		{
			case 1:
				atbeg();
				break;
			case 2:
				atend();
				break;
			case 3:
				before();
				break;
			case 4:
			    after();
				break;
			case 5:
				atpos();
				break;
			case 6:
				choice2 = 'n';
				break;
			default:
				printf("invalid choice");
		}   
	}
	while(choice2 == 'y');
}

void atbeg()
{
	Node *temp,*node;
	node = (Node*)malloc(sizeof(Node));
    printf("\n\n Enter a no.");
    scanf("%d",&node->num);
    node->next = NULL;
    node->prev = NULL;
    if(start == NULL)
    {
    	start = node;
    	return;
	}
	else
	{
		temp = start;
		start = node;
		node->next = temp;
		temp->prev = node;
	}
}

void display()
{
	Node *temp;
	temp = start;
	while(temp != NULL)
	{
		printf("<--%d-->",temp->num);
		temp = temp->next;
	}
}

void atend()
{
	Node *temp,*node;
	node = (Node*)malloc(sizeof(Node));
	printf("\n\n Enter a no.");
	scanf("%d",&node->num);
    node->next = NULL;
    node->prev = NULL;
    if(start == NULL)
    {
    	start = node;
    	return;
	} 
	temp = start;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
}

void before()
{
	int val;
	Node *temp,*temp1,*node;
	printf("\n Before which node you want to insert = ");
	scanf("%d",&val);
	node = (Node*)malloc(sizeof(Node));
	printf("Enter the data of node");
	scanf("%d",&node->num);
	node->next = NULL;
	temp = start;
	while(temp->num != val);
	{
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = node;
	node->next = temp;
}

void count()
{
	int count = 0;
	Node *temp;
	temp = start;
	while(temp != NULL)
	{
		count = count + 1;
		temp = temp->next;
	}
	printf("\n\n The total numbers of nodes are = %d",count);
}

void after()
{
	int val;
	Node *temp,*temp1,*node;
	printf("\n After which node you want to insert = ");
	scanf("%d",&val);
	node = (Node*)malloc(sizeof(Node));
	printf("Enter the data of node : ");
	scanf("%d",&node->num);
	node->next = NULL;
	temp = start;
	while(temp->num != val)
	{
		//temp1 = temp;
		temp = temp->next;
	}
	//temp1 = temp;
	node->next = temp->next;
	temp->next = node;
}

void atpos()
{
	int i = 1,c = 0,n;
	Node *temp,*temp1,*node;
	printf("enter the position number = ");
	scanf("%d",&n);
	node = (Node*)malloc(sizeof(Node));
	printf("\n\n Enter the data of node : ");
	scanf("%d",&node->num);
	node->next = NULL;
	temp = start;
	while(temp != NULL)
	{
		c = c + 1;
		temp = temp->next;
	}
	if(n>c);
	{
		printf("\n Not valid");
		return;
	}
	temp = start;
	while(i<n)
	{
		i = i + 1;
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = node;
	node->next = temp;
}

void edit()
{
	int i = 1,count = 0,pos,num1;
	Node *temp;
	printf("\n Enter the position of node for edit = ");
	scanf("%d",&pos);
	printf("\n\n Enter the data of new node : ");
	scanf("%d",&num1);
	temp = start;
	while(temp != NULL)
	{
		count = count + 1;
		temp = temp->next;
	}
	if(pos>count)
	{
		printf("\n Not valid");
		return;
	}
	temp = start;
	while(i<pos)
	{
		i = i + 1;
		temp = temp->next;
	}
	temp->num = num1;
}

void del()
{
	int ch3;
	char choice3;
	do
	{
		printf("\n 1. ATBEG");
		printf("\n 2. ATEND");
		printf("\n 3. BEFORE");
		printf("\n 4. AFTER");
		printf("\n 5. ATPOS1");
		printf("\n 6. GO BACK");
		printf("\n\n Enter Your Choice = ");
		scanf("%d",&ch3);
		switch(ch3)
		{
			case 1:
				atbeg1();
				break;
			case 2:
				atend1();
				break;
			case 3:
				before1();
				break;
			case 4:
				after1();
				break;
			case 5:
				atpos1();
				break;
			case 6:
				choice3 = 'n';
				break;
			default:
				printf("\n\n invalid choice");
		}
	}
	while(choice3 == 'y');	
}

void atbeg1()
{
	Node *temp;
	temp = start;
	start = start->next;
	temp->next = NULL;
	free(temp);
}

void atend1()
{
	Node *temp,*temp1;
	temp = start;
	while(temp->next != NULL)
	{
		temp1 = temp;
		temp = temp->next; 
	}
	temp1->next = NULL;
	free(temp);
}

void before1()
{
	int i;
	Node *temp,*temp1,*temp2;
	printf("\n Before which node you want to delete = ");
	scanf("%d",&i);
	temp = start;
	temp1 = temp->next;
	temp2 = temp1->next;
	while(temp2->num != i)
	{
		temp = temp->next;
		temp1 = temp->next;
		temp2 = temp1->next;
	}
	temp->next = temp2;
	temp1->next = NULL;
	free(temp1);
}

void after1()
{
	int i;
	Node *temp,*temp1,*temp2;
	printf("\n After which node you want to delete = ");
	scanf("%d",&i);
	temp = start;
	temp1 = temp->next;
	temp2 = temp1->next;
	while(temp->num != i)
	{
		temp = temp->next;
		temp1 = temp->next;
	    temp2 = temp1->next;
	}
	temp->next = temp2;
	temp1->next = NULL;
	free(temp1);
}

void atpos1()
{
	int i,c = 0,n;
	Node *temp,*temp1;
	printf("Enter the position of number = ");
	scanf("%d",&n);
	temp = start;
	while(temp != NULL)
	{
		c = c + 1;
		temp = temp->next;
	}
	if(n>c)
	{
		printf("Not valid");
		return;
	}
	temp = start;
	while(i<n)
	{
		i = i + 1;
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = temp->next;
	temp->next = NULL;
	free(temp);
}

void reverse()
{
	Node *ptr,*temp,*old;
	temp = start;
	ptr = NULL;
	while(temp != NULL)
	{
		old = ptr;
		ptr = temp;
		temp = temp->next;
		ptr->next = old;
	}
	start = ptr;
}

void sort()
{
	int n;
	Node *temp,*temp1;
	temp = start;
	while(temp == start)
	while(temp != NULL)
	{
		temp1 = temp->next;
		while(temp1 != NULL)
		{
			if(temp->num>temp1->num)
			{
				n = temp->num;
				temp->num = temp1->num;
				temp1->num = n;
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
	
}
