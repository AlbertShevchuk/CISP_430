#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream in("input.txt");		//input.txt is the file that we read from
ofstream out("output.txt");	//output.txt is the file that we write into

//This function looks ahead to get rid of all extra characters, such as new lines, spaces, tabs
//and single line comments.
int clean()
{
      string comments;  //store the comments in this variable
       while (in.peek()=='\n' || in.peek()=='/' || in.peek()==' ' || in.peek()=='\t'){
           if (in.peek()=='/' )
              getline(in, comments);  //read the entire line because it is a comment
           else
              in.get();    //eat the newline, space and tab characters
      }
      return 1;
}
void stringCopy(char *A, char *B) //*A is the initial and *B is the final. Replace contents of string A with contents of string B
{
    int move = 0;
    while (B[move] != '\0')
    {
        A[move]=B[move];
        move++;
    }
    A[move] = '\0';
}
bool stringCompare(char *A, char *B) // return true if the strings are identical, otherwise return false.
{
    bool equal = true;


    for (int x =0; A[x] != '\0' && B[x] != '\0' && equal == true; x++)
  {
      if(A[x] != B[x])
        equal = false;
  }
  return equal;
}
void stringConcatenation(char *A, char *B) // adds on the elements from string *B to the end of string *A
{
 int i=0, place =0;
 while(A[i] != '\0')
  {
   place++;
   i++;
  }
  i=0;
  while(B[i] != '\0')
  {
   A[place+1] = B[i];
   i++;
  }
 }
int stringPosition(char *A, char B)
{
 int newplace =0;
 for(int i=0; A[i]!= B; i++)
 {
   newplace = i;
   
cout<<newplace<<endl;
 }


  if(newplace <= 15)
  {
   return -1;
  }
  else
  {
   return newplace;
  }
  
  cout<<newplace<<endl;
  
 }

int stringLength(char *A)
{
 int space=0;
 char C[15];
  for(int i=0; A[i] != '\0'; i++)
  {
     C[i+1] = A[i];
     space++;
     C[0]=space+48;
  }
  for(int x=0; C[x]== '\0'; x++)
   {
    A[x]=C[x];
   }
 return space;
}

/*
int main()
{

char A[15], B[15];
char C;
int Position,Length;



while (clean() && in.good())
{

 in >> A >> B;
 stringCopy( A , B);
 out <<"A :  "<< A <<"  B : "<<B<<endl;

 in >> A >> B;
 if (stringCompare(A, B) == 0)

     out <<"False"<< endl;
 else
     out <<"True"<< endl;


 in >> A >> B;
 stringConcatenation(A, B);
 out << A << "  " <<endl;

 in >> A >> C;
 Position=stringPosition(A,  C);
 out << Position << endl;

 in >> A;
 Length=stringLength(A);
 out << Length<<endl;




}

in.close();

out.close();

}

*/

int main()
{
   char A[15]="testing";
   char B[15]="random";
   char from[15], to[15];
   char C = '0';
   bool equal = true;
   double distance;
   int REsult=0;

 // can use in.good() to check if for end of file
    while (clean() && in.good())
    {
       in >>from>> to >> distance;
       out<<from<<"  "<<to<<"  "<< distance <<endl;
    }
    in.close();
    out.close();
    stringCopy(A,B);
    stringLength(A);
	equal = stringCompare(A,B);
	REsult = stringPosition(A,B[0]);
	
    


    
}
