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
};
struct myList3
{
	char data[10];						
	struct myList *next;	
};
struct myList4
{
	char data[10];						
	struct myList *next;	
};

typedef struct myList list;	
typedef struct myList list3;
typedef struct myList list4;

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
}


list3* merge(list3 *head3, list4 *head4) 
{
   	list3 *i = head3;
	do
	{
		if(i->next==NULL)
		{
			return(i);
			break;
		}
		i=i->next;
	}
	while (i!=NULL);
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
 
 
list* split(list *head, int wordCount)
{
 	list *curr, *i;
 	int counter = 0;
 	i = head;

 	do
	{
		counter++;
		if(counter==(wordCount/2))
		{
			curr = i->next;
			i->next = NULL;
			break;
		}
		else
			i=i->next;	
	}
	while (counter<(wordCount/2));
 	return (curr);
}


int main()
{
	in.open("inputSplit.txt");
	out.open("outputSplit.txt");
	list *head , *curr;
	list3 *head3 , *curr3;
	list4 *head4 , *curr4;
	head = NULL;
	head3 = NULL;
	head4 = NULL;
	char temp[10] = {NULL};
	bool file = 0;
	int wordCount = 0;	
					
	do
	{
		temp[0]= {NULL};
		in >> temp;
		
		if(temp[0]==NULL)
		{
			if(file)
				cout<<"myList1 and myList2 has been created"<<endl<<endl;
			else
				cout<<"Nothing has been read"<<endl<<endl;
		}
			else
			{
				if(!head)
				{
					wordCount++;
					file = 1;
					list* newList = (list *)malloc(sizeof(list));
					strcpy (newList->data,temp);
					newList->next = NULL;
					head = newList;
					curr = newList;
				}
				else
				{	
					wordCount++;
					list* newList = (list *)malloc(sizeof(list));
					strcpy (newList->data,temp);
					curr->next = newList;
					newList->next = NULL;
					curr = newList;		
				}
			}	
	}	
	while(temp[0]!=0);
								
	curr = split(head, wordCount);
	out<<endl<<"myList1"<<endl<<endl;
	traverse(head);
	out<<endl<<"myList2"<<endl<<endl;
	traverse(curr);
											
	in.close();
   	out.close(); 
	in.clear();   
	in.open("inputMerge.txt");
	out.open("outputMerge.txt");   
	
	int counter = 0;

	do
	{
		counter++;
		if(counter<=5)
		{
			if(!head3)
			{
				list3* newList3 = (list3 *)malloc(sizeof(list3));
				in >>newList3->data;
				newList3->next = NULL;
				head3 = newList3;
				curr3 = newList3;
			}
			else
			{
				list3* newList3 = (list3 *)malloc(sizeof(list3));
				in >>newList3->data;
				curr3->next = newList3;
				newList3->next = NULL;
				curr3 = newList3;		
			}
		}
		else
		{
			if(!head4)
			{
				list4* newList4 = (list4 *)malloc(sizeof(list4));
				in >>newList4->data;
				newList4->next = NULL;
				head4 = newList4;
				curr4 = newList4;
			}
			else
			{
				list4* newList4 = (list4 *)malloc(sizeof(list4));
				in >>newList4->data;
				curr4->next = newList4;
				newList4->next = NULL;
				curr4 = newList4;			
			}
		}
	}
	while(counter<10);  
	
	cout<<endl<<"myList3 and myList4 has been combined into myList3"<<endl;	
	curr3 = merge(head3,head4);
	curr3->next = head4;
	traverse(head3);
	in.close();
   	out.close(); 
	in.clear(); 
	dellete(head);
	dellete(curr);
	dellete(head3);
	
return(0);
}
