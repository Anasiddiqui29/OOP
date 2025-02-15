#include <iostream>
#include <cmath>
using namespace std ;

class Office
{
    string location ; 
    int seatingcapacity ; 
    string furniture[3] ; 

    public:

    Office(string loc = "" , int cap = 0 , string fur1 = "" , string fur2 = "" , string fur3 = "") 
    : location(loc) , seatingcapacity(cap) , furniture{fur1 , fur2 ,fur3} {}

    void display()
    {
        cout << "Location: " << location << endl ;
        cout << "Seating Capacity: " << seatingcapacity << endl ; 
        for(int i=0 ; i<3 ; i++)
        {
            cout << "Furniture " << i+1 << " : " << furniture[i] << endl ; 
        }
    }


} ;

int main()
{
    Office off1; //zero arguements
    Office off2("Hilltown") ; //one arguements
    Office off3("Central karachi" , 45) ; //two arguements
    Office off4("Gulshan Iqbal" , 50 , "Desk" , "Chair" , "Table") ; //three arguements 

    cout << "Zero arguement" << endl ; 
    off1.display() ;

    cout << "One arguement" << endl ; 
    off2.display() ;

    cout << "Two arguements" << endl ; 
    off3.display() ;

    cout << "Three arguements" << endl ; 
    off4.display() ;

}