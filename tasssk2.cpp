#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

class batsman
{
    int bcode ; 
    char bname[20] ;
    int innings ; 
    int notouts ;
    int runs ; 
    float batavg ; 

    void calavg()
    {
        batavg = runs/(innings-notouts) ;
    }

    public:
    void readdata()
    {
        cout << "Enter the bcode of the batsman: "<< endl ; 
        cin >> bcode ; 

        cout << "Enter the name of the batsman"<< endl ;
        cin >> bname ; 

        cout << "Enter the number of the innings: "<< endl ; 
        cin >> innings ; 

        cout << "Enter the not outs of the batsman: "<< endl ; 
        cin >> notouts ; 

        cout << "Enter the total runs: " <<endl ; 
        cin >> runs ;

        calavg() ;

    }

    void displaydata()
    {
        cout << "Code of batsman: "<< bcode << endl ; 
        cout << "Name of the batsman: "<< bname << endl ; 
        cout << "Number of innings: "<< innings << endl ;
        cout << "Number of notouts: "<< notouts << endl ; 
        cout << "Total runs scored: "<< runs << endl ; 
        cout << "Batting average: " << batavg << endl ; 
    }
};

int main()
{
    batsman player ;
    player.readdata() ;
    player.displaydata() ;
}