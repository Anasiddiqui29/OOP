#include <iostream>
#include <cmath>
using namespace std ;

class Electricity
{
	int consumer_no ;
	string consumer_name ; 
	int pmonth ;
	int cmonth ; 
	char eb ; 
	
	public:
		
	Electricity()
	{
		cout << "Welcome to Bill generator" << endl ; 
	}
	
	int calbill(char type , int p_month , int c_month)
	{
		int units[4] = {100 , 201 , 501} ; 
		float dprice[4] = {1.0 , 2.5 , 4 , 6} ;
		float cprice[4] = {2 , 4.50 , 6 , 7} ;
		
		float bill ; 
		int unit = c_month - p_month ;
		
		if(type == 'D')
		{
			if(unit == units[0])
			{
				bill = unit * dprice[0] ; 
			}
			if(unit > units[0] && unit < units[1])
			{
				bill = unit * dprice[1] ; 
			}
			if(unit >= units[1] && unit < units[2])
			{
				bill = unit * dprice[2] ; 
			}
			if(unit > units[2])
			{
				bill = unit *  dprice[3] ;
			}
			
		}
		if(type == 'C')
		{
			if(unit == units[0])
			{
				bill = unit * cprice[0] ; 
			}
			if(unit > units[0] && unit < units[1])
			{
				bill = unit * cprice[1] ; 
			}
			if(unit >= units[1] && unit < units[2])
			{
				bill = unit * cprice[2] ; 
			}
			if(unit > units[2])
			{
				bill = unit * cprice[3] ; 
			}
			
		}
		return bill ; 
	}
	
	void getinput()
	{
		cout << "Enter consumer number: " << endl ; 
		cin >> consumer_no ; 
		cout << "Enter tyoe of connection(D for domestic and C for commercial): " << endl ; 
		cin >> eb ;
		cout << "Enter consumer name: " << endl ; 
		cin >> consumer_name ;
		cout << "Enter previous month reading: " << endl ; 
		cin >> pmonth ; 
		cout << "Enter current month reading: " << endl ; 
		cin >> cmonth ; 
		
		
	}
	
	void display()
	{
		cout << "Detail information"<<endl ; 
		
		cout << "Consumer Number: " << consumer_no << endl ; 
		cout << "Consumer Name: " << consumer_name << endl; 
		if(eb == 'D')
		{
			cout << "Type of connection: Domestic "<< endl ; 
		}
		else
		{
			cout << "Type of connection: Commercial" << endl ; 
		}
		cout << "Current month reading: " << cmonth << endl ; 
		cout << "Previous month reading: " << pmonth << endl ; 
		
		int Unit = cmonth - pmonth ; 
		
		cout << "Total units: " << Unit << endl ; 
		
		float BILL ; 
		BILL = calbill(eb , pmonth , cmonth) ;
		
		cout << "Total bill: " << BILL << endl ; 
	}	
		
} ;


int main()
{
	Electricity bill1 ; 
	int decision ; 
	
	do
	{
	
		bill1.getinput() ;
		bill1.display() ;
		
		cout << "Do you want to continue(Press 1 for yes or 0 to exit) : "<< endl ; 
		cin >> decision ;
		
	}while(decision == 1) ;
	
}
