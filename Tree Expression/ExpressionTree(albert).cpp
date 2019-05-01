#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

using namespace std;

struct tree 
{ 
    char data; 
    struct tree *left;
	struct tree *right; 
};

typedef struct tree tree;

int top=-1; 
tree *stack[20]; 
tree *node;

void push(tree* node) 
{ 
    stack[++top]=node; 
}

tree* pop() 
{ 
    return(stack[top--]); 
}

int check(char ch) 
{ 
	if((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*')) 
		return 2; 
	else 
		return 1; 
}

int cal(tree *node) 
{ 
    int ch; 
    ch = check(node->data); 
    if(ch == 1) 
   		return node->data-48; 
    else if(ch == 2) 
    { 
        if(node->data == '+') 
            return cal(node->left) + cal(node->right); 
        if(node->data == '-') 
            return cal(node->left) - cal(node->right); 
        if(node->data == '*') 
            return cal(node->left) * cal(node->right); 
        if(node->data == '/') 
            return cal(node->left) / cal(node->right); 
    } 
}

void levelDisplay(tree *node) 
{
	int static level = 0;
	
	if(node!=NULL) 
    { 	
    	level++;
		cout<<" Level: "<<level<<", heading left"<<endl;	
		levelDisplay(node->left); 
		level--;
		cout<<" Level: "<<level<<", heading right"<<endl;
		levelDisplay(node->right);
	}
}

inorder(tree *node) 
{ 
	int static numCount = 0;

    if(node!=NULL) 
    { 	
   		inorder(node->left); 
   		
   		if(numCount == 0)
    	{
    		cout<<"(";	
    		numCount = 1;
		}
		if(numCount == 3)
    	{
    		cout<<")";	
    		numCount = 0;
		}
	
   	 	cout<<node->data; 
   	 	
   		if(!(node->data=='+'||node->data=='-'||node->data=='/'||node->data=='*')) 
   	 		numCount++;
		
    	inorder(node->right);
    } 
    
return (numCount);	
}

void operand(char b) 
{ 
    node=(tree*)malloc(sizeof(tree)); 
    node->data=b; 
    node->left=NULL; 
    node->right=NULL; 
    push(node); 
}

void operators(char a) 
{ 
    node=(tree*)malloc(sizeof(tree)); 
    node->data=a; 
    node->right=pop(); 
    node->left=pop(); 
    push(node); 
}

main() 
{ 
    int i,p,k,ans; 
    char s[20]; 
  
    cout<<"Enter a postfix expression: "; 
  
    gets(s); 
    k=strlen(s); 
    i=0; 
    
    for(i=0; s[i]!='\0'; i++) 
    { 
    	p=check(s[i]); 
        if(p==1) 
            operand(s[i]); 
        else if(p==2) 
            operators(s[i]); 
    } 
    
    ans=cal(stack[top]); 
    cout<<"The resultant value is: "<<ans<<endl; 
    cout<<"The expression tree in infix notation is: "; 
    ans = inorder(stack[top]); 
    if (ans != 0)
    	cout<<")"<<endl;
	
	cout<<"Print level display below"<<endl;
	levelDisplay(stack[top]);

return(0);
}
