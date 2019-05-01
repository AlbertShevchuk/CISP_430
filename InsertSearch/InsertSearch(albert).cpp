#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
ifstream in; 

struct BinaryTree 
{
	char name[30];
    struct BinaryTree *left;
    struct BinaryTree *right;
    struct node *names;   
};

struct node 
{
	char name[30];
	struct node* next;
};

typedef struct BinaryTree tree;
typedef struct node node;

int main()
{			
	in.open("input.txt");
	tree *head , *curr;
	node *nCurr;
	head = NULL;
	nCurr = NULL;
	char temp[30] = {NULL};
	bool flag = 1;
	int duplicates;
				
	while((in>>temp)!=NULL)
	{	
		if(!head)
		{
			head = (tree *)malloc(sizeof(tree));
			strcpy (head->name,temp);
			head->left = NULL;
			head->right = NULL;
			head->names = NULL;
			curr = head;
			flag = 0;
		}
		else
		{	
			while(flag)
			{
				if(((strcmpi(curr->name, temp)) > 0) && (curr->right == NULL))
				{
					curr->right = (tree *)malloc(sizeof(tree));
					strcpy (curr->right->name,temp);
					curr->right->left = NULL;
					curr->right->right = NULL;
					curr->right->names = NULL;
					flag = 0;
				}
				else if(((strcmpi(curr->name, temp)) < 0) && (curr->left == NULL))
				{
					curr->left = (tree *)malloc(sizeof(tree));
					strcpy (curr->left->name,temp);
					curr->left->left = NULL;
					curr->left->right = NULL;
					curr->left->names = NULL;
					flag = 0;
				}
				else if((strcmpi(curr->name, temp)) == 0)
				{	
					if(curr->names == NULL)
					{
						curr->names = (node *)malloc(sizeof(node));
						strcpy (curr->names->name,temp);
						curr->names->next = NULL;
						nCurr = curr->names;
						flag = 0;
					}
					else 
					{
						for(nCurr = curr->names; nCurr->next != NULL; nCurr = nCurr->next )
						{ }		
						nCurr->next = (node *)malloc(sizeof(node));
						strcpy (nCurr->next->name,temp);
						nCurr->next->next = NULL;
						flag = 0;		
					}						
				}
				else
				{
					if(strcmpi(curr->name, temp) > 0)
					{
						curr = curr->right;
						flag = 1;
					}
					else if (strcmpi(curr->name, temp) < 0)
					{
						curr = curr->left;
						flag = 1;
					}		
				}
			}
		}	
		temp[0]= {NULL};
		flag = 1;
		curr = head;
		nCurr = head->names;
	}	
	
	cout<<"Enter a Name to Serch in the Tree: ";
	cin>>temp;
	flag = 1;
	nCurr = head->names;
	curr = head;
	int level = 1;
	
	while(flag)
	{
		cout<<"Level: "<<level<<endl;
		if((strcmpi(curr->name, temp)) > 0) 
		{
			if(curr->right == NULL)
			{
				cout<<temp<<" does not exist in this Tree"<<endl;
				break;
			}
			curr = curr->right;
			cout<<"Right"<<endl;
			level++;
		}
		else if((strcmpi(curr->name, temp)) < 0) 
		{
			if(curr->left == NULL)
			{
				cout<<temp<<" does not exist in this Tree"<<endl;
				break;
			}
			curr = curr->left;
			cout<<"Left"<<endl;
			level++;
		}
		else if((strcmpi(curr->name, temp)) == 0)
		{
			cout<<temp<<" has been found on level: "<<level<<endl;
			if(curr->names == NULL)
			{
				flag = 0;
				cout<<"No duplicates were found!"<<endl;
			}
			else 
			{
				duplicates = 1;
				for(nCurr = curr->names; nCurr->next != NULL; nCurr = nCurr->next , ++duplicates )
				{ }
				cout<<"Ammount of duplicates found: "<<duplicates<<endl;
				flag = 0;		
			}						
		}
	}
					
return(0);
}
