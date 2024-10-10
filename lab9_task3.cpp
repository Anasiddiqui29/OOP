#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std ;

class Car
{
    protected:
    int model_number ;
    int year ; 
    int original_price ; 

    public:
    Car(int model_number , int year , int original_price)
    {
        this->model_number = model_number ;
        this->year = year ;
        this->original_price = original_price ; 
    }

    virtual int calculate_Sales_price(){}

    int getmodelnum()
    {
        return model_number ;
    }
    int getyear()
    {
        return year ;
    }
    int getoriginal()
    {
        return original_price ; 
    }

} ;

class Sports : public Car
{
    int tax ; 

    public:
    Sports(int tax , int m , int y ,int o) : Car(m ,y , o)
    {
        this->tax = tax ;
    }

    int calculate_Sales_price()
    {
        return (original_price+tax) ; 
    }
} ;

class Classic : public Car
{ 
    public:
    Classic(int m , int y ,int o) : Car(m ,y , o )
    {
        
    }

    int calculate_Sales_price()
    {   
        if(Car::getyear() > 2000)
        {
            return original_price*0.75 ;
        }
        else
        {
            if(Car::getyear() >1995)
            {
                return original_price*0.50 ;
            }
            else
            {
                return original_price*0.25 ;  
            }
        }
    }
} ;

class Sedan : public Car
{
    int discount ;  

    public:
    Sedan(int discount  , int m , int y , int o) : Car(m ,y , o)
    {
        this->discount = discount ; 
    }

    int calculate_Sales_price()
    {
        return original_price - discount ;  
    }


} ;

class Exhibition  
{
    int year_exhibition ; 
    Car * cars[100] ;

    public:
    Exhibition(int yearOfExhibition) : year_exhibition(yearOfExhibition) 
    {
        for(int i=0 ; i<100 ; i++)
        {
            cars[i] = nullptr ; 
        }
    }

    void addCar(int modelNumber, int year, int sale ,int discount = 0,int tax = 0 )  
    {
        // Determine car type based on year
        Car* car;
        if (year > 2000)
        {
            car = new Classic(modelNumber, year ,sale);
        }
        else if (year > 1995)
        {
            car = new Sports(tax,modelNumber, year , sale);
        }
        else
        {
            car = new Sedan(discount,sale,modelNumber, year);
        }
        // Add car to exhibition
        for (int i = 0; i < 100; i++) 
        {
            if (!cars[i]) 
            {
                cars[i] = car;
                break;
            }
        }
    }

    void display()
    {
        cout << "Details of Cars" << endl ; 

        for(int i=0 ; i<100 ; i++)
        {
            cout << "Model number: " << cars[i]->getmodelnum() << endl ;
            cout << "Price: $ " << cars[i]->calculate_Sales_price() << endl ; 
        }
    }
} ;

int main()
{
    Exhibition exhibition(2024);

    // Add cars to the exhibition
    exhibition.addCar(101, 2005,21000000);
    exhibition.addCar(102, 1998, 2000000 ,500); // SportsCar with tax
    exhibition.addCar(103, 1990,21110000 , 1000); // SedanCar with discount

    exhibition.display();

    return 0;
}
