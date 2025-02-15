#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

int mod(int n , int m)
{
    //base case
    if(m>n)
    {
        return n ; 
    }
    else
    {
        return mod(n-m , m) ;
    }
}

int main()
{
    int m , n ;

    cout << "Enter the value of n: " << endl ;
    cin >> n ;

    cout << "Enter the value of m: " << endl ;
    cin >> m ;

    int res = mod(n , m) ;

    cout << "Result : "<< res << endl ; 
}