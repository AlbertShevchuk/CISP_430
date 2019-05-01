#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
ifstream in; 

sChild(int a[],int i,int n)
{
    int left=2*i+1;
	int right=2*i+2;

    if(right>=n)
    {
    	return left;
	}
    else if(a[left]<=a[right])
    {
    	return left;
	}
    else
    {
    	return right;
	}
}

void place(int a[],int number,int &n)
{
    int node;
	int location=n;

    while (location>0)
    {
        node =(location-1)/2;
        
        if (number>=a[node])
        {
            a[location]=number;
            return;
        }

        a[location]=a[node];
        location=node;
    }

    a[0]=number;
}

void deleteLink(int a[],int &n)
{
    int left;
	int right;
	int temp;
	int parent;
	int i = n;
	int child;

    a[0]=a[n-1];
    n--;
    parent=(i-1)/2;
    
    if(a[i]<a[parent])
    {
        place(a,a[i],i);
        return;
    }

    left=2*i+1;
    right=2*i+2;
    
    while(right<n)
    {
        if((a[i]<=a[left])&&(a[i]<=a[right]))
        {
            return;
		}
        if(a[right]>=a[left])
        {
            temp=a[i];
            a[i]=a[left];
            a[left]=temp;
            i=left;
        }
        else
        {
            temp=a[i];
            a[i]=a[right];
            a[right]=temp;
            i=right;
        }
        
        left=2*i+1;
        right=2*i+2;
    }

    if(left==n-1&&a[i])
    {
        temp=a[i];
        a[i]=a[left];
        a[left]=temp;
    }

    i=0;
    while(i*2+1<n)
    {
        child=sChild(a,i,n);
        temp=a[child];
        a[child]=a[i];
        a[i]=temp;
        i=child;
    }
}

void print(int a[],int n)
{
    if(n==0)
    {
        cout<<"Nothings Exists";
        return;
    }
    for(int i=0;i<n;i++)
    {
        cout<<setw(3)<<a[i]<< " ";
        if((i==0)||(i==2)||(i==6)||(i==14) )
        {
        	cout<<endl;
		}
    }
}

delete5(int a[],int &n)
{
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        deleteLink(a,n);
        cout<<"Delete: "<<i+1<<endl<<endl;
        print(a,n);
        cout<<endl<<endl;
    }
}

file(int a[],int &n)
{
    in.open("input.txt");
    int temp,i=0;

    while((in>>temp)&&(i<10))
    {
        place(a,temp,n);
        n++;
        i++;
    }
    
    in.close();
    in.clear(); 
}

main()
{
    int a[10];
	int nodes=0;
	
    file(a,nodes);
    cout<<"Heap Tree has been Created Below"<<endl<<endl;
    print(a,nodes);
    cout << endl<<endl;
    delete5(a,nodes);
    
return(0);
}
