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
char data[20];// int data;
node *next;
node *prev;
};

string print()
{
	node *head;
	node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
	}

	
}
/*
void insertBeg (char a[20], struct node *&head, struct node *&tail)
{
//node *temp=a; //a temp pointer variable that we want to point to the new nodes that are created
temp=new node; //creates a new node and then assigns the address to temp because a pointer is being returned 
strcpy(temp->data, data);//temp->data=item;

if (!head)
{ //nothing in the list, everything points to self
 //this should only happen once when the list is empty and then everytime after should go to the else condition
temp->prev=temp;
temp->next=temp;
head=temp;
tail=temp;
}
else
{ //something in the list. Connect old tail and old head
temp->prev=head->prev; //temp->prev=head->prev connect temp to tail
temp->next=head; //connect temp to head
head->prev=temp; //connect old head to the one before it which is the new node
temp->prev->next=temp; //connecting the tail to the new node
head=temp; //head becomes temp

/*
tail->next=temp;
temp->prev=tail;
temp->next=head;
tail=temp;
head->prev=temp;

}

}
*/
int main()
{
	node *head, *tail , *temp = NULL;
	char misc[20] = {NULL};
	in.open("input.txt");
    out.open("output.txt");
    
	in>>misc;
	
	//node *temp=a; //a temp pointer variable that we want to point to the new nodes that are created
	temp=new node; //creates a new node and then assigns the address to temp because a pointer is being returned 
	strcpy(temp->data, misc);//temp->data=item;
	
	if (!head)
	{ //nothing in the list, everything points to self
	 //this should only happen once when the list is empty and then everytime after should go to the else condition
	temp->prev=temp;
	temp->next=temp;
	head=temp;
	tail=temp;
	}
	else
	{ //something in the list. Connect old tail and old head
	temp->prev=head->prev; //temp->prev=head->prev connect temp to tail
	temp->next=head; //connect temp to head
	head->prev=temp; //connect old head to the one before it which is the new node
	temp->prev->next=temp; //connecting the tail to the new node
	head=temp; //head becomes temp
    }
	/*
	tail->next=temp;
	temp->prev=tail;
	temp->next=head;
	tail=temp;
	head->prev=temp;
	
	*/	
	while(misc!=NULL)//print function to display contents of array
	{
	 //int i=0;
	 cout<<temp->data<<endl;
	 exit(1);	
	 //i++;
	 //break;
	}
	
	return 0;
}


