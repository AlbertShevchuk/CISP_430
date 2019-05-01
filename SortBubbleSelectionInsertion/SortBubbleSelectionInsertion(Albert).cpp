#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

bubbleSort(int arr[][4])
{
    int temp, index, limit = 4;
		
	for (;limit > 0; limit--)
	{
    	for (index=0; index<limit; index++)
      	{
       		if (arr[index][0] > arr[index+1][0])
      		{
				temp=arr[index][0];
      			arr[index][0]=arr[index+1][0];
      			arr[index+1][0]=temp;
      		}
      	}
   	}
   
cout<<endl<<"After Bubble Sort"<<endl<<endl;	
	
	for(int i = 0 ; i <= 4 ; i++ )
	{
		for(int ii = 0 ; ii <= 3 ; ii++ )
		{
			cout<<arr[i][ii];
		}
		cout<<endl;	
	}
}

selectionSort(int arr[][4])
{
	int temp, index_of_largest,index, limit =4;
 
 	for(;limit > 0;limit--)
	{	
   		index_of_largest=0 ;
	
    	for (index=1; index <= limit; index++)
		{	
			if (arr[index][1] < arr[index_of_largest][1])
      			index_of_largest=index;  	  
      	}
		if (limit != index_of_largest)
		{
    		temp=arr[limit][1];
   			arr[limit][1]=arr[index_of_largest][1];
   			arr[index_of_largest][1]=temp;
		}
   	}
   	
cout<<endl<<"After Selection Sort"<<endl<<endl;	
	
	for(int i = 0 ; i <= 4 ; i++ )
	{
		for(int ii = 0 ; ii <= 3 ; ii++ )
		{
			cout<<arr[i][ii];
		}
		cout<<endl;	
	}
}

insertionSort(int arr[][4])
{
	int i, j ,tmp ,SIZE = 4;
	
	for (i = 1; i < SIZE; i++) 
	{ 
		for (j=i; j>0 && arr[4][j] < arr[4][j-1];j--)
		{
			tmp = arr[4][j];
			arr[4][j] = arr[4][j - 1];
			arr[4][j - 1] = tmp;
		}
	}
	
cout<<endl<<"After Insertion Sort"<<endl<<endl;	
	
	for(int i = 0 ; i <= 4 ; i++ )
	{
		for(int ii = 0 ; ii <= 3 ; ii++ )
		{
			cout<<arr[i][ii];
		}
		cout<<endl;	
	}
}

int binarySearch(int A[][4], int key)
{
	int SIZE = 4;
	int high = SIZE-1, low = 0, mid;
	bool found=false;
  
	while (high >= low && !found)
	{
    	mid = (high + low ) / 2;
      	if (key>A[4][mid] )
			low = mid + 1;
		else if (key<A[4][mid])
			high = mid - 1;
		else
			found=true;     
	}
return found;
}

int main()
{
	int arr[5][4] = { { 5, 4, 6, 7 }, { 3, 7, 9, 2 }, { 2, 5, 8, 4}, { 2, 2, 2, 2 }, { 0, 7, 3, 2 } };
	int arrTemp[5][4];
	
	cout<<"ORIGINAL ARRAY"<<endl<<endl;	
	
	for(int i = 0 ; i <= 4 ; i++ )
	{
		for(int ii = 0 ; ii <= 3 ; ii++ )
		{
			cout<<arr[i][ii];
		}
		cout<<endl;	
	}
	
	memcpy(arrTemp, arr, sizeof (int) * 5 * 4);
	bubbleSort(arrTemp);
	memcpy(arrTemp, arr, sizeof (int) * 5 * 4);
	selectionSort(arrTemp);
	memcpy(arrTemp, arr, sizeof (int) * 5 * 4);
	insertionSort(arrTemp);
	
	int searchKey = 0;
	cout<<endl<< "What number do you want to search for in the 5th row? ";
	cin >> searchKey;
	if (binarySearch(arrTemp,searchKey))
		cout << "Found";
	else
		cout <<"Not found";  

return (0);
}
