#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std ; 

//Super class
class DessertItem
{
    protected:
    string name ;

    public:
    DessertItem(string name)
    {
        this->name = name ; 
    }
    virtual int getCost() {} ;

    string getname()
    {
        return name ;
    }

} ;

class Candy : public DessertItem
{
    float weight ; 
    float price_per_pound ; //in cents
    int calories ;

    public:
    Candy(float weight , float price_per_pound ,int calories, string n) : DessertItem(n) 
    {
        this->weight = weight ; 
        this->price_per_pound = price_per_pound ; 
        this->calories = calories ;
    }

    int getCost() 
    {
        float a = weight * price_per_pound ;
        int n = round(a) ; // rounding it off to the nearest decimal 

        return n ; 
    }

    void setCalories(int calories)
    {
        this->calories = calories ; 
    }
    int getcalories()
    {
        return calories ;
    }

} ;

class Cookie : public DessertItem
{
    int number ; //number of cookies
    float price_per_dozen ; 
    int calories ; 

    public:
    Cookie(int number , float price_per_dozen ,int calories, string n) : DessertItem(n)
    {
        this->number = number;
        this->price_per_dozen = price_per_dozen ;
        this->calories = calories ;
    }

    int getCost()
    {
        float n = (price_per_dozen/12) * number; 
        int a = round(n) ;

        return a ;
    }
    void setCalories(int calories)
    {
        this->calories = calories ; 
    }
    int getcalories()
    {
        return calories ;
    }

} ;

class IceCream : public DessertItem
{
    protected:
    int cost ;
    int calories ; 

    public:
    IceCream(int cost , int calories , string n) : DessertItem(n)
    {
        this->cost = cost ; 
        this->calories = calories ;
    }

    virtual int getCost()
    {
        return cost ; 
    }
    void setCalories(int calories)
    {
        this->calories = calories ; 
    }
    int getcalories()
    {
        return calories ;
    }


} ;

class Sundae : public IceCream
{
    int cost_of_topping ; 

    public:
    Sundae(int cost, int calories, int toppingCost, string n) : IceCream(cost, calories, n), cost_of_topping(toppingCost) {}

    int getCost()
    {
        return IceCream::getCost()+cost_of_topping ;
    }

} ;

class Checkout
{
    static const int MAX_ITEMS = 100;
    DessertItem* items[100];
    int itemCount;
    float taxRate;

    public:
    Checkout(int itemCount =0 , float taxRate) : itemCount(itemCount) , taxRate(taxRate)
    {
        for(int i=0 ; i<MAX_ITEMS ; i++)
        {
            items[i] = nullptr ;
        }
    }

    void addItem(DessertItem * item)
    {
        if(itemCount < MAX_ITEMS)
        {
            items[itemCount++] = item ; //Arraylist to store data items
        }
    }

    void clearregister()
    {
        itemCount = 0;
    }

    int getitems()
    {
        return itemCount ;
    }

    int getTotalcost() // without tax
    {
        int total;
        for(int i=0 ; i<itemCount ; i++)
        {
            total += items[i]->getCost() ;
        }
        return total ; 
    }

    int getTax()
    {
        return round(taxRate * getTotalcost()) ;
    }

    void receipt()
    {
        cout << "RECEIPT\n" << endl ; 
        for(int i=0 ; i<itemCount ; i++)
        {
            cout << items[i]->getname() << ": $ " << items[i]->getCost() << endl ; 
        }

        cout << "---------------------------------------------------------------" << endl;
        cout << "Total Cost : $ "<< getTotalcost() /100.0 << " and " << getTotalcost() % 100 << " cents" << endl ; 
        cout << "Tax : $ " << getTax() /100.0 << " and " << getTax() %100 << " cents" << endl;
        cout << "Total cost + tax : $" << (getTotalcost() /100.0) + (getTax() /100.0) <<
        " and " << (getTotalcost() % 100) + (getTax() %100) << endl ;


    }

} ;

int main() 
{
    Checkout checkout(0.10); // Tax rate of 10%
    checkout.addItem(new Candy(2.3, 89, 205, "Fudge"));
    checkout.addItem(new Cookie(4, 399, 133, "Chocolate Chip Cookies"));
    checkout.addItem(new IceCream(200, 250, "Vanilla Ice Cream"));
    checkout.addItem(new Sundae(250, 300, 50, "Sundae with Toppings"));

    checkout.receipt() ;

    return 0;
}
