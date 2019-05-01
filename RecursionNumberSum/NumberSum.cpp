#include <iostream>

using namespace std;

recursion(int i)
{
	int ii = 0;
	
	if(i/10!=0)
	{
		ii = i % 10;
		return (ii + recursion(i / 10));	
	}	
	else
		return(i % 10);
}

int main()
{	
	int i = 0, sum = 0;
	cout<<"Enter up to a 4 digit number:  ";
	cin>>i;
	sum = recursion(i);
	cout<<"the sum of all individual integers is: "<<sum<<endl;
		
return (0);
}

