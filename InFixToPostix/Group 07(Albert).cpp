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
	char stuff;
	struct stack *next;
};
typedef struct stack stack;

pop(stack *&top, stack *&bottom)
{
	
	stack *temp;
	temp = top;
	cout<<temp->stuff;
	
	if(top->next == NULL)
		top=NULL;
	else
		top=top->next;	
	delete(temp);
}

push(char temp, stack *&top , stack *&bottom)
{
	stack* newstack = (stack *)malloc(sizeof(stack));
	newstack->stuff=temp;
	
	if(top)
	{
		newstack->next = top;
		top = newstack;
	}
	else
		newstack->next = NULL;
		top = bottom = newstack;	
}

int main()
{
	in.open("input.txt");
	char temp;
	stack *top = NULL, *bottom = NULL;
	bool done, done1, done2;
	
	while(in >> temp != NULL)
	{
		done = 1;
		while(done)
		{		
			if((temp == '-') || (temp == '+') || (temp == '*') || (temp == '/') || (temp == '(') || (temp == ')'))
			{
				if(temp == '(')
				{
					push(temp, top, bottom);
					done2 = 1;
			
					do
					{
						in >> temp;
						done1 = 1;
						while(done1)
						{		
							if((temp == '-') || (temp == '+') || (temp == '*') || (temp == '/') || (temp == ')'))
								{
									if(top->stuff == '(')
									{
										push(temp, top, bottom);
										done1 = 0;
										break;
									}
									else if(temp == ')')
									{
										do
										{
											if(top->stuff == '(')
												{
													stack *temp;
													temp = top;
													if(top->next == NULL)
														top=NULL;
													else
														top=top->next;
					 								delete(temp);
												}
											else
											{
												pop(top, bottom);
											}
										}
										while(top->stuff =! '(');
										
										done2 = 0;
										done = 0;
										break;										
									}
									else if((top->stuff == '+') && ((temp == '+') || (temp == '-')))
				 					  	pop(top, bottom);
									else if((top->stuff == '-') && ((temp == '+') || (temp == '-'))) 
										pop(top, bottom);	
									else if((top->stuff == '*') && ((temp == '*') || (temp == '/')))	
									  	pop(top, bottom);
									else if((top->stuff == '/') && ((temp == '*') || (temp == '/')))	
									  	pop(top, bottom);
									else if((top->stuff == '*') && ((temp == '+') || (temp == '-')))
									 	pop(top, bottom);
									else if((top->stuff == '/') && ((temp == '+') || (temp == '-'))) 		
								  		pop(top, bottom);
									else if((top->stuff == '-') && ((temp == '*') || (temp == '/')))	
									  	{
									  		push(temp, top, bottom);
									  		done1 = 0;
									  	}	
									else if((top->stuff == '+') && ((temp == '*') || (temp == '/')))	
									  	{
											push(temp, top, bottom);
											done1 = 0;	
										}
								}
								else
								{
									cout<<temp;
									done1 = 0;
								}
						}		
					}	
					while(done2);
				}
				
				if(top == NULL) 
			 	{
					push(temp, top, bottom);
					done = 0;
					break;
				}
		
				if((top->stuff == '+') && ((temp == '+') || (temp == '-')))
					pop(top, bottom);
				 	  		 	  	
					
				else if((top->stuff == '-') && ((temp == '+') || (temp == '-'))) 		
				  	pop(top, bottom);	
				else if((top->stuff == '*') && ((temp == '*') || (temp == '/')))	
				  	pop(top, bottom);
				else if((top->stuff == '/') && ((temp == '*') || (temp == '/')))	
				  	pop(top, bottom);	
				else if((top->stuff == '*') && ((temp == '+') || (temp == '-')))
				 	pop(top, bottom);	
				else if((top->stuff == '/') && ((temp == '+') || (temp == '-'))) 		
				  	pop(top, bottom);	
				else if((top->stuff == '-') && ((temp == '*') || (temp == '/')))	
				  	{
						push(temp, top, bottom);
				  		done = 0;
					}	
				else if((top->stuff == '+') && ((temp == '*') || (temp == '/')))	
				  	{
						push(temp, top, bottom);
						done = 0;
					}
			}
			else
			{
				cout<<temp;
				done = 0;
			}
						
		}	
	}

	stack *temp1;
	temp1 = top;
while(top!=NULL)
{	
	temp1 = top;
	cout<<temp1->stuff;
	
	if(top->next == NULL)
		top=NULL;
	else
		top=top->next;
		
	delete(temp1);
}

 return (0);
}
