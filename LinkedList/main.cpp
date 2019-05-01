/*
Zia Rehman
CISP 430
Professor Sabzevary
MW 7:00PM - 8:20PM
Group Project 2
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
ifstream in;
ofstream out;

struct name
{
	char letters[16];
	struct name *next;
};
struct myList3
{
	char letters[16];
	struct name *next;
};
struct myList4
{
	char letters[16];
	struct name *next;
};

typedef struct name list;
typedef struct name list3;
typedef struct name list4;

void erase(list* head)
{
	list *position;
	position = head;
	do
	{
		head=head->next;
		delete(position);
		position=head;
	}
	while (position != '\0');
}


list3* merge(list3 *head3, list4 *head4)
{
   	list3 *i = head3;
	do
	{
		if(i->next == '\0')
		{
			return(i);
			break;
		}
		i = i->next;
	}
	while (i != '\0');
}


void traverse(list *head)
{
 	list *i = head;
	do
	{
		out<<i->letters<<endl;
		i=i->next;
	}
	while (i != '\0');
}


list* split(list *head, int elements)
{
 	list *current, *i;
 	int counter = 0;
 	i = head;

 	do
	{
		counter++;
		if(counter==(elements/2))
		{
			current = i->next;
			i->next = '\0';
			break;
		}
		else
			i=i->next;
	}
	while (counter < (elements/2));
 	return (current);
}


int main()
{
	in.open("inputSplit.txt");
	out.open("outputSplit.txt");
	list *head , *current;
	list3 *head3 , *current3;
	list4 *head4 , *current4;
	head = '\0';
	head3 = '\0';
	head4 = '\0';
	char temp[16] = {'\0'};
	bool file = 0;
	int wordCount = 0;

	do
	{
		temp[0] = {'\0'};
		in >> temp;

		if(temp[0] == '\0')
		{
			if(file)
				cout<<"Split Worked!!!"<<endl<<endl;
			else
				cout<<"Empty input"<<endl<<endl;
		}
			else
			{
				if(!head)
				{
					wordCount++;
					file = 1;
					list* newList = (list *)malloc(sizeof(list));
					strcpy (newList->letters,temp);
					newList->next = '\0';
					head = newList;
					current = newList;
				}
				else
				{
					wordCount++;
					list* newList = (list *)malloc(sizeof(list));
					strcpy (newList->letters,temp);
					current->next = newList;
					newList->next = '\0';
					current = newList;
				}
			}
	}
	while(temp[0] != 0);

	current = split(head, wordCount);
	out<<endl<<"myList1"<<endl<<endl;
	traverse(head);
	out<<endl<<"myList2"<<endl<<endl;
	traverse(current);

	in.close();
   	out.close();
	in.clear();
	in.open("inputMerge.txt");
	out.open("outputMerge.txt");

	int counter = 0;

	do
	{
		counter++;
		if(counter <= 5)
		{
			if(!head3)
			{
				list3* newList3 = (list3 *)malloc(sizeof(list3));
				in >>newList3->letters;
				newList3->next = '\0';
				head3 = newList3;
				current3 = newList3;
			}
			else
			{
				list3* newList3 = (list3 *)malloc(sizeof(list3));
				in >>newList3->letters;
				current3->next = newList3;
				newList3->next = '\0';
				current3 = newList3;
			}
		}
		else
		{
			if(!head4)
			{
				list4* newList4 = (list4 *)malloc(sizeof(list4));
				in >>newList4->letters;
				newList4->next = '\0';
				head4 = newList4;
				current4 = newList4;
			}
			else
			{
				list4* newList4 = (list4 *)malloc(sizeof(list4));
				in >>newList4->letters;
				current4->next = newList4;
				newList4->next = '\0';
				current4 = newList4;
			}
		}
	}
	while(counter<16);

	cout<<endl<<"Merged Successfully!"<<endl;
	current3 = merge(head3,head4);
	current3->next = head4;
	traverse(head3);
	in.close();
   	out.close();
	in.clear();
	erase(head);
	erase(current);
	erase(head3);

return(0);
}
