#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std ; 

class Box
{
    protected:
    int capacity ; 
    float cost ; 

    public:
    Box(int capacity , float cost)
    {
        this->capacity = capacity ;
        this->cost = cost ; 
    }

};

class largeBox : public Box
{
    public:
    largeBox(int c , float co) : Box(c , co) {}

};

class mediumBox : public Box
{
    public:
    mediumBox(int c , float co) : Box(c , co) {}

} ;

class smallBox : public Box
{
    public:
    smallBox(int c , float co) : Box(c , co) {}
} ;

class coffee : public largeBox , public mediumBox , public smallBox
{
    float order_price ; 
    int bags ;
    int large ; 
    int medium ; 
    int small; 
    
    public:
    coffee(float order_price,int bags , int large , int medium , int small , int largeCapacity, float largeCost, int mediumCapacity, float mediumCost, int smallCapacity, float smallCost):
    largeBox(largeCapacity, largeCost), mediumBox(mediumCapacity, mediumCost), smallBox(smallCapacity, smallCost)
    {
        this->order_price = order_price ; 
        this->bags = bags ; 
        this->large = large ; 
        this->medium = medium ; 
        this->small = small ; 
    }

    void calculateNumBoxes()
    {
        large = bags / largeBox::capacity ; 
        medium = (bags % largeBox::capacity) / mediumBox::capacity ; 
        small = (bags - (large*largeBox::capacity + medium*mediumBox::capacity)) / smallBox::capacity ;

    }

    void display()
    {
        cout << "Number of bags ordered : " << bags << endl ; 
        cout << "The cost of the order: $" << order_price << endl ; 
        cout << "Boxes used: " << endl ; 
        cout << large << " Large" << "- $" << large*largeBox::cost << endl ; 
        cout << medium << " Medium" << "- $" <<medium*mediumBox::cost << endl ; 
        cout << small << " Small" << "- $" <<small*smallBox::cost << endl ;
        cout << "Your total cost : $" << order_price + large*largeBox::cost + medium*mediumBox::cost + small*smallBox::cost <<endl ; 
    }

} ;

int main()
{
    int quantity ; 
    cout << "Enter the total number of bags: "<< endl ; 
    cin >> quantity ;

    coffee order1(286.00 , quantity , 0,0,0 , 20 , 1.80, 10 , 1.0 , 5 , 0.60) ;
    order1.calculateNumBoxes();
    order1.display() ; 

}