#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>


using namespace std ;

class Table
{
    public:
    int t_seats ; 
    int seats_occ ;
    int free_seat ;
    bool clean;

    //default constructor
    Table() : t_seats(4) , clean(1) {}

    //parameterized constructor
    Table(int capacity) 
    {
        if(capacity==4 || capacity==8)
        {
            t_seats = capacity ;
        }
        else
        {   
            if(capacity > 0 && capacity <=6)
            {
                t_seats = 4 ;
            }
            if(capacity>=7)
            {
                t_seats = 8; 
            }
        }
         
    } 

};
    
void OccupyTable(Table table[] , int size , int g_size)
{
    for(int i =0 ; i< size ; i++)
    {
        if(table[i].clean==1 && table[i].seats_occ != 0)
        {
            cout << "The table "<<i+1 << " has been assigned" << endl ;
            table[i].clean = false ; 
            int tsize ; 
            if(i>=0 && i<=1)
            {
                cout << "The table has capacity of 8"<< endl ;  
            }
            if(i>1 && i<size)
            {
                cout << "The table has capacity of 4"<< endl ; 
            }
            break ;  
        }
    }
}

void EmptyTable(Table table[],int t_num)
{
    if(t_num >= 0 && t_num <= 5)
    { 
        table[t_num].seats_occ = 0 ;
        table[t_num].clean = true ;    
    }
}


int main()
{
    cout << "Name : Muhammad Anas Siddiqui" << endl ; 
    cout << "ID: 23k-0575" << endl ;
    
    Table tables[5] = {8,8,4,4,4} ;

    OccupyTable(tables , 5 , 4) ;
    OccupyTable(tables , 5, 6) ;

    //using the table
    OccupyTable(tables , 5 , 4) ;

    //having lunch
    tables[0].clean = false ; 

    //leavig the table
    tables[0].seats_occ = 0 ; 

    EmptyTable(tables , 1) ; 
}