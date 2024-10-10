#include <iostream>
#include <string>

using namespace std ; 

class Employee
{
	protected:
	string name ; 
	int age ;  
	
	public:
	
	Employee(string name , int age)
	{
		this->name = name ; 
		this->age = age ;
	}
	
	int calculateSalary()
	{
		int hours , totalSalary ; 
		cout << "Enter the total number of hours: " <<endl ; 
		cin >> hours ; 
		
		return (hours*1500) + 40000 ; 	
	}
	
} ;

class lawyer : public Employee
{
		public:
		lawyer(string n , int a ) : Employee(n , a) {}
		
		void display()
		{
			int totalsalary = Employee::calculateSalary() ;
			cout << "Name of the lawyer: " << name << endl ; 
			cout << "Age of the lawyer: " << age << endl ; 
			cout << "Total salary: "<<totalsalary<<endl ;  
			cout << "Lawyers know how to sue" << endl ; 	
		}	
} ;

class Marketers : public Employee
{
	public:
	Marketers(string n , int a ) : Employee(n , a) {}
	
	void display()
	{
		int totalsalary = Employee::calculateSalary() + 10000 ;
		cout << "Name of the Marketer: " << name << endl ; 
		cout << "Age of the Marketer: " << age << endl ; 
		cout << "Total salary: "<<totalsalary<<endl ;  
		cout << "Lawyers know how to advertise" << endl ; 
	}	
} ; 

class Secretaries : public Employee
{
	public:
	Secretaries(string n , int a ) : Employee(n , a) {}
	
	int leave_encashment()
	{
		int days ,amt ; 
		cout << "How many days you have availed: " << endl ;
		cin >> days ; 
		
		if(days==0)
		{
			return 5000 ; 
		}
		else
		{
			amt = (5000/10) * days ;
			return 5000-amt ; 
		}
	}
	
	void display()
	{	
		int totalsalary = Employee::calculateSalary() + leave_encashment() ;
		cout << "Name of the Secretary: " << name << endl ; 
		cout << "Age of the Secretary: " << age << endl ; 
		cout << "Total salary: "<<totalsalary<<endl ;  
		cout << "Lawyers know how to advertise" << endl ; 
	}	
	
} ;

class legal_secretaries : public Employee
{
	public:
	legal_secretaries(string n , int a ) : Employee(n , a) {}
	
	void display()
	{	
		int totalsalary = Employee::calculateSalary() + 5000 ;
		cout << "Name of the Legal Secretary: " << name << endl ; 
		cout << "Age of the Legal Secretary: " << age << endl ; 
		cout << "Total salary: "<<totalsalary<<endl ;  
		cout << "Legal secretaries know how to prepare legal documents" << endl ; 
	}	
	
} ; 


int main()
{
	lawyer law1("Rajesh" , 25) ;
	law1.display() ;
	
	Marketers mark("Rehan" , 20) ;
	mark.display() ;
	
	Secretaries sec1("Hamad" , 27) ;
	sec1.leave_encashment() ;
	sec1.display() ; 
	
	legal_secretaries leg("Hasan" , 30) ;
	leg.display() ; 
	
	
	
}







