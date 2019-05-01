#include <iostream>
using namespace std;

int partition(int a[], int first, int last)
{
    int piv ot = a[last], index = first;  
   
    for(int i = first; i < last; i++)
	{
		if(a[i] >= pivot)
		{
			swap(a[i],a[index]);
			index++;		
		}		
    } 
    
	swap(a[index],a[last]); 
	return(index);
}

void quickSort(int a[], int start, int end)
{
    int pIndex;
	if(start<end)
  	{      
		pIndex=partition(a,start,end);   
		quickSort(a, start, pIndex-1);   
		quickSort(a, pIndex+1, end);     
	}
}

int main()
{
	 int a[]={3,0,1,8,7,2,4,6,8,1,3};

	for(int counter = 0; counter<=10; counter++)
		cout<<a[counter];

	cout<<endl;
 	quickSort(a,0,10);  
 	
 	for(int counter = 0; counter<=10; counter++)
		cout<<a[counter];
		
return(0);
}

