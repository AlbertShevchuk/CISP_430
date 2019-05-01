#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream in("input.txt");	 
ofstream out("output.txt");	 

/*
int clean(){
      string comments;  //store the comments in this variable
       while (in.peek()=='\n' || in.peek()=='/' || in.peek()==' ' || in.peek()=='\t'){
           if (in.peek()=='/' )
              getline(in, comments);  //read the entire line because it is a comment
           else
              in.get();    //eat the newline, space and tab characters
      }
      return 1;
}
*/


void stringCopy(char *A, char *B) 
{
	int counterB=0;
	for(int counter=0; B[counter]!=NULL; counter++)
		{
			counterB=counter;
		}
	
	for(int counter=0; A[counter]!=NULL; counter++)
		{
			if (counter>counterB)
					A[counter]=NULL;
			else
					A[counter]=B[counter];
		}
	cout<<endl;
	
	cout<<"Array A: "<<A<<endl;
	cout<<"Array B: "<<B<<endl;
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
    
    	cout<<endl;
 		cout<<"Are the Arrays the same?";
 		if(compareResult==1)
 			cout<<" yes"<<endl;
 		else
 			cout<<" no"<<endl;
 			
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

	
	for (int counter=0; counter<=(counterA+counterB+1); ++counter)
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

	cout<<endl;
	cout<<A<<endl;
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
 	
 	cout<<endl;
 	cout<<counterB<<endl;
	
	return (counterB); 	
	
 }
 
	  
	
	 


 
 
/*
 
int stringLength(char *A)
{
 int space=0;
 char C[15];
  for(int i=0; A[i] != '\0'; i++)
  {
     C[i+1] = A[i];
     space++;
     C[0]=space+49;
  }
  for(int x=0; C[x]== '\0'; x++)
   {
    A[x]=C[x];
   }
 return space;
}
*/

int main()
{
   char A[15]="ferrari";
   char B[15]="enzo";
   bool stringC;
   int stringP=0;
	double distance;
	
    
     
   /* 
    
    while (clean() && in.good())
	{
        in >>A>> B >> distance;
       out<<A<<B<< distance <<endl;
    }
    
   in.close();
    out.close();  
   
    */
    
	stringCopy(A,B);
   stringC=stringCompare(A,B);   
   stringConcatenation(A,B);  
   // A[0]='z';	  // (change these to test func4)
   // B[0]='o';   // (change these to test func4)
   stringP=stringPosition(A,B[0]);
    
    
    

    return 0; 
}
