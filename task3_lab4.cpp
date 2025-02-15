#include <iostream>
#include <cmath>
using namespace std ;

class Employee
{
    int empcode ; 
    string empname ; 

    void setEmpcode(int code)
    {
        empcode = code ; 
    }

    int getEmpcode()
    {
        return empcode ; 
    }

    void setEmpname(string name)
    {
        empname = name ; 
    }

    string getEmpname()
    {
        return empname ; 
    }

    public:
    
    Employee() {}
  
    Employee(int code ,string name) 
    {
        empcode = code ; 
        empname = name ; 
    }

    void display()
    {
        cout << "Employee name: " << empname << endl ; 
        cout << "Employee code: " << empcode << endl ; 
    }
} ; 

int main()
{
    Employee emp[6] ;

    for(int i=0 ; i<6 ; i++)
    {
        cout << "Enter the name of employee "<< i+1 << " :" << endl ; 
        string Name ;
        cin >> Name ; 
        int Code ; 
        cout << "Enter the code of employee " << i+1 << " :" << endl ; 
        cin >> Code ; 

        emp[i] = Employee(Code , Name) ; //calling parameterized constructor
    }

    //displaying employees information

    for(int i = 0 ; i<6 ; i++)
    {
        emp[i].display() ;
    }


}