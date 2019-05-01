#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
ifstream in; 
ofstream out;

struct student
{
	char data[10];						
	struct student *next;	
	struct student *prev;
	struct grade *scorePtr;				
};

struct grade
{
	char data[10];						
	struct grade *next;	
};

typedef struct student student;
typedef struct grade grade;																								// above is 2 structures, student is bothway, grade is oneway 

stdudentAddHead(student *&studentHead, student *&studentTail, char temp[], grade *&gradeHead, grade *&gradeTail)		// studentaddHead is resposible for making a list if there isnt any, modfying the beggining of the list, adding scores to the student
{																														// all the inportant pointers are past as reference exept the array temp
	if(studentHead == NULL)																								// if studentHEad points no nothing
	{
		student* newStudent = (student *)malloc(sizeof(student));
		newStudent->prev = NULL;
		newStudent->next = NULL;																						// we create the first link of the list having bothe the head and the tail pointing to the same link
		strcpy (newStudent->data,temp);																												
		studentHead = newStudent;
		studentTail = newStudent;
		
		do																												// loop for adding the scores
		{
			in >> temp;																									// read into temp
			if(((strcmp (temp,"end")) == 0))																			// is temp the word "end"
				{
					newStudent->scorePtr = NULL;																		// then we set the current studdents scoreptr pointer to NULL and dip out of this loop							
					break;	
				}
			else																										// otherwise
			{
				if(!gradeHead)																							// if gradeHead points to nothing																	
				{
					grade* newGrade = (grade *)malloc(sizeof(grade));
					strcpy (newGrade->data,temp);
					newGrade->next = NULL;									 											// we create the first link of the list having bothe the head and the tail pointing to the same link
					gradeHead = newGrade;
					gradeTail = newGrade;
				}
				else																									// otherwise if gradeHead exists
				{	
					grade* newGrade = (grade *)malloc(sizeof(grade));
					strcpy (newGrade->data,temp);
					gradeTail->next = newGrade;																			// we keep creating the link and adding it to the tail 
					gradeTail =	newGrade;
					gradeTail->next = NULL;
				}
			}
		}
		while(!((strcmp (temp,"end")) == 0));
		
		newStudent->scorePtr = gradeHead;																				// lastly i establish a link between the current students and the scores 
	}
	else																												// but is student head has already been created
	{
		student* newStudent = (student *)malloc(sizeof(student));
		newStudent->prev = NULL;
		newStudent->next= studentHead;
		studentHead->prev = newStudent;																					//this little area modiyes the head where it sets the new student ahead of student head, witch becomes the head																			
		strcpy (newStudent->data,temp);
		studentHead = newStudent;
		
		do
		{
			in >> temp;
			if(((strcmp (temp,"end")) == 0))
				{
					newStudent->scorePtr = NULL;
					break;	
				}
			else
			{
				if(!gradeHead)
				{
					grade* newGrade = (grade *)malloc(sizeof(grade));
					strcpy (newGrade->data,temp);
					newGrade->next = NULL;
					gradeHead = newGrade;																				// this adding grade code is exacly the same as the adding grade code in the above senario 
					gradeTail = newGrade;
				}
				else
				{	
					grade* newGrade = (grade *)malloc(sizeof(grade));
					strcpy (newGrade->data,temp);
					gradeTail->next = newGrade;
					gradeTail =	newGrade;
					gradeTail->next = NULL;
				}
			}
		}
		while(!((strcmp (temp,"end")) == 0));
		newStudent->scorePtr = gradeHead;
	}
}

stdudentAddTail(student *&studentTail, char temp[], grade *&gradeHead, grade *&gradeTail)								// studentAddTail is resmonsible for adding links to the end of the list
{																														// all the inportant pointers are past as reference exept the array temp
	student* newStudent = (student *)malloc(sizeof(student));
	studentTail->next = newStudent;
	newStudent->prev = studentTail;
	newStudent->next = NULL;																							// adds a link, sets it to studentTail and has next point to a NULL indicating that is the end
	strcpy (newStudent->data,temp);
	studentTail = newStudent;
	
	do
	{
		in >> temp;
		if(((strcmp (temp,"end")) == 0))
			{
				newStudent->scorePtr = NULL;
				break;	
			}
		else
		{
			if(!gradeHead)
			{
				grade* newGrade = (grade *)malloc(sizeof(grade));
				strcpy (newGrade->data,temp);
				newGrade->next = NULL;
				gradeHead = newGrade;																					// this adding grade code is exacly the same as the adding grade code in function studentAddHead
				gradeTail = newGrade;
			}
			else
			{	
				grade* newGrade = (grade *)malloc(sizeof(grade));
				strcpy (newGrade->data,temp);
				gradeTail->next = newGrade;
				gradeTail =	newGrade;
				gradeTail->next = NULL;
			}
		}
	}
	while(!((strcmp (temp,"end")) == 0));
		
	newStudent->scorePtr = gradeHead;
}

