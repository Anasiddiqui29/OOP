#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

class BOOK
{
    int bookno ;
    char booktitle[20] ;
    float price ; 

    public:
    
    void TOTAL_COST(int N)
    {
        float totalprice ; 

        totalprice = N*price ;

        cout << "Total price: " << totalprice << endl ; 
    }

    void INPUT()
    {
        cout << "Enter the book number: " << endl ; 
        cin >> bookno ;

        cout << "Enter the book title: " << endl ;
        cin >> booktitle ;

        cout << "Enter the price of the book: " << endl ; 
        cin >> price ;
    }

    void PURCHASE()
    {
        int N ; 

        cout << "Enter the number of copies you want to buy: "<< endl ;
        cin >> N ;

        TOTAL_COST(N) ;  
    }

};

int main()
{
    BOOK customer ;

    customer.INPUT() ;

    customer.PURCHASE() ;
}