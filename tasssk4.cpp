#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

class REPORT
{
    char adno[4] ;
    char name[20] ;
    float marks[5] ; 
    float avg ; 

    void GETAVG()
    {
        int sum = 0 ;
        for(int i=0 ; i<5 ; i++)
        {
            sum = sum + marks[i] ; 
        }
        avg = sum/5 ; 
    }

    public:

    void READINFO()
    {
        cout << "Enter the admission number: " << endl ; 
        cin >> adno ;

        cout << "Enter the name: " << endl; 
        cin >> name ; 

        for(int i=0 ; i<5 ; i++)
        {
            cout << "Enter the marks for subject " << i+1 << endl ; 
            cin >> marks[i] ;
        }

        GETAVG() ;
    }

    void DISPLAYINFO()
    {
        cout << "--------------------------------------------------" << endl ;
        cout << "Detailed information of the child" << endl ; 
        cout << "Admission number: " << adno << endl ; 
        cout << "Name: " << name << endl ;

        for(int i=0 ; i<5 ; i++)
        {
            cout << "Marks of subject "<< i+1 << ": " << marks[i] <<endl ; 
        }

        cout << "Average: " << avg << endl ; 
    }

} ;

int main()
{
    REPORT student;

    student.READINFO() ;

    student.DISPLAYINFO() ;
}