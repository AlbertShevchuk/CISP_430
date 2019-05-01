#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
ifstream in; 
ofstream out;

struct tree
{
	int data;						
	struct tree *left;	
	struct tree *right;
};

typedef struct tree tree;

void inOrder(tree *&curr)
{
	if(curr != NULL)
	{
		inOrder(curr->left);
		out<<curr->data<<" ";
		inOrder(curr->right);
	}
}

void pre(tree *&curr)
{
	if(curr != NULL)
	{
		out<<curr->data<<" ";
		pre(curr->left);
		pre(curr->right);
	}
}

void post(tree *&curr)
{
	if(curr != NULL)
	{
		post(curr->left);
		post(curr->right);
		out<<curr->data<<" ";
	}
}

deleteReconect(tree *&curr, tree *&B4, tree *&head)
{
	tree *Temp = NULL;
	bool found = 0;
	
	if((curr->right == NULL) && ((curr->left == NULL)))
	{
		if(curr->data == B4->data)
		{
			delete curr;
			head = NULL;
			out<<"You have deleted the last item on the tree and at this point the tree is empty"<<endl;
		}
		else 
		{	
			if(B4->right != NULL)
			{
				if(B4->right->data == curr->data) 
				{
					(B4->right = B4->right->left); 
				}
				else	 
				{
					(B4->left = B4->left->left);
				}
			}
			else if(B4->left != NULL)
			{
				if(B4->left->data == curr->data) 
				{
					(B4->left = B4->left->left); 
				}
				else	 
				{
					(B4->right = B4->right->left);
				}
			}
			delete curr;
		}
	}
	else if((curr->right != NULL) && ((curr->left == NULL)))
	{
		if(curr->data == B4->data)
		{
			head = curr->right;
			delete curr;	
		}
		else 
		{
			if(B4->right != NULL)
			{
				if(B4->right->data == curr->data) 
				{
					  (B4->right = B4->right->left); 
				}
				else	 
				{
					(B4->left = B4->left->left);
				}
			}
			else if(B4->left != NULL)
			{
				if(B4->left->data == curr->data) 
				{
					  (B4->left = B4->left->left); 
				}
				else	 
				{
					(B4->right = B4->right->left);
				}
			}
			delete curr;
		}
	}
	else if((curr->right == NULL) && ((curr->left != NULL)))
	{
		if(curr->data == B4->data)
		{
			head = curr->left;
			delete curr;
		}
		else 
		{
			if(B4->right != NULL)
			{
				if(B4->right->data == curr->data) 
				{
					(B4->right = B4->right->left); 
				}
				else	 
				{
					(B4->left = B4->left->left);
				}
			}
			else if(B4->left != NULL)
			{
				if(B4->left->data == curr->data) 
				{
					(B4->left = B4->left->left); 
				}
				else	 
				{
					(B4->right = B4->right->left);
				}
			}
			delete curr;
		}
	}
	else
	{
		curr->data = curr->right->data;
		Temp = curr->right;
		
		do
		{
			if(Temp->left == NULL)
				found = 1;
			else
			{
				B4 = Temp;
				Temp = Temp->left;
			}
		}
		while(!found);
		
		if(curr->data == Temp->data)   
		{
			if(Temp->right == NULL)
			{
				curr->right = NULL;
				delete Temp;	
			}
			else
			{
				curr->right = Temp->right;
				delete Temp;
			}
		}
		else
		{
			(curr->data = Temp->data);
			B4->left = NULL;
			delete Temp;
		}
	}
}

add(tree *&curr, int temp)
{
	if(((temp > curr->data)) && (curr->right == NULL))
	{
		curr->right = (tree *)malloc(sizeof(tree));
		curr->right->data = temp;
		curr->right->left = NULL;
		curr->right->right = NULL;
	}
	else if(((temp < curr->data)) && (curr->left == NULL))
	{
		curr->left = (tree *)malloc(sizeof(tree));
		curr->left->data = temp;
		curr->left->left = NULL;
		curr->left->right = NULL;
	}
	else
	{
		if((temp > curr->data))
			add(curr->right, temp);
		else if ((temp < curr->data))
			add(curr->left, temp);
	}
}

nameFind(tree *&curr, int temp, tree *&head)
{
	
	int loop = 1;
	tree *B4 = curr;
		
	do
	{
		if((temp == curr->data))  
		{
			deleteReconect(curr, B4, head);
			loop = 1;
			return 1;
		}
		else if(((temp > curr->data)) && (curr->right != NULL))
		{
			B4 = curr;
			curr = curr->right;
		}
		else if(((temp < curr->data)) && (curr->left != NULL))
		{
			B4 = curr;
			curr = curr->left;
		}
		else
		{ 
			loop = 0;
			return 0;
		}
	}
	while(loop);
}

addHead(tree *&head, int temp)
{
	head = (tree *)malloc(sizeof(tree));
	head->data = temp;
	head->left = NULL;
	head->right = NULL;		
}

main()
{
	in.open("input.txt");
	out.open("output.txt");
	
	int number = 0;	
	char temp[9];	
	tree *head = NULL;
	tree *curr = NULL;																				 
	bool deleteFind = 1;
																							
	while((in>>temp)!=NULL)	
	{
		if((strcmp (temp,"delete")) == 0)
		{
			in >> number;
			
			if(!head)
				addHead(head, number);
			else
			{
				curr = head;
				deleteFind = nameFind(curr, number, head);
				
				if(deleteFind == 0)
				{
					curr = head;
					add(curr, number);
				}
			}
		}
		else
		{
		    number	= atoi(temp);
			if(!head)
				addHead(head, number);	
			else
			{
				curr = head;
				add(curr, number);		
			}
		}
	}

	curr = head;
	out<<"Pre-Order: ";
	pre(curr);
	out<<endl<<endl;
	out<<"In-Order: ";
	curr = head;
	inOrder(curr);
	out<<endl<<endl;
	out<<"Post-Order: ";
	curr = head;
	post(curr);
	in.close();																						// close the file
   	out.close(); 
	in.clear(); 
	
	cout<<"Done, check output.txt";
	
return(0);
}
