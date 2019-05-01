/*
Zia Rehman
CISP 430 Prof. Sabzevary
MW 7-8:20PM
Group Stacks P5
*/


#include <iostream>
#include<iomanip>
#include<stack>
using namespace std;

struct node 
{
int item;
node *next;
};

void pop(struct node *&top)
{
struct node *temp;
if(top)
 {	
 temp=top;
 top=top->next;
 delete temp;
 }
}

void push(int item, struct node *&top)
{
struct node *newNode=new node;
newNode->item=item;
newNode->next=top;
top=newNode;
}

void binary(int number)
{
	int remainder;

	if(number <= 1) 
	{
		cout << number;
		return ;
	}
	remainder = number%2;
	binary(number >> 1);    
	cout << remainder;
}


void hex(int item, struct node *&top)
{
    int remainder;
     /*
     for(;item!=0;)
     {
     	remainder=item%16;
     	item=item/16;
     	push(remainder, *&top);
     	cout<<remainder<<endl;
	 }*/
    do
    {
        remainder = item % 16; 
        item = item/16;
        push(item, *&top);
        cout<<item;
    }
    while(item!=0); 
}

void hexa(int item, struct node *&top)
{
    
	int counter = 0, x[80], i = 0;
	char copyChar;

   

	while (item > 0 )
    {
         x[i] = item % 16;
         item = item/16;

		switch(x[i])
        {
            case 0:
                copyChar = '0'; break;
            case 1:
                copyChar = '1'; break;
            case 2:
                copyChar = '2'; break;
            case 3:
                copyChar = '3'; break;
            case 4:
                copyChar = '4'; break;
            case 5:
                copyChar = '5'; break;
            case 6:
                copyChar = '6'; break;
            case 7:
                copyChar = '7'; break;
            case 8:
                copyChar = '8'; break;
            case 9:
                copyChar = '9'; break;
            case 10:
                copyChar = 'A'; break;
            case 11:
                copyChar = 'B'; break;
            case 12:
                copyChar = 'C'; break;
            case 13:
                copyChar = 'D'; break;
            case 14:
                copyChar = 'E'; break;
            case 15:
                copyChar = 'F'; break;
        }

        push(item, *&top);
        cout<<copyChar;
        i++;
	}

}

int main()
{
  int item;
  struct node *top=NULL;
   //stack<int> mystack;
  
 
  if(!top)
  {
  	cout<<"The stack is empty"<<endl;
  	cout<<"Enter a number so we can build the list"<<endl;
  	cin>>item;
  	push(item, *&top);
  	cout<<"The decimal number " << item << " converted to binary is "<<endl;
    binary(item);
    cout<<" "<< endl;
    cout<<"The decimal number " << item << " converted to hex is "<<  "0x";
	hexa(item, *&top);
	cout<<" "<<endl;
  	pop(*&top);
  }
  else
  {
  	push(item, *&top);
  	
      //pop(*&top);
  	//cout<<top<<endl;
  }
  
 //cout<<"Enter an integer"<<endl;
 // cin>>number;
 //cout<<"The decimal number " << number << " converted to binary is "<<endl;
 //binary(number);
 //cout<<number<<endl;
 //cout<<"Enter a number to be converted to hexadecimal"<<endl;
 //cin>>test;
 //cout<<"The decimal number " << number << " converted to hex is "<<  "0x" << hex <<number<<endl;
 
 push(10,top);
 pop(top);
 
 return 0;
}
