#include <iostream>
#include <cmath>
using namespace std ;

class Number
{
	float num ; 
	int result ; 
	
	public:
	
	//parameterize constructor
	Number(float num)
	{
		this->num = num ; 	
	}
	
	int checkwholenum()
	{
		float rem ;
		
		rem = num - int(num) ;  
		
		if(rem > 0)
		{
			return 0 ;
		}
		if(rem ==0)
		{
			return 1 ; 	
		} 
	}
	
	int checkpos()
	{
		if(num < 0)
		{
			return 0 ;
		}
		else
		{
			return 1 ; 
		}
	}
	
	int Factorial()
	{
		result = 1 ; 
		int num2 = num ;
		
		while(num2 > 0)
		{
			result = result * (num2) ;
			num2 = num2 - 1 ; 
		}
		return result ; 
	}
	
	void display()
	{
		cout << "Factorial of "<< num << " is: " << result << endl  ; 
	}
	
		
	
} ;

int main()
{

	Number num1(5.2) ; 
	
	int res1 , res2 ;
	res1 = num1.checkpos() ;
	res2 = num1.checkwholenum() ;
	
	if(res1==1 && res2 ==1)
	{
		num1.Factorial() ;
		num1.display() ;
	}
	else
	{
		cout << "Number not valid" << endl ; 
	}
	
	 
}
