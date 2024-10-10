#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std ;

const int maxCards = 100 ; 

class Customer
{
    protected:
    string name ; 
    string address ; 
    int license ; 
    int age ; 
    string creditCardsinfo[maxCards] ; 

    public:
    Customer(string name , string address , int license , int age)
    {
        this->name = name ; 
        this->address = address ; 
        this->license = license ; 
        this->age = age ; 
        
        for(int i=0 ; i<maxCards ; i++)
        {
            creditCardsinfo[i] = " " ; //initializing with null string
        }
    }

    string getName()
    {
        return name ; 
    }

    bool ageVerification()
    {
        if(age<18)
        {
            cout << "Cannot rent a car" << endl ; 
            return false ; 
        }
        else
        {
            return true ; 
        }
    }
    bool fee()
    {
        if(age>=18 && age<=25)
        {
            cout << "Young-age fee" << endl ; 
            return true ;
        }
    }

};

class Vehicle
{
    protected:
    string make ; 
    string model ; 

    public:
    Vehicle(string make , string model)
    {
        this->make = make ; 
        this->model = model ; 
    }

    virtual string getVehicleType()=0  ; //Pure virtual function
    virtual void rentalRate() = 0 ;
} ;

class Compact : public Vehicle
{
    int year ; 
    int recent_reading ; 
    string vehicle_id ; 

    public:
    Compact(string m , string mod , int year , int recent_reading , string vehicle_id) 
    : Vehicle(m , mod)
    {
        this->year = year ; 
        this->recent_reading = recent_reading ;
        this->vehicle_id = vehicle_id ; 
    }

    string getVehicleType() override
    {
        return "Comapct" ;
    }

    void rentalRate() override
    {
        int total=0 , days ;
        int weekrate = 1000 ; 
        int monthrate = 4000 ; 

        cout << "Enter the number of days: " << endl ; 
        cin >> days ;

        if(days>29)
        {
            total = monthrate + 2000 ;
            cout << "Your total rent: "<< total << endl ; 
        }
        if(days<29)
        {
            days = days/7 ;
            total = days*weekrate + 2000 ;
            cout << "Your total rent: "<< total << endl ;
        }
    }
} ;

class Standard : public Vehicle
{
    int year ; 
    int recent_reading ; 
    string vehicle_id ; 

    public:
    Standard(string m , string mod , int year , int recent_reading , string vehicle_id) 
    : Vehicle(m , mod)
    {
        this->year = year ; 
        this->recent_reading = recent_reading ;
        this->vehicle_id = vehicle_id ; 
    }

    string getVehicleType() override
    {
        return "Standard" ;
    }

    void rentalRate() override
    {
        int total=0 , days ;
        int weekrate = 1000 ; 
        int monthrate = 4000 ; 

        cout << "Enter the number of days: " << endl ; 
        cin >> days ;

        if(days>29)
        {
            total = monthrate + 3000 ;
            cout << "Your total rent: "<< total << endl ; 
        }
        if(days<29)
        {
            days = days/7 ;
            total = days*weekrate + 3000 ;
            cout << "Your total rent: "<< total << endl ;
        }
    }
} ;

class luxury : public Vehicle
{
    int year ; 
    int recent_reading ; 
    string vehicle_id ; 

    public:
    luxury(string m , string mod , int year , int recent_reading , string vehicle_id) 
    : Vehicle(m , mod)
    {
        this->year = year ; 
        this->recent_reading = recent_reading ;
        this->vehicle_id = vehicle_id ; 
    }

    string getVehicleType() override
    {
        return "Luxury" ;
    }

    void rentalRate() override
    {
        int total=0 , days ;
        int weekrate = 1000 ; 
        int monthrate = 4000 ; 

        cout << "Enter the number of days: " << endl ; 
        cin >> days ;

        if(days>29)
        {
            total = monthrate + 4000 ;
            cout << "Your total rent: "<< total << endl ; 
        }
        if(days<29)
        {
            days = days/7 ;
            total = days*weekrate + 4000 ;
            cout << "Your total rent: "<< total << endl ;
        }
    }
} ;

class Contracts : public Customer
{
    string vehicleMake;
    string vehicleModel;
    string startDate;
    string endDate;
    double rentalRate;
    double youngAgeFee;

    public:
    Contracts(string n,string a,int ag,int lic , string vehicleMake, string vehicleModel, string startDate, 
    string endDate,double youngAgeFee ,  double rentalRate, bool youngDriver) 
    : Customer(n ,a , lic , age)
    {
        this->vehicleMake = vehicleMake;
        this->vehicleModel = vehicleModel;
        this->startDate = startDate;
        this->endDate = endDate;
        this->rentalRate = rentalRate;
        this->youngAgeFee = youngAgeFee ; 
    }

    string getVehicleMake() const 
    {
        return vehicleMake;
    }

    string getVehicleModel() const 
    {
        return vehicleModel;
    }

    string getStartDate() const 
    {
        return startDate;
    }

    string getEndDate() const 
    {
        return endDate;
    }

    double getRentalRate() const 
    {
        return rentalRate;
    }

    double getyoungAgefee() const
    {
        return youngAgeFee ; 
    }

    double getTotalfee()
    {
        double totalFee = rentalRate;
        if (Customer::fee()) { // If customer is subject to young-age fee
            totalFee += youngAgeFee;
        }
        // You can add more logic here to calculate additional fees if needed
        return totalFee;
    }



};

int main() {
    // Create a customer
    Customer customer("John Doe", "123 Main St", 12345, 30);

    // Create vehicle instances
    Compact compact("Toyota", "Corolla", 2022, 5000, "ABC123");
    Standard standard("Honda", "Accord", 2021, 6000, "XYZ456");
    luxury luxuryCar("Mercedes", "S-Class", 2023, 7000, "DEF789");

    // Display vehicle types
    cout << "Vehicle Types:" << endl;
    cout << compact.getVehicleType() << endl;
    cout << standard.getVehicleType() << endl;
    cout << luxuryCar.getVehicleType() << endl;

    cout << "\nRental Rates:" << endl;
    cout << "Compact Rental Rate: ";
    compact.rentalRate();
    cout << "Standard Rental Rate: " ;
    standard.rentalRate();
    cout << "Luxury Rental Rate: ";
    luxuryCar.rentalRate();

    // Create a rental contract
    Contracts contract("John Doe", "123 Main St", 12345, 30, "Toyota", "Corolla", "2024-05-01", "2024-05-05", 50.0, 200.0, false);

    // Display contract details
    cout << "\nContract Details:" << endl;
    cout << "Customer Name: " << customer.getName() << endl;
    cout << "Vehicle: " << contract.getVehicleMake() << " " << contract.getVehicleModel() << endl;
    cout << "Start Date: " << contract.getStartDate() << endl;
    cout << "End Date: " << contract.getEndDate() << endl;
    cout << "Rental Rate: $" << contract.getRentalRate() << " per day" << endl;
    cout << "Young Age Fee: $" << contract.getyoungAgefee() << endl;
    cout << "Total Fee: $" << contract.getTotalfee() << endl;

    return 0;
}


