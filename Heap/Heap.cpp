#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void readFile(int array[], int &n);
void insert(int array[], int num, int &n);
void printLevel(int array[], int n);
void deleteFive(int array[], int &n);
void deleteNode(int array[], int &n);
int smallerChild(int array[], int i, int n);

//=========================================================================\\

int main()
{
    int array[10], numOfNodes=0;

    readFile(array, numOfNodes);
    cout << endl;
    cout << "Before Delete" << endl;
    cout << "______________________________________" << endl;
    printLevel(array, numOfNodes);
    cout << endl << endl;
    deleteFive(array, numOfNodes);
}

//=========================================================================\\

void readFile(int array[], int &n)
{
    ifstream in("input.txt");

    int temp, i=0;

    while( (in >> temp) && (i<10) )
    {
        insert(array, temp, n);
        n++;
        i++;
    }

    in.close();
}

//=========================================================================\\

void insert(int array[], int num, int &n)
{
    int parentnode, location=n;

    while (location > 0)
    {
        parentnode =(location - 1)/2;
        if (num >= array[parentnode])
        {
            array[location] = num;
            return;
        }

        array[location] = array[parentnode];

        location = parentnode;
    }

    array[0] = num;


}

//=========================================================================\\

void printLevel(int array[], int n)
{
    if(n==0)
    {
        cout << "EMPTY!!";
        return;
    }

    for(int i=0; i<n; i++)
    {
        cout << setw(3) <<array[i] << "   ";
        if( (i==0) || (i==2) || (i==6) || (i==14) )
            cout << endl;
    }
}

//=========================================================================\\

void deleteFive(int array[], int &n)
{
    cout << endl;
    for(int i=0; i<5; i++)
    {
        deleteNode(array, n);
        cout << "After Delete #" << i+1 << endl;
        cout << "______________________________________" << endl;
        printLevel(array, n);
        cout << endl << endl << endl;
    }
}

//=========================================================================\\

void deleteNode(int array[], int &n)
{
    int left, right, temp, parentNode, i=n, childToSwap;

    array[0]=array[n-1];
    n--;

    parentNode=(i-1)/2;
    if(array[i] < array[parentNode])
    {
        insert(array, array[i], i);
        return;
    }

    left=2*i+1;
    right=2*i+2;
    while(right < n)
    {
        if((array[i] <= array[left]) && (array[i] <= array[right]))
            return;
        if(array[right] >= array[left])
        {
            temp = array[i];
            array[i] = array[left];
            array[left] = temp;
            i = left;
        }
        else
        {
            temp = array[i];
            array[i] = array[right];
            array[right] = temp;
            i = right;
        }
        left=2*i+1;
        right=2*i+2;
    }

    if(left == n-1 && array[i])
    {
        temp = array[i];
        array[i] = array[left];
        array[left] = temp;
    }

    i=0;
    while(i*2+1 < n)
    {
        childToSwap = smallerChild(array, i, n);
        temp = array[childToSwap];
        array[childToSwap] = array[i];
        array[i] = temp;

        i=childToSwap;
    }


}

//=========================================================================\\

int smallerChild(int array[], int i, int n)
{
    int left=2*i+1, right=2*i+2;

    if(right >= n)
        return left;
    else if(array[left] <= array[right])
        return left;
    else
        return right;
}

//=========================================================================\\

