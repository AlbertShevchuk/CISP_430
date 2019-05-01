/*
Zia Rehman
CISP 430
Professor Sabzevary
MW 7:00PM - 8:20PM
Group Recursive Comma P10
*/

#include <iostream>
#include <cstdlib>
using namespace std;

char* putCommas(long dig, int i, int j)
{
    char *array;
    array = (char*)malloc(sizeof(char));
    if(dig<=999)
    {
        array[(i*3)+j] = (dig%10) +48; //casting done to convert from int to char
        array[(i*3)+j+1] = ((dig/10)%10) +48;
        array[(i*3)+j+2] = (dig/100) +48;
    }
    else if(dig>=999)
    {
        array = putCommas((dig/1000), i+1, j+1);
        array[(i*3)+j] = ((dig%1000)%10) +48;
        array[(i*3)+j+1] = (((dig%1000)/10)%10) +48;
        array[(i*3)+j+2] = ((dig%1000)/100) +48;
        array[(i*3)+j+3] = ',';
    }
    return array;
}

int length(long x)
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


char* reverseArray(char *array, int size)
{
    char *temp = (char*)malloc(sizeof(char)*size);

    for(int i=0, j=size-1; j>=0; i++, j--)
        temp[j] = array[i];

    for(int i=0; i<size; i++)
        array[i] = temp[i];

    free(temp);

    return array;
}

int main()
{
    int i=0, j=0;
    long digits=0;
    char *array = (char*)malloc(sizeof(char)*(length(digits)+((length(digits)-1)/3)));

    cout << "Enter digits: " <<endl;
    cin >> digits;
    cout << endl;
    array = putCommas(digits, i, j);
    array = reverseArray(array, ((length(digits)+((length(digits)-1)/3))));
    cout << "Here is your number: " <<endl;

    for(int i=0; i<((length(digits)+((length(digits)-1)/3))); i++)
        cout<<array[i];
    cout << endl;
    return 0;
}
