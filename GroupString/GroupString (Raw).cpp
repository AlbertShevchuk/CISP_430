#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;




main()
 {
      // part 1
	 
	char A[] = "albertsogaingsta";
	char B[] = "twinturbocharger";
	
    int i,b= 2;
    cout<<i<<endl<<b<<endl;
	
	int counterA=0;
	int counterB=0;
	int counterC=0;
	int counterD=0;
	int counter1=0;
		
	cout<<"Part 1"<<endl;
	cout<<endl;
	cout<<"Array A: ";
	cout<<A<<endl;
	cout<<"Array B: ";
	cout<<B<<endl;
	cout<<endl;
	
	for(int counter=0; A[counter]!=NULL; counter++)
	{
		counterA=counter;
	}

	cout<<"The size of Array A is: "<<counterA<<endl;
	
		for(int counter=0; B[counter]!=NULL; counter++)
	{
		counterB=counter;
	}

	cout<<"The size of Array B is: "<<counterB<<endl;
	cout<<endl;
	cout<<"Replaced the contents of string A with the contents of string B"<<endl;
	cout<<endl;
	
	for(int counter=0; A[counter]!=NULL; counter++)
		{
			if (counter>counterB)
					A[counter]=NULL;
			else
					A[counter]=B[counter];
		}
		
	cout<<"Array A: ";
	cout<<A<<endl;
	cout<<"Array B: ";
	cout<<B<<endl;

    // Part 2
    
	cout<<endl;
    cout<<"Part 2"<<endl;
    cout<<endl;   
	cout<<"Array A: ";
	cout<<A<<endl;
	cout<<"Array B: ";
	cout<<B<<endl;   
    
    bool compareResult=0;
    
    for(int counter=0; counter<counterA; counter++)
    {
    	if(A[counter]==B[counter])
    			compareResult=1;
    	else
    	{
				compareResult=0;
    			counter=counter+counterA;
		}
	}
    
    	cout<<endl;
 		cout<<"Are the Arrays the same?";
 		if(compareResult==1)
 			cout<<" yes"<<endl;
 		else
 			cout<<" no"<<endl;
 		
		 
		 ////////////////////////////////////////////////////////////////	
 	
  	char C[] = "albertsogaingst";
	char D[] = "twinturbocharge";
    cout<<endl;
	cout<<"Array C: ";
	cout<<C<<endl;
	cout<<"Array D: ";
	cout<<D<<endl;   
    
    compareResult=0;
    
    for(int counter=0; counter<counterA; counter++)
    {
    	if(C[counter]==D[counter])
    			compareResult=1;
    	else
    	{
				compareResult=0;
    			counter=counter+counterA;
		}
	}
    
    	cout<<endl;
 		cout<<"Are the Arrays the same?";
 		if(compareResult==1)
 			cout<<" yes"<<endl;
 		else
 			cout<<" no"<<endl;
    
    // Part 3: (no more magic)
    
    
	char AB[29];
	
		for(int counter=0; C[counter]!=NULL; counter++)
	{
		counterC=counter;
	}

	cout<<"The size of Array C is: "<<counterC<<endl;
	
		for(int counter=0; D[counter]!=NULL; counter++)
	{
		counterD=counter;
	}

	cout<<"The size of Array D is: "<<counterD<<endl;
	
	for (int counter=0; counter<=(counterC+counterD+2); ++counter)
		{
			if(counter>counterC)
			{
				AB[counter]=D[counter-15];
			}
			else
			{
				AB[counter]=C[counter];
			}
		}
	
	cout<<AB<<endl;
	for(int counter=0; AB[counter]!=NULL; counter++)
	{
		counterC=counter;
	}

	cout<<endl;
	cout<<"The size of Array AB is: "<<counterC<<endl;
	cout<<endl;
	
	
	//part 4
	
	char z = 'o';

 counterC=0;
			
	for (int counter=0; (C[counter]!=z); counter++)
	{
		counterC=counter;
	}
	
	if(counterC==0)
		cout<<"-1"<<endl;
	else
		cout<<"The positon is: "<<counterC+1<<endl;
	
	//////////////part 5
	
	cout<<endl;
	cout<<"this is part 5"<<endl;
	cout<<endl;
	
	char E[15] = "Bonjour";
	char F[15];
	
	cout<<"this is before the shift: ";
	cout<<E<<endl;
	
		for(int counter=0; E[counter]!=NULL; counter++)
	{
		counterA=counter;
	}

	cout<<"The size of Array E is: "<<counterA<<endl;

	for ( int counter=0 ; counter<=15 ; counter++)
	    {
			if (counter<=counterA)
					F[counter+1]=E[counter];					
			else
					F[counter+1]=NULL;
		}
	
	F[0]=49+counterA;
		
	for(int counter=0; F[counter]!=NULL; counter++)
	{
		E[counter]=F[counter];
	}
	
	cout<<endl;
	cout<<"this is after the shift: ";
	cout<<E<<endl;
	cout<<"The "<<E[0]<<" is the number of the charecters that were moved witch is: "<<counterA+1<<endl;
	
}
