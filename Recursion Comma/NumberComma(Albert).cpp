#include <iostream>

using namespace std;

recursion(char *i, int trac)
{
	int counter = 0;
	
	if(*i != NULL)
	{
		counter = (recursion(++i, trac+1));	
			
		if((trac % 3 == 0) && (trac > 0))	
		{
			cout<<",";
			cout<<*(i - (trac - counter));
			return(++counter);
		}
		else
		{
			cout<<*(i - (trac - counter));
			return(++counter);
		}
	}
	else
	{
		cout<<*(i - trac);
		return (0);
	}
}

int main()
{	
	char i[9];
	int trac = 0, sum;
	
	cout<<"Enter up to a 4 digit number:  ";
	cin>>i;
	recursion(i,trac);
		
return (0);
}

