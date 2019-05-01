#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

const int HTSIZE = 10;

int hashFunction(string insertKey, int keyLength)
{
	int sum = 0;
	for (int index = 0; index < keyLength; index++)
		sum = sum + static_cast<int>(insertKey[index]);
	return (sum % HTSIZE);
}

int main() {
	
	string hashTable[HTSIZE];
	string line;
	ifstream in; 
	int sub = 0;
	int index = 0;
	bool found;
	int collision = 0;
	
	in.open("input.txt");
	cout<< "List Hashed" << endl << endl;
	cout<< "SUB" << setw(5) << "KEY" << endl;
		 
	while(in)
	{
		getline(in, line);
		index = hashFunction(line, line.length());
		hashTable[index] = line;
	}
	for(index = 0; index < HTSIZE; index++)
	{
		if(hashTable[index] == "")
		{
			hashTable[index] = "-1";
		}
		cout << left << setw(5) << index << hashTable[index] << endl;
	}
	in.close();
	
	in.open("input.txt");
	
	while(in)
	{
		getline(in, line);
		sub = hashFunction(line, line.length());
		found = false;
		
		while(hashTable[sub] != "-1" && !found)
		{
			
			if(hashTable[sub] == line)
			{
				found = true;
			}
			else
				sub = (sub + 1) % HTSIZE;
		}
		if(found)
		{ }
		else
		{
			hashTable[sub] = line;
		}
	}
		
	in.close();

	string searchNum;
	bool resultSearch = 0;
	cout<<endl<<"Witch Item Would you like to search for? : ";
	cin >> searchNum;

	for( index = 0; index < HTSIZE; index++)
	{
		if (hashTable[index] == searchNum)
			resultSearch = 1;
	}
	
	if(resultSearch)
		cout<<endl<<"Item Found"<<endl;
	else
		cout<<endl<<"Not in the list"<<endl;

return 0;
}


