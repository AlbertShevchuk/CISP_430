/*
Zia Rehman
CISP 430
Professor Sabzevary
MW 7:00PM - 8:20PM
Group Postfix Evaluate Project 7.5
*/
#include <iostream>
#include <fstream>
using namespace std;
ofstream out;

struct node
{
    char item;
    struct node *next;
};
typedef struct node node;

struct results
{
	int num;
	struct results *next;
};
typedef struct results results;	

node *push(node *top, char data)
{
    if ( top == '\0' )
    {
        top = new node;
        top->next = '\0';
        top->item = data;
    }
    else
    {
        node *temp = new node;
        temp->item = data;
        temp->next = top;
        top = temp;
    }
    return top;
}

node *pop(node *top)
{
    if ( top->item != '(')
        out << top->item;
    node *temp = top;
    top = top->next;
    delete temp;
    return top;
}

results *push(results *num, int result)
{
    if ( num == '\0' )
    {
        num = new results;
        num->next = '\0';
        num->num = result;
    }
    else
    {
        results *temp = new results;
        temp->num = result;
        temp->next = num;
        num = temp;
    }
    return num;
}

int pop(results *&num)
{
    int a;
    results *temp=num;
    num=num->next;
    a=temp->num;
    delete temp;
    return a;
}

char print(node *top)//go through and print the items through return
{
    return top->item;
}

int evaluate(char eval, int op1, int op2)
{
    switch ( eval )
    {
        case '+':
            op1 += op2;
            break;
        case '-':
            op1 -= op2;
            break;
        case '*':
            op1 *= op2;
            break;
        case '/':
            op1 /= op2;
            break;
    }
    return op1;
}

int main()
{
    node *top = '\0';
    ifstream in("input.txt");
    out.open("postfix.txt");
    char data, temp;
  
  
        
    while (in.good() && in.peek()!=EOF)
    {
        in >> data;
        if ( data >= '0' && data <= '9' )
                  
			out << data;
        else if ( data == '+' || data == '-'|| data == '*' || data == '/' )
        {
            if ( top == '\0' )
                top = push(top, data); //if top is null, start adding things onto it
            else
            {
                temp = print(top);       //if operator is > in precedence
                if ( (data == '*' || data == '/') && (temp == '+' || temp == '-') )
                    top = push(top, data);
                else
                {                           //checking precedence of operator
                    while ( !( (data == '*' || data == '/') && (temp == '+' || temp == '-') ) && top != '\0' && temp != '(' )
                    {
                        top = pop(top);
                        if ( top != '\0' )
                            temp = print(top);
                    }
                    top = push(top, data);
                }
            }
        }
        else if ( data == '(' )
        {
            top = push(top, data);
        }
        else
        {
            while ( print(top) != '(' )
            {
                top = pop(top);
            }
        }
    }
    while ( top != '\0' )
        top = pop(top); //print out everything on the stack
    
    in.close();
    in.clear();
    out.close();
    in.open("postfix.txt");
	
	results *operands = '\0';
    int cast, op1, op2;
    while ( in.good() && in.peek()!=EOF )
    {
        in >> data;
        if ( data >= '0' && data <= '9' )
        {
            cast = data - '0';
            operands = push( operands, cast );
        }
        else
        {
            op2 = pop( operands );
            op1 = pop( operands );
            operands = push( operands, evaluate(data, op1, op2));
        }
    }

    op1 = pop( operands );
    cout << op1;

    in.close();

    return 0;
}
