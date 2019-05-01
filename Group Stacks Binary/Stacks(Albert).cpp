#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct stack 
{
	unsigned long long int num;
	struct stack *next;
};
typedef struct stack stack;

dellete(stack *head)
{
	stack *i;
	i = head;
	do
	{
		head=head->next;
		delete(i);
		i=head;
	}
	while (i!=NULL);
}

pop(stack *&top, stack *&bottom, bool biHex)
{
	stack *temp;
	
	if(biHex == 0)
	{
		do
 		{	
 			if(top == bottom)
 			{
 				cout<<top->num;
 				delete (top);
 				top = NULL;
 				bottom =NULL;
		 	}
		 	else
	 		{
	 			temp=top;
 				cout<<top->num;
 				top=top->next;	
 				delete temp;
			}
 		}
 		while(top!=NULL);
 	}
 	else
 	{
 		do
 		{	
 			if(top == bottom)
 			{
 				if((top->num) > 9)
					 cout<<(char)((top->num) + 55);
				else
					 cout<<top->num;
					 
 				delete (top);
 				top = NULL;
 				bottom =NULL;
		 	}
		 	else
	 		{
	 			if((top->num) > 9)
					 cout<<(char)((top->num) + 55);
				else
					 cout<<top->num;
					 
	 			temp=top;
 				top=top->next;	
 				delete temp;
			}
 		}
 		while(top!=NULL);
	}
}

push(int remainder, stack *&top , stack *&bottom)
{
	stack* newstack = (stack *)malloc(sizeof(stack));
	newstack->num=remainder;
	newstack->next=top;
	top=newstack;
	if(!bottom)
		bottom = newstack;	
}

hexadecimal(int number, stack *&top, stack *&bottom)
{
	int remainder;
	
	do
	{
		remainder = number % 16; 
		number = number/16;
		push(remainder,top,bottom);
	}
	while(number!=0);
}

binary(int number, stack *&top, stack *&bottom)
{
	unsigned long long int remainder;
	
	do
	{
		remainder = number % 2; 
		number = number/2;
		push(remainder,top,bottom);
	}
	while(number!=0);
}

int main()
{
	long long number;
	stack *top, *bottom = NULL;

	cout<<"Enter a positive number: ";
 	cin>>number;
 	cout<<endl;
 	cout<<"The number " << number << " converted to binary is: ";
 	binary(number,top,bottom);
 	pop(top,bottom,0);
 	cout<<endl<<endl;
 	cout<<"The number " << number << " converted to hexadecimal is: ";
 	hexadecimal(number,top,bottom);
 	pop(top,bottom,1);
 	dellete(bottom);
 	
 return (0);
}
