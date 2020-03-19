#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct Mylist
{
	int score;
	char name[16];
	struct Mylist* prev;
	struct Mylist* next;
}mylist;


mylist* IniticalList()
{
	mylist* tmp = (mylist*)malloc(sizeof(mylist));
	memset(tmp, 0, sizeof(mylist));
	tmp->prev = NULL;
	tmp->next = NULL;
	return tmp;
}

void InsertNewElement(mylist* head)
{
	mylist* p = NULL;
	if(head != NULL)
	{
		p = head;
	}
	else
		return;
	while(p->next != NULL)
	{
		p = p->next;
	}
	mylist* new = (mylist*)malloc(sizeof(mylist));
	new->score = rand()%100;
	strcpy(new->name, "Yj");
	p->next = new;
	new->next = NULL;
	new->prev = p;
}

void InsertNewSpecialElement(mylist* head, int num)
{
	mylist* p = NULL;
	if(head != NULL)
	{
		p = head;
	}
	else
		return;
	while(p->next != NULL)
	{
		p = p->next;
	}
	mylist* new = (mylist*)malloc(sizeof(mylist));
	new->score = num;
	strcpy(new->name, "Yj");
	p->next = new;
	new->next = NULL;
	new->prev = p;
}

mylist* FindTheElement(mylist* head, int targ)
{
	mylist* p = head;
	while(p!=NULL && p->score != targ )
	{
		p = p->next;
	}
	return p;
}

void ChangeElementInList(mylist* head, int num, int newnum)
{
	mylist* pos = FindTheElement(head, num);
	if(pos != NULL)
		pos->score = newnum;
	else
		return;
}

void DeleteElement(mylist* head, int targ)
{
	mylist* p = FindTheElement(head, targ);
	if(p != NULL)
	{
		mylist* tmp = p;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(tmp);
	}
	else
		return;	
}

void DeleteAllList(mylist* head)
{
	mylist* p = head;
	while(p->next != NULL)
	{
		mylist* tmp = p;
		p = p->next;
		free(tmp);
	}
	free(p);
}

void PrintALLList(mylist* head)
{
	mylist* p = NULL;
	if(head != NULL)
	{
		p =  head->next;
	}
	while(p != NULL)
	{
		printf("the num is: %d \n",p->score);
		p = p->next;
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	mylist* head = IniticalList();
	for(int i = 0; i < 10; i++)
	{
		InsertNewElement(head);
	}
	InsertNewSpecialElement(head,102);
	PrintALLList(head);
	printf("please input num need: ");
	int num,numold;
	scanf("%d,%d",&num,&numold);
	ChangeElementInList(head,numold,num);
	printf("------------------------\n");
	PrintALLList(head);
	DeleteElement(head,num);
	printf("------------------------\n");
	PrintALLList(head);
	printf("------------------------\n");
	DeleteAllList(head);
	head = NULL;
	PrintALLList(head);
	return 0;
}