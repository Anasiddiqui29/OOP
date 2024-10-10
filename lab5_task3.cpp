#include <iostream>
#include <cmath>

using namespace std ;

class batsman
{
    string name;  
    int runs ; 
    int balls ; 
    int dismissed ; 

    public:

    batsman(const string &name , int runs)
    {
        this->name = name ; 
        this->runs = runs ; 
    }

    string getname()
    {
        return name ; 
    }

    inline int avg(int Runs , int Dismiss)
    {
        return Runs/Dismiss ; 
    }

    inline int strike_rate(int run , int Balls)
    {
        return (run/Balls)*100 ; 
    }

};

int main()
{
    batsman bat1("Shahid" , 30000); 

    int Avg = bat1.avg(30000 , 200) ;
    int strike = bat1.strike_rate(30000 , 25000) ; 

    cout << "Batsman name: " << bat1.getname() << endl ; 
    cout << "Average: " << Avg << endl ; 
    cout << "Strike rate: " << strike << endl ; 

}