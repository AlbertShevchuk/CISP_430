#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
ifstream in; 

struct node 
{
     int item;
     node *next;          
};

typedef struct node node;

enqueue(int temp, node *&head, node *&tail)
{
	node* newNode = (node *)malloc(sizeof(node));
	newNode->item = temp;
	newNode->next = NULL;
		
	if(head)
	{
		tail->next = newNode;
		tail = newNode;
	}
	else
		head = tail = newNode;		
}

dequeue(node *&head)
{
	node *temp;
	temp = head; 
	
	if(head->next!=NULL)
    	head = head->next; 
    else
    	head = NULL;
	 
	delete temp;
}



int main()
{	
	node *head = NULL, *tail = NULL, *arrayBase10[10] = {NULL};
	int temp = 0, counter = 0, bigNum = 0, arraySize = 0;
	
	in.open("input.txt");
	
	while(in >> temp != NULL)
		counter++;
		
	int arrayTemp[counter-1];
	
	in.close();
	in.clear();	
	in.open("input.txt");
	
	counter = 0; 
	
	while(in >> temp != NULL)
	{
		arrayTemp[counter] = temp;	
		counter++;	
	}
	
	arraySize = counter;
	bigNum = arrayTemp[counter];
	counter--;
	arraySize--;
	
	while(counter >= 0)
	{
		if(arrayTemp[counter]>=bigNum)
			bigNum=arrayTemp[counter];
												
		counter--;		
	}
	
	counter = 1;
	
	while((bigNum/10)!=0)
	{
		bigNum=bigNum/10;
		counter++;
	}
	
	int mod = 1, divizor = 1;
	
	bigNum = counter;
	
	for(int counter0 = 1; counter0 <= bigNum; counter0++)
	{
		mod = mod*10;
		if(counter0 > 1)
			divizor = divizor*10;
		
		for(counter = 0; counter <= 9; counter++)
		{
			for(int counter1 = 0; counter1 <= arraySize; counter1++)
			{
				if(((arrayTemp[counter1] % mod) / divizor) == counter)
				{
					enqueue(arrayTemp[counter1], head, tail);
					arrayBase10[counter] = head;
				}
			}
			head = NULL;
			tail = NULL;	
		}
		
		int counter3 = 0;
		
		for(int counter2 = 0; counter2 <= 9; counter2++)
		{		
			while(arrayBase10[counter2] != NULL)
			{
				arrayTemp[counter3] = arrayBase10[counter2]->item;
				dequeue(arrayBase10[counter2]);
				counter3++;
			}
		}	
	}

	for(counter = 0; counter <= arraySize; counter++)
		cout<<arrayTemp[counter]<<" ";
	
	in.close();
	in.clear();	
return (0);
}
