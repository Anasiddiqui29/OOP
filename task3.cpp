#include <iostream>
#include <cmath>
using namespace std ;

void printReverse(char *car , int len)
{
	int i ; 
	
	//storing in reverse order
	for(i=0 ; i<len/2 ; i++)
	{
		char temp = car[i] ;
		car[i] = car[len-i-1] ;
		car[len-i-1] = temp ;  
	}

	//printing modified array
	for(i=0 ; i<len ; i++)
	{
		cout << car[i] << " " << endl ; 
	}

}


int main()
{
	int len , i ; 
	
	cout << "Enter the size of an array: " << endl ; 
	cin >> len ;
	
	char arr[len] ; 
	
	for(i=0 ; i<len ; i++)
	{
		cout << "Enter the value: " << endl ; 
		cin >> arr[i] ; 
	}
	
	//calling function
	printReverse(arr , len) ;
	
}
