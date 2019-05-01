#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
ifstream in; 
ofstream out;

struct node {
     int item;
     node *next;          
};

typedef struct node node;	

dellete(node* head)
{
	node *i;
	i = head;
	do
	{
		head=head->next;
		delete(i);
		i=head;
	}
	while (i!=NULL);
}

void traverse(node *head)
{
 	node *i = head;

	while (i!=NULL)
	{
		cout<<i->item<<endl;
		i=i->next;
	}
}

void enqueue(int temp, node *&head, node *&tail)
{
	node* newNode = (node *)malloc(sizeof(node));
	newNode->item = temp;
	newNode->next = NULL;
		
	if(tail)
	{
		tail->next = newNode;
		tail = newNode;
	}
	else
		head = tail = newNode;	
}

void dequeue(node *&head, node *&tail)
{
	node *temp;
    temp = head;  
    head = head->next;  
	delete temp;
}

int main()
{
	in.open("input.txt");
	int temp;
	node *head = NULL, *tail = NULL, *tempTail = NULL, *i = NULL;
	
	while((in>>temp) != NULL)
	{ 
		enqueue(temp,head,tail);
	}

	tempTail = tail;
	
	do
	{
		i = head;
		
		if((head->item)<0)
		
			dequeue(head,tail);
		else
			{
				enqueue(head->item, head, tail);
				dequeue(head,tail);
			}
	}
	while(i != tempTail);
	
	if(head == NULL)
		cout<<"The input were all negative numbers"<<endl;
	else
		traverse(head);
		
	in.close();
	in.clear();	
	dellete(head);
	head = NULL, tail = NULL, tempTail = NULL, i = NULL;
	
return(0);  
}

