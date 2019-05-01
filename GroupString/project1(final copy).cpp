#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream in("input.txt");	 
ofstream out("output.txt");	 

void stringCopy(char *A, char *B) 
{
	int counterB=0;
	for(int counter=0; B[counter]!=NULL; counter++)
		{
			counterB=counter;
		}
	
	for(int counter=0; (counter<=15); counter++)
		{
			if (counter>counterB)
					A[counter]=NULL;
			else
					A[counter]=B[counter];
		}	
}

bool stringCompare(char *A, char *B)
{
	int counterB=0;
	int counterA=0;
	bool compareResult=0;
	
	for(int counter=0; A[counter]!=NULL; counter++)
		{
			counterA=counter;
		}
		
	for(int counter=0; B[counter]!=NULL; counter++)
		{
			counterB=counter;
		}
    
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
  return compareResult;
}

void stringConcatenation(char *A, char *B)  
{
	int counterA=0;
	int counterB=0;
	
	for(int counter=0; A[counter]!=NULL; counter++)
	{
		counterA=counter;
	}

		for(int counter=0; B[counter]!=NULL; counter++)
	{
		counterB=counter;
	}

	for (int counter=0; counter<=(counterA+counterB+2); ++counter)
		{
			if(counter>counterA)
			{
				A[counter]=B[counter-counterA-1];
			}
			else
			{
				A[counter]=A[counter];
			}
		}
}
 
int stringPosition(char *A, char B)
{
  int counterA=0, counterB=0;
  
  	for(int counter=0; A[counter]!=NULL; counter++)
		{
			counterA=counter;
		}
 		counterA++;
 			
	for (int counter=0; (A[counter]!=B); ++counter)
	{
			counterB++;	
			if(A[counter]==NULL)
				{
					counterB=(-1);
					break;
				}
	}	
	return (counterB); 	
 }
 
int stringLength(char *A)
{
	char B[15];
	int counterA=0;
	
 for(int counter=0; A[counter]!=NULL; counter++)
	{
		counterA=counter;
	}

	for ( int counter=0 ; counter<=15 ; counter++)
	    {
					B[counter+1]=A[counter];						
		}
	
	B[0]=49+counterA;
		
	for(int counter=0; counter<=15; counter++)
	{
		if(counter<=counterA+1)
			A[counter]=B[counter];
		else
			A[counter]=NULL;
	}
	return (counterA+1);
}

int main()
{
   char A[15];
   char B[15];
   char C[15];
   char D[15];
   char E[15];
   char F[15];
   char G[15];
   char H[15];
   char I[15];
   bool stringC;
   int stringP=0;
   double distance;
	
        in >>A>>B>>C>>D>>E>>F>>G>>H>>I>> distance; 
		
	out<<"     Group Assignment: 1) GroupString by Albert Shevchuk "<<endl<<endl<<endl;;
    out<<"  Funct: stringCopy"<<endl<<endl;
	out<<"Contents in Array A and B before stringCopy"<<endl;
    out<<"Array A: "<<A<<endl;
	out<<"Array B: "<<B<<endl;
	
	stringCopy(A,B);
	
	out<<"Contents in Array A and B after stringCopy"<<endl;
    out<<"Array A: "<<A<<endl;
	out<<"Array B: "<<B<<endl<<endl;
	out<<"  Funct: stringCompare"<<endl<<endl;
	out<<"Contents in Array C and D before stringCompare"<<endl;
    out<<"Array C: "<<C<<endl;
	out<<"Array D: "<<D<<endl;

	stringC=stringCompare(C,D);
	
	out<<"Are the Contents in Array C and D the same?";
 		if(stringC==1)
 			out<<" yes"<<endl;
 		else
 			out<<" no"<<endl;
 	
	out<<endl;		
 	out<<"  Funct: stringConcatenation"<<endl<<endl;
	out<<"Contents in Array E and F before stringCompare"<<endl;
    out<<"Array E: "<<E<<endl;
	out<<"Array F: "<<F<<endl;
	out<<"Contents in Array E and F after stringCompare"<<endl;
	
  	stringConcatenation(E,F);  
  	
  	out<<"Array E: "<<E<<endl;
	out<<"Array F: "<<F<<endl<<endl;
	out<<"  Funct: stringPosition"<<endl<<endl;
	out<<"Contents in Array G and H before stringPosition"<<endl;
    out<<"Array G: "<<G<<endl;
	out<<"Array H: "<<H<<endl;
	
  	stringP=stringPosition(G,H[0]);
  	
  	out<<"The first letter "<<H[0]<<" of Array H is located in position: "<<stringP<<" of Array G"<<endl<<endl;
    out<<"  Funct: stringLength"<<endl<<endl;
	out<<"Contents in Array I before stringPosition"<<endl;
    out<<"Array I: "<<I<<endl;
	
	int size=stringLength(I);
	
	out<<"Ammount of letters moved: "<<size<<endl;
	out<<"Contents in Array I after stringPosition"<<endl;
    out<<"Array I: "<<I<<endl;
    
	in.close();
    out.close(); 
	 
    return 0; 
}
