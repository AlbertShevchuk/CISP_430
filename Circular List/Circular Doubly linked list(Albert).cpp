#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
ifstream in; 
ofstream out;

struct myList
{
	char data[10];						
	struct myList *next;	
	struct myList *prev;
};

typedef struct myList list;

list* remove(list *&head, list *&curr, int number)
{
	list *cur;
	int counter = 0;
	
	for(int i = 1; i <= number; i++)
	{
		cur = head;
		head = head->next;
		head->prev = curr;
		curr->next = head;
		delete(cur);
	}		
}

list* dellete(list* head, int counter)
{
	list *i = head;
	int cnt = 0;
	
	do
	{
		cnt++;
		head=head->next;
		delete(i);
		i=head;
	}
	while (cnt<counter);
}

traverse(list *head, int counter)
{
 	list *i = head;
	int cnt = 0;
	
	do
	{
		cnt++;
		head=head->next;
		out<<i->data<<endl;
		i=head;
	}
	while (cnt<counter);
}

int main()
{
	in.open("input.txt");
	out.open("output.txt");
	list *head , *curr;
	head = NULL;
	char temp[10] = {NULL};
	bool file = 0;
	int counter = 0;
				
	do
	{
		temp[0]= {NULL};
		in >> temp;
		
		if(temp[0]==NULL)
		{
			if(file)
				cout<<"Circular doubly linked myList has been created"<<endl<<endl;
			else
			{
					cout<<"Nothing has been read!"<<endl<<endl;
					exit(0);
			}
		}
		else
		{
			if(!head)
			{
				file = 1;
				counter++;
				list* newList = (list *)malloc(sizeof(list));
				newList->prev = NULL;
				strcpy (newList->data,temp);
				newList->next = NULL;
				head = newList;
				curr = newList;
			}
			else
			{	
				counter++;
				list* newList = (list *)malloc(sizeof(list));
				curr->next = newList;
				newList->prev = curr;
				strcpy (newList->data,temp);
				newList->next = NULL;
				curr = newList;		
			}
		}	
	}	
	while(temp[0]!=NULL);
	
	head->prev = curr;
	curr->next = head;
	int number = 0;
	
	cout<<"How many consecutive items do you want to delete from the beggining? "<<endl;
	do
	{
		cout<<"You are only allowed to chose between items 1 and  "<<counter<<endl;
		cin>>number;
		if((number<=counter)&&(number>0))
			break;
		cout<<"Your entry was invalid, please try again "<<endl;			
	}
	while(!((number<=counter)&&(number>0)));
	
	if(number == counter)
		{
			cout<<"You have chosen to delete all the items"<<endl;
			dellete(head,counter);
		}
	else
	{
		remove(head,curr,number);
		out<<"Below is the resultant after removal"<<endl<<endl<<endl;
		traverse(head, (counter-number));
		dellete(head, (counter-number));	
		cout<<endl<<"Ammount of items written to file output.txt: "<<(counter-number)<<endl;
	}
return(0);
}