stdudentAddMiddle(student *&curr, student *&studentTail, char temp[], grade *&gradeHead, grade *&gradeTail)			// this function is responsible for splitting the previous link to the next link and inserting a new link in between
{																													// all the inportant pointers are past as reference exept the array temp
	student* newStudent = (student *)malloc(sizeof(student));
	curr->next->prev = newStudent;
	newStudent->next = curr->next;
	newStudent->prev = curr;
	curr->next = newStudent;		
	strcpy (newStudent->data,temp);
	
	do
	{
		in >> temp;
		if(((strcmp (temp,"end")) == 0))
			{
				newStudent->scorePtr = NULL;
				break;	
			}
		else
		{
			if(!gradeHead)
			{
				grade* newGrade = (grade *)malloc(sizeof(grade));
				strcpy (newGrade->data,temp);
				newGrade->next = NULL;
				gradeHead = newGrade;
				gradeTail = newGrade;																					// this adding grade code is exacly the same as the adding grade code in function studentAddHead
			}
			else
			{	
				grade* newGrade = (grade *)malloc(sizeof(grade));
				strcpy (newGrade->data,temp);
				gradeTail->next = newGrade;
				gradeTail =	newGrade;
				gradeTail->next = NULL;
			}
		}
	}
	while(!((strcmp (temp,"end")) == 0));
		
	newStudent->scorePtr = gradeHead;
}

funkDelete(student *&i, student *&studentHead, student *&studentTail)													// this function delermines how to delete the individual list along with the student scores, it recevs reference to a pointer studentHead and studentTail of type student
{																														// and it also receves a reference to a pointer i, which is the exact location where the name to delete is
	student *studentTemp;
	grade *gradeTemp, *gradeHead;																						// spare pointers
	
	if(studentHead == i)																								// if name is at the beggining of the list then we modify the head, delleteing the scores first if theres any
	{
		studentTemp = i;
		studentHead = studentHead->next;
		studentHead->prev = NULL;
		gradeHead = studentTemp->scorePtr;															
		
		while(gradeHead)
		{
			gradeTemp = gradeHead;
			gradeHead = gradeHead->next;
			delete(gradeTemp);
		}
		delete(studentTemp);
	}
	else if(studentTail == i)																							// if name is at the end of the list then we modify the tail, delleteing the scores first if theres any
	{
		studentTemp = i;
		studentTail = studentTail->prev;
		studentTail->next = NULL;
		gradeHead = studentTemp->scorePtr;
		
		while(gradeHead)
		{
			gradeTemp = gradeHead;
			gradeHead = gradeHead->next;
			delete(gradeTemp);
		}
		delete(studentTemp);
	}
	else																												// otherwise we are in between and we connect the prev and next together and have temp delete the name, delleteing the scores first if theres any
	{
		studentTemp = i;
		i->next->prev = i->prev;
		i->prev->next = i->next;
	
		gradeHead = studentTemp->scorePtr;
		
		while(gradeHead)
		{
			gradeTemp = gradeHead;
			gradeHead = gradeHead->next;
			delete(gradeTemp);
		}
		delete(studentTemp);
	}			
}

print(student *&studentHead, student *&studentTail)																		// this function prints the results into the file, it recevs reference to a pointer studentHead and studentTail of type student
{
	student *i;
	grade *ii;																											// spare pointers  to make looping eazyer
	
	i = studentHead;

	while (i!=NULL)
	{
		ii = i->scorePtr;
		out<<i->data<<": ";
		i=i->next;
		
		while(ii!=NULL)																									// this is esentualy the same code that i use for dialocate function, double loop to print all the contents
		{
			out<<ii->data<<" ";
			ii=ii->next;
		}
		out<<endl;
	}
	
	out<<endl;
	
		i = studentTail;																			

	while (i!=NULL)
	{
		ii = i->scorePtr;																								// to print backwards, i just traverse with ->prev instead of next for student list
		out<<i->data<<": ";
		i=i->prev;																				
		
		while(ii!=NULL)
		{
			out<<ii->data<<" ";																							// grade list still has only one way to go 
			ii=ii->next;
		}
		out<<endl;
	}
}

deallocate(student *&studentHead)																						// this fuction delets the remaining lists, it receves reference to a pointer studentHead of tyoe student
{
	student *studentHeadTemp;																							// make a temp pointer for student head
	grade *gradeHead, *gradeHeadTemp;																					// make a 2 pointes of type grade
								
	while (studentHead!=NULL)																							// double loop that deletes the scores first then the name, untill all the names are gone
	{
		gradeHead = studentHead->scorePtr;
		studentHeadTemp = studentHead;																					// temp replaces head, heads moves foward for student
		studentHead = studentHead->next;
		
		while(gradeHead!=NULL)																							// loops while there are no more grades
		{
			gradeHeadTemp = gradeHead;																					// temp replaces head, heads moves foward for grade 
			gradeHead=gradeHead->next;																					// grade temp gets deleted first
			delete(gradeHead);																	
		}
		delete(	studentHeadTemp);																						// student temp gets deleted last
	}
}

