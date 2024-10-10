#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std ; 

class Package
{
    protected:

    string name ; 
    string address ;
    string city ; 
    string state ; 
    int zip;
    int weight ; 
    int cost ;

    public:
    Package(string name , string address , string city , string state , int zip , int weight , int cost)
    {
        this->name = name ; 
        this->address = address ; 
        this->city = city ; 
        this->state = state ; 
        this->zip = zip ; 
        this->weight = weight ; 
        this->cost = cost ; 
    }

    void authentication()
    {
        if(weight < 0 || cost<0)
        {
            cout << "Incorrect input" << endl;
        }
    }

    double calculateCost()
    {
        int total ;
        total = weight * cost ;

        return total;   
    }

} ;

class TwoDayPackage : public Package 
{
    int flatflee ;
    
    public:
    TwoDayPackage(string n ,string a , string c , string s , int z , int w, int co , int flatflee) : Package(n,a,c,s,z,w,co)
    {
        this->flatflee = flatflee ; 
    }

    int ship_cost()
    {
        int t_cost ; 
        t_cost = flatflee + Package::calculateCost() ; 
        return t_cost ; 
    }

};

class OvernightPackage : public Package
{
    int additional_cost ; 

    public:
    OvernightPackage(string n ,string a , string c , string s , int z , int w, int co , int additional_cost) : Package(n,a,c,s,z,w,co)
    {
        this->additional_cost = additional_cost ; 
    }

    int calculateadditional()
    {
        int t_cost ; 
        t_cost = additional_cost + Package::calculateCost() ;
        return t_cost ; 
    }
};

int main()
{
    TwoDayPackage pack1[2] = { TwoDayPackage("Rajesh" , "Gulshan" , "Karachi" , "Sindh" , 2345 , 23 , 20,100) ,
    TwoDayPackage("Rehan" , "DHA" , "Lahore" , "Punjab" , 5467 , 25 , 15,100)
    } ;

    OvernightPackage pack2[2] = { OvernightPackage("Rajesh" , "Gulshan" , "Karachi" , "Sindh" , 2345 , 23 , 20,500) ,
    OvernightPackage("Rehan" , "DHA" , "Lahore" , "Punjab" , 5467 , 25 , 15,500)
    };    

    cout<< "Two Day Package details" << endl ; 
    for(int i=0 ; i<2 ; i++)
    {
        pack1[i].authentication() ;
        cout << "Package "<<i+1 <<" : $ " << pack1[i].ship_cost() <<endl ;  ;
    }
    cout<< "Overnight Package details" << endl ; 
    for(int i=0 ; i<2 ; i++)
    {
        cout << "Package "<<i+1 <<" : $ " << pack2[i].calculateadditional() <<endl ;
    }

}

