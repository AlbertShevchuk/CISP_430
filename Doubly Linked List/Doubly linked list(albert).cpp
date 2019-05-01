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
	int data;						
	struct myList *next;	
	struct myList *prev;
};

typedef struct myList list;

dellete(list* head)
{
	list *i;
	i = head;
	do
	{
		head=head->next;
		delete(i);
		i=head;
	}
	while (i!=NULL);
	cout<<endl;
	cout<<"Output.txt file is ready"<<endl<<endl;
}

traverse(list *head)
{
 	list *i = head;
	do
	{
		out<<i->data<<endl;
		i=i->next;
	}
	while (i!=NULL);
	
	
}

list* deleteFromTail(list *curr, list *head, int number, int totalNumbers)
{
	list *cur = curr;
	list *pre = NULL;
	list *ahead = cur->prev;
	int counter = 0;
	
	do
	{
		counter++;
		if(counter == number)
		{
			if(pre == NULL)
			{
				 curr=curr->prev;
				 ahead->next=NULL;
				 delete(cur);
				 return(curr);
				 break;
			}
			else
			{
				if(counter == totalNumbers)
				{
					delete(cur);
					pre->prev=NULL;
					head = pre;
					return(head);
					break;
				}
				else
				{
					pre->prev=ahead;
					ahead->next=pre;
					delete(cur);
					return(curr);
					break;
				}
			}
		}
		pre = cur;
		cur = cur->prev;
		ahead = cur->prev;
	}
	while (counter!=number);	
}

list* deleteFromHead(list *head, list *curr, int number, int totalNumbers)
{
	list *cur = head;
	list *pre = NULL;
	list *ahead = cur->next;
	int counter = 0;
	
	do
	{
		counter++;
		if(counter == number)
		{
			if(pre == NULL)
			{
				 head=head->next;
				 head->prev=NULL;
				 delete(cur);
				 return(head);
				 break;
			}
			else
			{
			
				if(counter == totalNumbers)
				{
					delete(cur);
					pre->next=NULL;
					curr = pre;
					return(curr);
					break;
				}
				else
				{
					pre->next=ahead;
					ahead->prev=pre;
					delete(cur);
					return(head);
					break;
				}
			}
		}
		pre = cur;
		cur = cur->next;
		ahead = cur->next;
	}
	while (counter!=number);	
}

int main()
{
	in.open("input.txt");
	out.open("output.txt");
	list *head , *curr;
	head = NULL;
	int temp = 0;
	bool file = 0;
	int counter = 0;
				
	do
	{
		temp = 0;
		in >> temp;
		
		if(temp==0)
		{
			if(file)
				cout<<"Doubly linked myList has been created"<<endl<<endl;
			else
				cout<<"Nothing has been read"<<endl<<endl;
		}
		else
		{
			if(!head)
			{
				file = 1;
				counter++;
				list* newList = (list *)malloc(sizeof(list));
				newList->prev = NULL;
				newList->data = temp;
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
				newList->data = temp;
				newList->next = NULL;
				curr = newList;		
			}
		}	
	}	
	while(temp!=0);
		
	int number=0;
	
	cout<<"Which item do you want to delete from the beginning?"<<endl;
	
	do
	{
		cout<<"You are only allowed to chose between items 1 and  "<<counter<<endl;
		cin>>number;
		if((number<=counter)&&(number>0))
			break;
		cout<<"Your entry was invalid, please try again "<<endl;			
	}
	while(!((number<=counter)&&(number>0)));
	 
	((number==counter)?(curr):(head)) = deleteFromHead(head,curr,number,counter);
	
	counter--;
	
	cout<<"Which item do you want to delete from the end?"<<endl;
	
	do
	{
		cout<<"You are only allowed to chose between items 1 and "<<counter<<endl;
		cin>>number;
		if((number<=counter)&&(number>0))
			break;
		cout<<"Your entry was invalid, please try again "<<endl;			
	}
	while(!((number<=counter)&&(number>0)));
	
	((number==counter)?(head):(curr)) = deleteFromTail(curr,head,number,counter);
	
	traverse(head);
	in.close();
   	out.close(); 
	in.clear(); 
	dellete(head);
	
return(0);
}
