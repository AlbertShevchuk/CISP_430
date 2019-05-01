#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef struct node * nodePtr;

struct node
{
    int data;
    nodePtr next;
};

typedef struct node node;
nodePtr headMain = NULL;

void push(nodePtr &head, int data)
{
    nodePtr newNode = new node;
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL)
	{
        head = newNode;
        headMain = head;
    }
	else
	{
        head->next = newNode;
        head = newNode;
    }
}

void print(nodePtr head)
{
    nodePtr curr = head;
    while(curr != NULL)
	{
        cout<<curr->data;
        curr = curr->next;
    }
   cout<<endl; 
}

void segregate(nodePtr head, nodePtr &top, nodePtr &bottom)
{
    nodePtr flat;
    nodePtr passive;

    if (head == NULL || head->next == NULL)
	{
        top = head;  
        bottom = NULL;  
    }
	else
	{
		flat = head->next;
        passive = head;

        while(flat != NULL)
		{
            flat = flat->next;

            if(flat != NULL)
			{
                passive = passive->next;
                flat = flat->next;
            }
        }
        top = head;  
        bottom = passive->next;  
        passive->next = NULL;
    }
}

nodePtr merge(nodePtr i, nodePtr ii) 
{
    nodePtr merged = NULL;

    if (i == NULL)
		return ii;
    else if (ii == NULL)
        return i;
    if (i->data <= ii->data)
	{
        merged = i;
        merged->next = merge(i->next, ii);
    }
	else
	{
        merged = ii;
        merged->next = merge(i, ii->next);
    }
    
    return merged;
}

void sort(nodePtr *origin)
{
    nodePtr head = *origin;
    nodePtr i = NULL;
    nodePtr ii = NULL;

    if(head == NULL || head->next == NULL)
		return;
		
    segregate(head, i, ii);
    sort(&i);
    sort(&ii);
    *origin = merge(i, ii);
}

int main()
{
	nodePtr head = NULL;  
    
	cout<<"Enter Five random non-nagative numbers"<<endl;

	for(int counter = 1, value = 0; counter<=5 ; counter++)
	{
		cout<<endl<<"Entery for Number "<<counter<<": ";
		cin>>value;
		push(head, value); 
	}
	
	cout<<endl<<endl;
    print(headMain);
    sort(&headMain);
    print(headMain);

return 0;
}

