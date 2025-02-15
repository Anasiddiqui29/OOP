#include <iostream>
#include <cmath>
using namespace std ;

class Product
{
    public:

    int pro_code ; 
    int pro_price ; 
    int count ; 
    
    
    void setproduct(int code , int price)
    {
        pro_code = code ; 
        pro_price = price ; 
    }

    void getproduct()
    {
        cout << "Product code: " << pro_code << endl ; 
        cout << "Product price: " << pro_price << endl ; 
    }

    

    //default constructor
    Product()
    {
        count++ ; 
    }
    
    int displaysum(int price , int Count)
    {
        int sum = 0 ;

        sum = Count * price ; 

        return sum ; 

    }

    int getcount()
    {
        return count ; 
    }

} ;

int main()
{
    int choice ;
    int numproducts = 0 ;
    Product * products = nullptr ;//dma

    do{
    cout << "1. Add a prdouct" << endl ; 
    cout << "2. Display a product total value" << endl ; 
    cout << "3. Display all products" << endl ; 
    cout << "4. Quit" << endl ; 

    cout << "Enter choice: " << endl ; 
    cin >> choice ; 

    switch (choice){
    
    case 1:{
        Product * temp = new Product[numproducts+1] ; 

        for(int i =0 ; i<numproducts ; i++)
        {
            temp[i] = products[i] ; 
        }
        
        
        //add a new product
        int Code , Price ; 
        cout << "Enter the code of the product: " << endl ; 
        cin >> Code ; 
        cout << "Enter the price: " << endl;
        cin >> Price ; 

        temp[numproducts].setproduct(Code , Price) ; 
        numproducts++ ; 

        //free allocated memory
        delete[] products ; 

        products = temp ; 

        break;
    }
    case 2:{
        int total ; 

        for(int i =0 ; i<numproducts ; i++)
        {
            total = total + products[i].pro_price ; 
            
        }

        cout << "Total price: " << total << endl ; 
        break ; 
    }
    case 3:{
        for(int i=0 ; i<numproducts ; i++)
        {
            products[i].getproduct() ;
        }
        break ;
    }
    case 4:{
        cout << "Quiting program...." << endl ; 
        break ; 
    }
    default:{
        cout << "Invalid choice" << endl ;
        break;
    }
    }
    }while(choice != 4) ;

    delete[] products ; 




}