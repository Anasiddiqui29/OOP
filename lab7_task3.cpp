#include <iostream>
#include <cmath>

using namespace std ;

class Pizza
{
    string size; 
    int n_cht ;
    int n_pt ; 
    int n_ht ; 

    public:

    Pizza(string size , int n_cht , int n_pt , int n_ht)
    {
        this->size = size ; 
        this->n_cht = n_cht ; 
        this->n_pt = n_pt ; 
        this->n_ht = n_ht ; 
    }

    string getsize()
    {
        return size ; 
    }
    
    int getcht()
    {
        return n_cht ;
    }

    int getpt()
    {
        return n_pt ;
    }

    int getht()
    {
        return n_ht ; 
    }

    double calcCost()
    {
        double cost = 0 ; 
        if(size=="small")
        {
            cost = 1000 + (getcht()*200) + (getpt()*200) + (getht()*200) ;
        }
        if(size == "medium")
        {
            cost = 1200 + (getcht()*200) + (getpt()*200) + (getht()*200) ;
        }
        if(size == "large")
        {
            cost = 1400 + (getcht()*200) + (getpt()*200) + (getht()*200) ;
        }
        return cost ; 
    }

    string getDescription()
    {
        return size ; 
    }

    const void display()
    {
        cout << "A " <<getDescription() <<"pizza " << "with " <<getcht() <<" cheese ,"<< getpt() << " pepporoni and " << getht() << " ham topping" <<endl ; 
        cout << "Total cost is " <<  calcCost() << endl ; 
    }

    //copy constructor
    Pizza(Pizza &order1)
    {
        this->size = order1.size ; 
        this->n_cht = order1.n_cht ; 
        this->n_pt = order1.n_pt ; 
        this->n_ht = order1.n_ht ; 
    }
} ;

int main()
{
    Pizza pizza1("small", 2, 1, 1);
    Pizza oldpizza(pizza1) ; 
    int choice , choice1; 
    cout << "Do u want to update the your order ? Press 1 for yes or 0 to exit" << endl;
    cin >> choice ; 
    if(choice==1)
    {
        Pizza pizza4("large" ,2,2,2) ;
        cout << "Old order details: " << endl ; 
        oldpizza.display() ;
        cout << "------------------------------" << endl ; 
        cout <<"Updated order detail" << endl ; 
        pizza4.display() ;

        cout << "Which one do you want to keep? Press 1 for updated one or 2 to keep the old one" <<endl ; 
        cin >> choice1 ; 

        if(choice1 == 1)
        {
            cout << "Final order details" << endl ; 
            pizza4.display() ;
        }
        if(choice1 == 2)
        {
            cout << "Final order details" << endl ; 
            oldpizza.display() ;
        }
    }

    //other instances
    Pizza pizza2("medium", 1, 0, 2);
    Pizza pizza3("large", 0, 3, 0);

    cout <<"------------------------------------" << endl ; 
    cout << "------------------------------------" << endl ;

    cout << "Order 2 details"<< endl ; 
    pizza2.display() ;
    cout << "Order 3 details" << endl ; 
    pizza3.display() ;  


}