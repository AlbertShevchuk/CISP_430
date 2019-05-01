/*
Zia Rehman
CISP 430 Prof. Sabzevary
MW 7-8:20PM
Group Queue P6
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct node {
     int num;
     node *next;
};

int clean(ifstream &in){
    string comments;  //store the comments in this variable
    while (in.peek()=='\n' || in.peek()=='/' || in.peek()==' ' || in.peek()=='\t'){
        if (in.peek()=='/' )
           getline(in, comments);  //read the entire line because it is a comment
        else
            in.get();    //eat the newline, space and tab characters
    }
    return 1;
}

ifstream in;

void enqueue(int num, struct node *&front, struct node*&rear){

    struct node *newNode=new node;
    newNode->num=num;
    newNode->next=NULL;
    if (rear){
        rear->next = newNode;
        rear = newNode;
   }else
        front = rear = newNode;
}

void dequeue(struct node *& front, struct node *& rear){
    struct node *temp;

    if(front){
        temp= front;
        front = front->next;
        delete temp;
    }

    if (!front)
       rear =NULL;
}

void neg(struct node *&frontq, struct node*&rear){

    struct node *temp;

    while (frontq->num < 0){
        dequeue(frontq, rear);
    }

    enqueue(frontq->num, frontq, rear);
    dequeue(frontq, rear);

    temp = rear;

    while (frontq != temp){
        if (frontq->num < 0){
            dequeue(frontq, rear);
        }
        else{
            enqueue(frontq->num, frontq, rear);
            dequeue(frontq, rear);
        }
    }
}

void PrintQueue(struct node* head){
    struct node* current = head;
    while (current != NULL) {
        cout << current->num << endl;
        current = current->next;
    }
}

int main(){
    int num = 0;

    struct node * frontq, * rear;
    frontq = rear =NULL;
    
    in.open("input.txt");

    while (clean(in) && in.good()){
        in >> num;
        enqueue(num, frontq, rear);
    }

    cout << "Queue before negative removal: " << endl;
    PrintQueue(frontq);

    if (frontq != NULL){
        neg(frontq, rear);
        cout << "Queue with only positive values: " << endl;
        PrintQueue(frontq);
    }
    else{
        cout << "The input file is empty" << endl;
    }

    in.close();
    in.clear();

    return 0;
}
