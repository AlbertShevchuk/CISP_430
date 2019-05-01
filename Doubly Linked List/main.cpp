#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
 
using namespace std;
ifstream in; 
ofstream out;


struct node
{
	int number;
	node *next;
};

bool empty(node *head);
char menu();
void insertfirst(node *&head, node *&last, int number);
void insert (node *&head, node *&last, int number);
void remove (node *&head, node *&last);
void show(node *current);


bool empty(node *head)
{
	if(head==NULL)
	return true;
	else
	return false;
}

char menu()
{
	char choice;
	
	cout<<"Menu"<<endl;
	cout<<"1: Add Something"<<endl;
    cout<<"2: Remove Something"<<endl;
	cout<<"3: Show contents"<<endl;
	cout<<"4: Exit"<<endl;	
	
	cin>>choice;
	
	return choice;
}

void insertfirst(node *&head, node *&last, int number)
{
	node *temp = new node;
	temp->number = number;
	temp->next = NULL;
	head = temp;
	last = temp;	 
}
void insert (node *&head, node *&last, int number)
{
	if(empty(head))
	{
		insertfirst(head,last,number);
	}
	else
	{
	node *temp = new node;
	temp->number = number;
	temp->next = NULL;
	last->next = temp; //joins the links or elements in the list
	last = temp;
	}
}
void remove (node *&head, node *&last)
{
	if(empty(head))
	cout<<"The list contains nothing!"<<endl;
	else 
	if(head == last)
	{
		delete head;
		head == NULL;
		last == NULL;
	}
	else
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}
}
void show(node *current)
{
	if(empty(current))
	{
	 cout<<"The list is empty."<<endl;	
	}
	else
	{
		cout<<"The list contains"<<endl;
		while(current != NULL)
		{
			cout<<current->number<<endl;
			current = current->next;
			
		}
	}
}

int main()
{
	node *head = NULL;
	node *tail = NULL;
	int number;
	char choice;
	
	do{
		
		choice=menu();
		
		switch(choice)
		{
			case '1': cout<< "Please enter a number"<<endl;
					  cin>>number;
					  insert(head, tail, number);
					  break;
			case '2': remove(head, tail);
					  break;
			case '3': show(head);
					  break;
			default: cout<<"System Exit";					 		
		}
		
	}while(choice != '4');
	
	
	
	return 0;
}


/*
struct node
{
	int data;
	node *next;
	node *prev;
};


int main() 
{
	node *head, *current, *tail=NULL;
	node *first, *second;
	int data = 0;
	
	cout<<data<<endl;
	
	head = new node;
	head->next=NULL;
	head->prev=NULL;
	head->data=3;
	second = new node;
	first->next=second;
	second -> data = 2;
	second -> next = NULL;
	cout<<head<<endl;
	cout<<second<<endl;
	return 0;
} */
