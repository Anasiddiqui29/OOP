#include <iostream>
#include <cmath>

using namespace std ;

class Appointment
{
    string appoint ; 
    int cost ;

    static int num_appointment ; 
    static int total ; 

    public:

    Appointment(const string &appointment , int cost)  
    {
        
        num_appointment++ ; 
        total = total+cost ;  
        this->cost = cost ;
        appoint = appointment ; 
    }

    string get_appoint()
    {
        return appoint ; 
    }
     
    static int get_num_appointments()
    {
        return num_appointment;
    }

    static int get_total_cost() 
    {
        return total;
    }

    static int t_cost()
    {
        int avg ; 

        avg = total / num_appointment ;  

        return avg ; 
    }

    
} ;

int Appointment::num_appointment = 0;
int Appointment::total = 0;

int main()
{
    Appointment app1("Appointment 1 Time : 0800" , 2000 ) ;
    Appointment app2("Appoinment 2 Time : 0830" , 6000 ) ;
    Appointment app3("Appoinment 3 Time : 0900" , 7000 ) ;
    Appointment app4("Appoinment 4 Time : 0930" , 3000 ) ;

    cout << "Number of appointments: " << Appointment :: get_num_appointments() << endl ; 
    cout << "Total cost: " << Appointment :: get_total_cost() << endl ; 
    cout << "Number of appointments: " << Appointment :: t_cost() << endl ; 
}
