#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std ; 

class Burger
{
    protected:
    int price; 
    string ingredients ; 
    string taste ; 

    public:
    Burger(int price , string ingredients , string taste)
    {
        this->price = price ; 
        this->ingredients = ingredients ;
        this->taste = taste ; 
    }

    void display()
    {
        cout << "The ingredients of the burger is: " << ingredients << endl ; 
    }

} ;

class ChickenBurger : public Burger
{
    int extra_cheese ; 

    public:
    ChickenBurger(int p , string ing , string tas , int extra_cheese) : Burger(p , ing , tas)
    {
        this->extra_cheese = extra_cheese ; 
    }

    void bill()
    {
        int total ; 
        if(extra_cheese==1)
        {
            total = 500 + Burger::price ;
        }
        else
        {
            total = Burger::price ; 
        }
        cout << "Total cost of the burger: " << total << endl ; 
    }

}; 

class BeefBurger : public Burger
{
    int extra_cheese ; 

    public:
    BeefBurger(int p , string ing , string tas , int extra_cheese) : Burger(p , ing , tas)
    {
        this->extra_cheese = extra_cheese ; 
    }

    void bill()
    {
        int total ; 
        if(extra_cheese==1)
        {
            total = 500 + Burger::price ;
        }
        else
        {
            total = Burger::price ;
        }
        cout << "Total cost of the burger: " << total << endl ; 
    }

} ;

int main()
{
    cout << "Welcome to our Restaurant" << endl ;
    string name ;
    int choice ,sauce , cheese;   
    cout << "What is ur name: " << endl ; 
    cin >> name ;
    cout << "\n\n" << endl ; 
    do
    {
        cout << "Menu" << endl ; 
        cout << "1.Chicken Burger" << endl ; 
        cout << "2.Beef Burger" << endl ; 
        cout << "Enter your choice(Press 0 to exit): " << endl;
        cin >> choice ; 
    
        switch(choice)
        {
            case 1: 
                cout << "Enter the ingedreints(Add sauce(1) or not(0)): " << endl ; 
                cin >> sauce ; 
                cout << "Do you want to add extra cheese: " << endl ; 
                cin >> cheese ; 
                if(sauce==1 && cheese==0)
                {
                    ChickenBurger order(1000 , "Chicken , sauce" , "Mild" , 0) ;
                    order.display() ;
                    order.bill() ; 
                }
                if(sauce==1 && cheese==1)
                {
                    ChickenBurger order(1000 , "Chicken , sauce and cheese" , "Mild" , 1) ;
                    order.display() ;
                    order.bill() ; 
                }
                if(sauce==0 && cheese==0)
                {
                    ChickenBurger order(1000 , "Chicken " , "Mild" , 0) ;
                    order.display() ;
                    order.bill() ; 
                }
                if(sauce==0 && cheese==1)
                {
                    ChickenBurger order(1000 , "Chicken , cheese" , "Mild" , 1) ;
                    order.display() ;
                    order.bill() ; 
                }

                break ;
            
            case 2 : 
                cout << "Enter the ingedreints(Add sauce(1) or not(0)): " << endl ; 
                cin >> sauce ; 
                cout << "Do you want to add extra cheese: " << endl ; 
                cin >> cheese ; 
                if(sauce==1 && cheese==0)
                {
                    BeefBurger order(1000 , "Beef , sauce" , "Spicy" , 0) ;
                    order.display() ;
                    order.bill() ; 
                }
                if(sauce==1 && cheese==1)
                {
                    BeefBurger order(1500 , "Beef, sauce and cheese" , "Spicy" , 1) ;
                    order.display() ;
                    order.bill() ; 
                }
                if(sauce==0 && cheese==0)
                {
                    BeefBurger order(1500 , "Beef" , "Spicy" , 0) ;
                    order.display() ;
                    order.bill() ; 
                }
                if(sauce==0 && cheese==1)
                {
                    BeefBurger order(1500 , "Beef , cheese" , "Spicy" , 1) ;
                    order.display() ;
                    order.bill() ; 
                }

                break ;


        }
    }while(choice != 0 && (choice != 1 || choice != 2)) ;


}


