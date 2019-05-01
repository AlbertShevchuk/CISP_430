/*
Zia Rehman
CISP 430
Professor Sabzevary
MW 7:00PM - 8:20PM
Group DeleteTree P12
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream in;
ofstream out;

typedef struct TreeNode
{
    int number;
    TreeNode *left;
    TreeNode *right;
}TreeNode;

void readFile(TreeNode *&root);
void insert(TreeNode *&root, int num);
bool deleteNode(int num, TreeNode *nodePtr, TreeNode *parentPtr);
void preOrder(TreeNode *root);
void inOrder(TreeNode *root);
void postOrder(TreeNode *root);
int convertToInt(char *temp);


void readFile(TreeNode *&root)
{
    in.open("input.txt");
    out.open("output.txt");

    char temp[10];
    int tempNumber;
    bool found;

    while(in >> temp)
    {
        if(strcmp(temp, "delete")==0)
        {
            in >> temp;
            tempNumber = convertToInt(temp);
            found = deleteNode(tempNumber, root, root);

            if(!found)
                insert(root, tempNumber);

            out<<"PreOrder: ";
            preOrder(root);
            out<<endl;
                        
            out<<"InOrder: ";
            inOrder(root);
            out<<endl;
                        
            out<<"PostOrder: ";
            postOrder(root);
            out<<endl;
        }
        else
        {
            tempNumber = convertToInt(temp);
            insert(root, tempNumber);
        }
    }
    in.close();
}

void insert(TreeNode *&root, int num)
{
	TreeNode *temp, *nodePtr;
	temp = new TreeNode;
	temp->number = num;
	temp->left = temp->right = NULL;

	if(!root)
        root = temp;
    else
    {
        nodePtr = root;
        while(nodePtr!=NULL)
        {
            if(num < nodePtr->number)
            {
                if(nodePtr->left)
                    nodePtr = nodePtr->left;
                else
                {
                    nodePtr->left=temp;
                    break;
                }
            }
            else if(num > nodePtr->number)
            {
                if(nodePtr->right)
                    nodePtr = nodePtr->right;
                else
                {
                    nodePtr->right = temp;
                    break;
                }
            }
        }
    }
}

bool deleteNode(int num, TreeNode *nodePtr, TreeNode *parentPtr)
{
    bool found=false;
    if(nodePtr==NULL)
        return false;
    else if(num < nodePtr->number)
        deleteNode(num, nodePtr->left, nodePtr);
    else if(num > nodePtr->number)
        deleteNode(num, nodePtr->right, nodePtr);
    else
    {
        found = true; 
        return found;
    }
}

void preOrder(TreeNode *root)
{
    if(root != NULL)
    {
        out<<root->number<<" ";
		preOrder(root->left);
		preOrder(root->right);
    }
}

void inOrder(TreeNode *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
		out<<root->number<<" ";
		inOrder(root->right);
    }
}

void postOrder(TreeNode *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
	 	postOrder(root->right);
		out<<root->number<<" ";
    }
}

int convertToInt(char *temp)
{
    int number=0, numDig, i=0, n=1;

    while(temp[i]!='\0')
        i++;

    numDig = i;

    for(int j=numDig-1; j>=0; j--)
    {
        number = (temp[j]-48)*(n);
        n = n*10;
    }
    return number;
}

int main()
{
    TreeNode *root=NULL;
    readFile(root);
    
    return 0;
}
