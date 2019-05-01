/*
Zia Rehman
CISP 430
Professor Sabzevary
MW 7:00PM - 8:20PM
Group Recursive Number Sum P9
*/

#include <iostream>
#include <fstream>
using namespace std;

//Recursive add function
int add(int x)
{
	int mod = x % 10;
	if ( x/ 10 == 0)
 	return x;
	else
 	return mod + add(x/10);
}

 
int main ()
{
	int num, sum = 0;

	cout <<"Enter a maximum of 4 integers:" <<endl;
	cin >> num; 
	cout << endl;
	sum = add(num);
	cout << "The sum of the integers is: " << sum << endl << endl;
}
