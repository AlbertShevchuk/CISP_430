/*
Zia Rehman
CISP 430
Professor Sabzevary
MW 7:00PM - 8:20PM
Group Recursive MergeSort P11.5
*/
#include <iostream>
using namespace std;

typedef struct Node * nodePtr;

struct Node
{
    int data;
    nodePtr next;
};

nodePtr globalHead;

void printList(nodePtr head)
{
    nodePtr current = head;
    while(current != NULL){
        cout<<current->data;
        current = current->next;
    }
   cout<<endl;//printf("\n");
}

void partition(nodePtr head, nodePtr *front, nodePtr *back){

    nodePtr fast;
    nodePtr slow;

    if (head == NULL || head->next == NULL){

        *front = head; // &a
        *back = NULL; // &b

    }else{

        slow = head;
        fast = head->next;

        while(fast != NULL){

            fast = fast->next;

            if(fast != NULL){

                slow = slow->next;
                fast = fast->next;

            }

        }

        *front = head; // a
        *back = slow->next; // b
        slow->next = NULL;
        printList(*front);
        printList(*back);

    }

}

nodePtr mergeLists(nodePtr a, nodePtr b){

    nodePtr mergedList = NULL;

    if (a == NULL){
        return b;
    }else if (b == NULL){
        return a;
    }

    if (a->data <= b->data){
        mergedList = a;
        mergedList->next = mergeLists(a->next, b);
    }else{
        mergedList = b;
        mergedList->next = mergeLists(a, b->next);
    }

    return mergedList;

}

void mergeSort(nodePtr *source){

    nodePtr head = *source;
    nodePtr a = NULL;
    nodePtr b = NULL;

    if(head == NULL || head->next == NULL){

        return;

    }

    partition(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *source = mergeLists(a, b);

}

void push(nodePtr *head, int data){

    nodePtr newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if ((*head) == NULL){
        *head = newNode;
        globalHead = *head;
    }else{
        (*head)->next = newNode;
        *head = newNode;
    }

}



// *head = head in the main function,
// it is only there to connect the two and
// not let make the function return anything
// passed by reference
// globalHead points to the start of the linked list
// if you are passing the address over here you have to
// make a double pointer over there in the function

int main(void)
{
    nodePtr head = NULL;

    // linked list is formed from top to bottom fashion
    // push is done in constant time O(1)

    push(&head, 4); // |
    push(&head, 3); // |
    push(&head, 1); // |
    push(&head, 5); // |
    push(&head, 7); // V

    printList(globalHead);

    mergeSort(&globalHead);

    printList(globalHead);

    return 0;
}

