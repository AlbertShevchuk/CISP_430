#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

ifstream in; 
ofstream out;

struct stack 
{
	int stuff;
	struct stack *next;
};
typedef struct stack stack;

pop(stack *&top, stack *&bottom)
{
	int pass;
	stack *temp;
	temp = top;
	pass = top->stuff;
	
	if(top->next == NULL)
		top=NULL;
	else
		top=top->next;	
		
	delete(temp);
	return(pass);
}

push(int temp, stack *&top , stack *&bottom)
{
	stack* newstack = (stack *)malloc(sizeof(stack));
	newstack->stuff=temp;
	
	if(top)
	{
		newstack->next = top;
		top = newstack;
	}
	else
	{
		newstack->next = NULL;
		top = bottom = newstack;
	}
}

int main()
{
	in.open("input.txt");
	char temp;
	int right, left;
	stack *top = NULL, *bottom = NULL;
	
	while( in >> temp != NULL)
	{		
		if((temp == '-') || (temp == '+') || (temp == '*') || (temp == '/'))
		{
			right = pop(top, bottom);
			left = pop(top, bottom);
				
			if (temp == '-')
   				{
					push((left - right), top , bottom);
  				}
			else if (temp == '+')
				{
					push((left + right), top , bottom);
				}		
       		else if (temp == '*')
			    {
			    	push((left * right), top , bottom);
				}
      		else if (temp == '/')
			  	{
			  		push((left / right), top , bottom);	
				}
       	}
		else
		{
			push((temp-'0'), top , bottom);
		}
	}

	cout<<top->stuff<<endl;	
	delete(top);
	
 return (0);
}
