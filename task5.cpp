#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

struct Invoice
{
    char p_num[20] ;
    char p_des[30] ;
    int quantity ; 
    float price ; 
} ;

void initialize(Invoice &myInvoice , char p_num[] , char p_des[] , int quantity , float price )
{
    strcpy(myInvoice.p_num , p_num) ;
    strcpy(myInvoice.p_des , p_des) ; 
    myInvoice.quantity = quantity ; 
    myInvoice.price = price ; 

    if(myInvoice.price < 0)
    {
        myInvoice.price = 0 ;
    }
    if(myInvoice.price<0)
    {
        myInvoice.quantity = 0 ;
    }

    //calculating invoice amount
    float total = myInvoice.quantity * myInvoice.price ; 

    cout << "Total Invoice amount: " << total << endl ; 

}
int main()
{
    Invoice myInvoice ; 

    initialize(myInvoice , "12345" , "Watch" , 4, 38.00) ;

}