/*
Zia Rehman
CISP 430
Professor Sabzevary
MW 7:00PM - 8:20PM
Group RadixSort P8.5
*/
#include <iostream>
#include <fstream>
using namespace std;

typedef struct queueNode
{
    int number;
    queueNode *next;
}queueNode;

typedef struct queuearray
{
    queueNode *queue0;
    queueNode *queue1;
    queueNode *queue2;
    queueNode *queue3;
    queueNode *queue4;
    queueNode *queue5;
    queueNode *queue6;
    queueNode *queue7;
    queueNode *queue8;
    queueNode *queue9;
}queuearray;

int readFile(int array[]);
int largestNumber(int a[], int size);
int length(int x);
void radixSort(int a[], int size);
void enqueue(int tempNumber, queueNode *&front, queueNode *&rear);
int dequeue(queueNode *&front, queueNode *&rear);


int main()
{
    int array[10], size;

    size = readFile(array);
    radixSort(array, size);
  
    for(int i=0; i<size; i++)
        cout << array[i] << " ";
    cout<<endl<<endl;

}


int readFile(int array[])
{
    ifstream in("input.txt");

    int input, i=0;

    while(in >> input)
    {
        array[i] = input;
        i++;
    }

    in.close();

    return i;
}

int largestNumber(int a[], int size)
{
    int largest=a[0];
    for(int i=1; i<size; i++)
    {
        if(a[i]>largest)
            largest=a[i];
    }

    return largest;
}

int length(int x)
{
    if(x>=1000000000) return 10;
    if(x>=100000000) return 9;
    if(x>=10000000) return 8;
    if(x>=1000000) return 7;
    if(x>=100000) return 6;
    if(x>=10000) return 5;
    if(x>=1000) return 4;
    if(x>=100) return 3;
    if(x>=10) return 2;
    return 1;
}

void radixSort(int a[], int size)
{
    queuearray queuearray1;
    queueNode *front0=NULL, *front1=NULL, *front2=NULL, *front3=NULL,
              *front4=NULL, *front5=NULL, *front6=NULL, *front7=NULL,
              *front8=NULL, *front9=NULL, *rear0=NULL, *rear1=NULL,
              *rear2=NULL, *rear3=NULL, *rear4=NULL, *rear5=NULL,
              *rear6=NULL, *rear7=NULL, *rear8=NULL, *rear9=NULL;
    int sd=0, m=10, n=1, max = length(largestNumber(a, size));

    while(sd<max)
    {
        for(int i=0; i<size; i++)
        {
            if(((a[i]%m)/n)==0)
                enqueue(a[i], front0, rear0);
            else if(((a[i]%m)/n)==1)
                enqueue(a[i], front1, rear1);
            else if(((a[i]%m)/n)==2)
                enqueue(a[i], front2, rear2);
            else if(((a[i]%m)/n)==3)
                enqueue(a[i], front3, rear3);
            else if(((a[i]%m)/n)==4)
                enqueue(a[i], front4, rear4);
            else if(((a[i]%m)/n)==5)
                enqueue(a[i], front5, rear5);
            else if(((a[i]%m)/n)==6)
                enqueue(a[i], front6, rear6);
            else if(((a[i]%m)/n)==7)
                enqueue(a[i], front7, rear7);
            else if(((a[i]%m)/n)==8)
                enqueue(a[i], front8, rear8);
            else if(((a[i]%m)/n)==9)
                enqueue(a[i], front9, rear9);
        }

        for(int i=0; i<size; i++)
        {
            if(front0!=NULL)
                a[i] = dequeue(front0, rear0);
            else if(front1!=NULL)
                a[i] = dequeue(front1, rear1);
            else if(front2!=NULL)
                a[i] = dequeue(front2, rear2);
             else if(front3!=NULL)
                a[i] = dequeue(front3, rear3);
            else if(front4!=NULL)
                a[i] = dequeue(front4, rear4);
            else if(front5!=NULL)
                a[i] = dequeue(front5, rear5);
            else if(front6!=NULL)
                a[i] = dequeue(front6, rear6);
            else if(front7!=NULL)
                a[i] = dequeue(front7, rear7);
            else if(front8!=NULL)
                a[i] = dequeue(front8, rear8);
            else if(front9!=NULL)
                a[i] = dequeue(front9, rear9);
        }

        sd++;
        n=n*10;
        m=m*10;
    }

    for(int i=0; i<size; i++)
    {
        if(front0!=NULL)
            a[i] = dequeue(front0, rear0);
        else if(front1!=NULL)
            a[i] = dequeue(front1, rear1);
        else if(front2!=NULL)
            a[i] = dequeue(front2, rear2);
        else if(front3!=NULL)
            a[i] = dequeue(front3, rear3);
        else if(front4!=NULL)
            a[i] = dequeue(front4, rear4);
        else if(front5!=NULL)
            a[i] = dequeue(front5, rear5);
        else if(front6!=NULL)
            a[i] = dequeue(front6, rear6);
        else if(front7!=NULL)
            a[i] = dequeue(front7, rear7);
        else if(front8!=NULL)
            a[i] = dequeue(front8, rear8);
        else if(front9!=NULL)
            a[i] = dequeue(front9, rear9);
    }

}

void enqueue(int tempNumber, queueNode *&front, queueNode*&rear)
{
    queueNode *temp=new queueNode;

    temp->number=tempNumber;
    temp->next=NULL;
    if (rear)
    {
        rear ->next=temp;
        rear =temp;
    }
    else
        front =rear =temp;
}

int dequeue(queueNode *&front, queueNode *&rear)
{
    int number;
    queueNode *temp;

    if(front)
    {
        temp=front;
        front =front->next;
        number=temp->number;
        delete temp;
    }

    if (!front)
        rear =NULL;

    return number;
}

