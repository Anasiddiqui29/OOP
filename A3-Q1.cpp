#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std ;

//Running fine

class Medicine
{
    protected:
    string name ; 
    string formula ; 
    double retail_price ; 
    string manufacturing_date ; 
    string expiration_date ; 

    public:
    Medicine(string name , string formula , double retail_price , string manufacturing_date , string expiration_date)
    {
        this->name = name ; 
        this->formula = formula ; 
        this->retail_price = retail_price ; 
        this->manufacturing_date = manufacturing_date ; 
        this->expiration_date = expiration_date ;
    }
    Medicine() {} ;

    //getters and setters
    void setname(string n)
    {
        name = n ; 
    }
    void setformula(string f)
    {
        formula = f ; 
    }
    void setprice(double p)
    {
        retail_price = p ; 
    }
    void setmanufacturing_date(string md)
    {
        manufacturing_date = md ; 
    }
    void setexpiration_date(string ed)
    {
        expiration_date = ed ; 
    }

    string getname(){return name ; }
    string getformula(){return formula ; }
    double getprice(){return retail_price ; }
    string getmdate(){return manufacturing_date ; }
    string getedate(){return expiration_date ; }

    virtual void display()
    {
        cout << "Here is the details of the Medicine" << endl ; 
        cout << "Name: " << name << endl ;
        cout << "Formula: " << formula << endl ;
        cout << "Price: " << retail_price << endl ; 
        cout << "Manufacturing date: " << manufacturing_date << endl ; 
        cout << "Expiration date: " << expiration_date << endl ;  
    }

    bool operator == (const Medicine &m)
    {
        Medicine temp ; 
        if(temp.expiration_date == m.expiration_date)
        {
            return true ;
        }
        else
        {
            return false ; 
        }
        
    }

} ;

class Tablet : public Medicine
{
    int sucrose_lvl ; //either 0 or 1

    public:
    Tablet(string n , string f , double p , string md , string ed , int sucrose_lvl)
    : Medicine(n , f , p , md , ed)
    {
        this->sucrose_lvl = sucrose_lvl ; 
    }

    void display() override
    {
        cout << "Here is the details of the Tablet" << endl ; 
        cout << "Name: " << name << endl ;
        cout << "Formula: " << formula << endl ;
        cout << "Sucrose level: " << sucrose_lvl << endl ; 
        cout << "Price: " << retail_price << endl ; 
        cout << "Manufacturing date: " << manufacturing_date << endl ; 
        cout << "Expiration date: " << expiration_date << endl ;
    }
} ;

class Capsule : public Medicine
{
    int absorption_lvl ; 

    public:
    Capsule(string n ,string f , double p , string md , string ed , int absorption_lvl)
    : Medicine(n , f , p , md , ed)
    {
        this->absorption_lvl = absorption_lvl ; 
    }

    void display() override
    {
        cout << "Here is the details of the Tablet" << endl ; 
        cout << "Name: " << name << endl ;
        cout << "Formula: " << formula << endl ;
        cout << "Absorption level: " << absorption_lvl << endl ; 
        cout << "Price: " << retail_price << endl ; 
        cout << "Manufacturing date: " << manufacturing_date << endl ; 
        cout << "Expiration date: " << expiration_date << endl ;
    }
} ;

class Syrup : public Medicine
{
    string taste ;

    public:
    Syrup(string n ,string f , double p , string md , string ed , string taste)
    : Medicine(n , f , p , md , ed)
    {
        this->taste = taste ; 
    }

     void display() override
    {
        cout << "Here is the details of the Tablet" << endl ; 
        cout << "Name: " << name << endl ;
        cout << "Formula: " << formula << endl ;
        cout << "Taste: " << taste << endl ; 
        cout << "Price: " << retail_price << endl ; 
        cout << "Manufacturing date: " << manufacturing_date << endl ; 
        cout << "Expiration date: " << expiration_date << endl ;
    }
} ;

class Pharmacist
{
    public:
    void search_medicine(Medicine * med[] , int size , string formula)
    {
        for(int i=0 ; i<size ; i++)
        {
            if(med[i]->getformula() == formula)
            {
                med[i]->display() ; 
            }
        }
    }
} ;

class Counter
{
    int nprice ; 

    public:

    Counter(int nprice)
    {
        this->nprice = nprice ;
    }

    bool search_medicine(Medicine * med[] , int size , string name)
    {
        for(int i=0 ; i<size ; i++)
        {
            if(med[i]->getname() == name)
            {
                med[i]->display() ; 
                nprice = med[i]->getprice() ; 
                return true ; 
            }
            else
            {
                return false ; 
            }
        }
    }

    void Update_Revenue(Medicine * med[], int size)
    {
        int price ; 
        price += nprice ; 
    }

} ;

int main() 
{
    cout << "Muhammad Anas Siddiqui" << endl ; 
    cout << "23k-0575" << endl ; 
    // Creating instances of medicines
    Medicine* medicines[3];
    medicines[0] = new Tablet("Paracetamol", "Acetaminophen", 5.99, "2023-01-01", "2023-12-31", 0);
    medicines[1] = new Capsule("Ibuprofen", "Ibuprofen", 7.99, "2023-02-01", "2023-12-31", 1);
    medicines[2] = new Syrup("Cough Syrup", "Dextromethorphan", 9.99, "2023-03-01", "2023-12-31", "Cherry");

    cout << "Displaying details of medicines:" << endl;
    for (int i = 0; i < 3; ++i) {
        medicines[i]->display();
        cout << endl;
    }

    Pharmacist pharmacist;
    Counter counter(0);

    // Searching for medicines by formula
    cout << "Searching for medicines by formula:" << endl;
    pharmacist.search_medicine(medicines, 3, "Acetaminophen");

    // Searching for a specific medicine
    cout << "Searching for a specific medicine:" << endl;
    counter.search_medicine(medicines, 3, "Paracetamol");

    counter.Update_Revenue(medicines, 3);

    // Deleting dynamically allocated memory
    for (int i = 0; i < 3; ++i) 
    {
        delete medicines[i];
    }

    return 0;
}




