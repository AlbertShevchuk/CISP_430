#include <iostream>
#include <fstream>
using namespace std;

int arr[5][4];
void bubblesort();
void selectionsort();
void insertionsort();
void flip( bool, unsigned, unsigned );
void original( int[5][4] );
void display();


void bubblesort()                  
{
    unsigned i, r = 0;
    bool flipped, done = false;

    for ( i = 4; (i > 0 && !done); i-- )
    {
        flipped = false;
        for ( r = 0; r < i; r++ )
        {
            if ( arr[r][0] > arr[r+1][0] )
            {
                flip( true, r, r+1 );
                flipped = true;
            }
        }
        if ( flipped )
            done = true;
    }

    display();
}

void selectionsort()               
{
    unsigned i, j, mark;
    int temp;

    for ( j = 0; j < 5; j++ )
    {
        temp = arr[j][1];
        mark = j;
        for ( i = j; i < 4; i++ )
        {
            if ( arr[i][1] > temp )
            {
                mark = i;
            }
        }
        flip( true, j, mark );
    }

    display();
}

void insertionsort()                
{
    unsigned i, j;
    int temp;
    bool done;
    for ( j = 1; j < 5; j++ )
    {
        done = false;
        temp = arr[4][j];
        for ( i = j; (i > 0 && !done); i-- )
        {
            if ( temp < arr[4][i-1] )
                flip( false, i, i-1 );
            else
                done = true;
        }
    }

    display();
}

void flip( bool row, unsigned a, unsigned b )     
{
    int temp;
    unsigned i;
    if ( row )
    {
        for ( i = 0; i < 5; i++ )
        {
            temp = arr[a][i];
            arr[a][i] = arr[b][i];
            arr[b][i] = temp;
        }
    }
    else
    {
        for ( i = 0; i < 4; i++ )
        {
            temp = arr[i][a];
            arr[i][a] = arr[i][b];
            arr[i][b] = temp;
        }
    }
}

void original( int newarr[5][4] )    
{
    unsigned r, c;
    for ( r = 0; r < 5; r++ )
    {
        for ( c = 0; c < 4; c++ )
        {
            arr[r][c] = newarr [r][c];
        }
    }
}

void display()                  
{
    unsigned r, c;
    for ( r = 0; r < 5; r++ )
    {
        for ( c = 0; c < 4; c++ )
        {
            cout << arr[r][c] << ' ';
            
        }
        cout << endl;
    }
}

int main()                     
{
    ifstream in("input.txt");
    int data;
    unsigned r, c;
    for ( r = 0; r < 5; r++ )
    {
        for ( c = 0; c < 4; c++ )
        {
            in >> data;
            arr[r][c] = data;
        }
    }

    int newarr[5][4];
    for ( r = 0; r < 5; r++ )
    {
        for ( c = 0; c < 4; c++ )
        {
            newarr[r][c] = arr[r][c];
        }
    }

    bubblesort();
    original(newarr);
    selectionsort();
    original(newarr);
    insertionsort();

    cout << "Please enter a number: ";
    cin >> data;
    unsigned j, l = 0, m, h = 3;
    bool done = false, change = false;

    while ( !done )
    {
        m = (l + h) / 2;
        if ( l == m )
            change = true;
        if ( data == arr[3][m] )
        {
            j = m;
            done = true;
        }
        else if ( data > arr[3][m] )
            l = m;
        else
            h = m;
        if ( change )
            if ( data == arr[3][h] )
            {
                j = h;
                done = true;
            }
    }

    for ( unsigned i = 0; i < 5; i++ )
        cout << arr[i][j];

    return 0;
}