int main()
{
	
	in.open("input.txt");																			// open the file
	out.open("output.txt");				

	student *studentHead, *studentTail, *deleteStudent;
	grade *gradeHead, *gradeTail;
	studentHead = NULL;
	studentTail = NULL;
	deleteStudent = NULL;																			// pointers that i use, important ones get set to NULL
	gradeHead = NULL;
	gradeTail = NULL;
	student *curr, *i;

	char temp[10];																					// tempurary array that i use to store the input data
	bool done;																						// boolean flag, probably the only thing i found helpfull from your code you provided as hints
		
	while((in>>temp)!=NULL)																			// read into temp and check if its a null loop
	{ 
		done = 0;																					// set bool flag to falce
	
		if(!(strcmp(temp,"delete")))																// first if statement that looks for the word dellete
		{		
			in >> temp;																				// if theres a dellete then it reads the following word with the assumption that it is a name
			i = studentHead;																		// pointer i is used as a counter to loop threw students withcout altering the pointer to the first student witch is studentHead, assuming studentHead is pointing to someting
		
			while (i!=NULL)																			// loop checks the list for name to delete 
			{
				if ((strcmp(i->data,temp)) == 0)													// when if statement finds the word then it will brake the loop and stop i at the exact location of the word
						break;

				i=i->next;																			// other wise it keeps moving foward in the list untill it reaches a null
			}
			
			if(i)
				funkDelete(i, studentHead, studentTail);											// if something in i then we pass, i, beggining of the list pointer, end of the list pointer to function funkDelete										
			else
				out<<temp<<" does not exist in the list"<<endl<<endl;								// if there is nothing in i then, the loop looped without finding the student to delete, and prints a message				
		}	
		else 																						// else statement to the first if state ment, this area satisfys that the read in word in not delete
		{
			if(studentHead == NULL)																	// if student head points to nothing
			{
				stdudentAddHead(studentHead, studentTail, temp, gradeHead, gradeTail);				// pass student head/tail, grade head/tail, and the input to student add head function
				curr=studentHead;																	// set pointer curr to the location of pointer student head, curr is going to be used as a counter to loop threw the students when sorting
			}
			else																					// if there is something in head
			{		  	
				while(done == 0)																	// loop while flag is falce
				{																					// in my compareing the way i have it set up is if it == -1 then place after, == 1 then place befor, == 0 (the same) dose not exist as an assumption
					if ((curr->prev == NULL) && ((strcmp(curr->data,temp)>0)))						// if your at the very beggining of the list, and you need to place befor then
					{	
						stdudentAddHead(studentHead, studentTail, temp, gradeHead, gradeTail);		// pass pointers student head/tail, grade head/tail and the input file to function studentAddHead
						curr = studentHead;															// set curr to adress studentHead
						done = 1;																	// set flag to true
					}
					else if (((strcmp(curr->data,temp)<0)) && (curr->next == NULL))					// if previous condition falce and if you need to place after and your at the end of the list then
					{	
						stdudentAddTail(studentTail, temp, gradeHead, gradeTail);					// pass pointers student head/tail, grade head/tail and the input file to function studentAddTail
						curr = studentHead;															// set curr to adress studentHead
						done = 1;																	// set flag to true
					}
					else if(((strcmp(curr->data,temp)<0)) && ((strcmp(curr->next->data,temp)>0))) 	// if previous condition falce and if you need to place after, and when comparing the next data element and its telling you to place befor then
					{	
						stdudentAddMiddle(curr, studentTail, temp, gradeHead, gradeTail);			// pass pointers student head/tail, grade head/tail and the input file to function studentAddMiddle
						curr = studentHead;															// set curr to adress studentHead
						done = 1;																	// set flag to true
					}
					else if(((strcmp(curr->data,temp)<0)) && ((strcmp(curr->next->data,temp)<0))) 	// if previous condition falce and if you need to place after, and when comparing the next data element and its telling you to place after then
					{
						curr=curr->next;															// move curr down the list
					}		
				}	
			}	
		}	
		temp[0] = 0;																				// befor loop ends set first slot of array temp to 0
		gradeHead = NULL;																			// remove adress from pointers grade head/tail
		gradeTail = NULL;	
	}

	print(studentHead, studentTail);																// pass student head/tail to the print function
	in.close();																						// close the file
   	out.close(); 
	in.clear(); 																					// empty the in>> operatpr
	deallocate(studentHead);																		// pass studentHead to fuction dealocate
	
	return(0);
}
