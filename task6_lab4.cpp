#include <iostream>
#include <cmath>
using namespace std ;

class Office
{
    string location ; 
    int seatingcapacity ; 
    string * furniture ;

    public:

    Office(string loc = "" , int cap = 0 , int size=0) 
    {
        location = loc ;
        seatingcapacity = cap ;  

        furniture = new string[size] ;

        for(int i=0 ; i<size ; i++)
        {
            furniture[i] = "" ; 
        }
    }

    //destructor to free allocated memory
    ~Office()
    {
        delete[] furniture ; 
    }

} ;

int main()
{
    Office * offptr = new Office("Karachi" , 12 , 5) ;

    //deleting dynamically allocated object
    delete[] offptr ; 
}


