/*
Zia Rehman
CISP 430
Professor Sabzevary
MW 7:00PM - 8:20PM
GroupString Project 1
*/

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

    //cout<<A<<endl;
    //cout<<B<<endl;
}
bool stringCompare(char *A, char *B) // return true if the strings are identical, otherwise return false.
{
    bool equal = true;


    for (int x =0; A[x] != '\0' && B[x] != '\0' && equal == true; x++)
  {
      if(A[x] != B[x])
        equal = false;
  }
  /*if (equal)
    {
    cout << A << " is the same as " << B << endl;
    }else{
    cout << A << " is NOT the same as " << B << endl;
    }*/

  return equal;
}
void stringConcatenation(char *A, char *B) // adds on the elements from string *B to the end of string *A
{


	cout<<A<<endl;
	cout<<B<<endl;
	
   int place = 0, i = 0;

    while (A[i] != '\0')
    {
        place++;
        i++;
    }

    i = 0;
    while (B[i] != '\0')
    {
        A[place + i]= B[i];
        i++;
    }
    //cout<<A;
}

int stringPosition(char *A, char B) //checks the position of the letter passed in relation to its position or existence in the string
{
 int i =0;
 int newplace =0;
 for(int i=0; A[i] != '\0'; i++)
 {
  if(A[i] == B)
  {
    newplace = i;
    break;
  }
  i++;
 }
  return newplace;
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
  }

  C[0]=space+48; //add 48 because adding to the ascii value

  for(int x=0; (x<=space+1); x++)
   {
    A[x]=C[x]; //recopying the new array to the old one to display
   }

  //cout<<C<<endl;

 return space;

}


int main(){
    char A[15];
    char B[15];
    bool equal = 0; //bool used for true or false in string compare
    char C = '0'; 
    int space = 0; 

    for (int i = 0; i<5 && clean() && in.good(); i++) 
    {                               // can use in.good to check if for end of fiLe.
        in >>A >> B;               // For every iteration, this reads in a Line from the file.
        switch (i)
        {
        case 0:
            stringCopy(A,B);
            cout << "The string has been copied and both arrays are the same"<<endl;
			cout <<"Array A:" << A << " " <<"Array B:" << B << endl; 

            out << "After copying the strings, array A && B are" << A << " " << B << endl; // output to file.

            break;

        case 1:
            equal = stringCompare(A,B);
            cout << A << " && " << B << " - ";
            out << "stringCompare: "  << A << " && " << B << " - ";
            if (equal)
			{ 
                cout << "They strings are identical" << endl;
                out << "They strings are identical" << endl; 
			}
            else
			 {
                cout << "They strings are not the same" << endl;
                out << "They strings are not the same" << endl; 
			 }
            break;

        case 2:
            stringConcatenation(A,B);
            cout << "Strings combined: " << A << " " << B << endl;
            out << "Both strings together: " << A << " " <<  B << endl;
            break;

        case 3:
            cout << A << " " << B << endl
                 << "The character " << B <<" is at position: " << stringPosition(A,B[0]) << endl;
            out  << A << " " << B << endl
                 << "The character is at position: " << stringPosition(A,B[0]) << endl;
            break;

        case 4:
            space = stringLength(A);
            cout << A << endl << "There are " << space << " characters." << endl;
            out << "The string " << A << "has " << space  << "  characters." << endl;
            break;

        default:
        break;
        } 

        for (int i = 0; i< 15; i++) //clear the array after every function calL
        {
            A[i] = '\0';
            B[i] = '\0';
        }
    } 
    in.close();
    return 0;
}



/*
int main()
{
   char A[15];
   char B[15];
   //char from[15], to[15];
   char C = '0';
   int newplace = stringPosition(A,B[0]);
   int space = stringLength(A);
   bool equal = true;
   double distance;
   
  
in.close();

out.close();



    //stringCopy(A,B);
    //stringCompare(A,B);
    //stringConcatenation(A,B);
	stringPosition(A,C);
	//stringLength(A);
	//equal = stringCompare(A,B);
    //cout<<spot<<endl;
    //cout<<newplace<<endl;


    return 0;
}*/
