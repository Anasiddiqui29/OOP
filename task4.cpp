#include <iostream>
#include <cmath>
#include <cctype>
#include <string>

using namespace std ;

int equalsIgnorecase(char arr1[], int size1 , char arr2[] , int size2)
{
    int count = 0 ; 
    if(size1==size2)
    {
        for(int i=0 ; i<size1 ; i++)
        {
            if(tolower(arr1[i]) == tolower(arr2[i])) //converting uppercase to lower case (lowercase remains lowercase)
            {
                count = count + 1 ;
            }
 
        }
    }

    if(count == size1)
    {
        return 1 ;
    }
    else
    {
        return 0 ; 
    }
}

int main()
{
    int size1 , size2 ;

    //taking input from the user
    cout << "Enter the size of array 1: " << endl ;
    cin >> size1 ;

    char arr1[size1] ;

    cout << "Enter the size of array 2: " << endl ;
    cin >> size2 ;

    char arr2[size2] ;

    for(int i=0 ; i<size1 ; i++)
    {
        cout << "Enter the character " << i+1 << " of array 1: " << endl ; 
        cin >> arr1[i] ;
    }

    for(int i=0 ; i<size2 ; i++)
    {
        cout << "Enter the character " << i+1 << " of array 2: " << endl ; 
        cin >> arr2[i] ;
    }

    //calling function
    int res = equalsIgnorecase(arr1 , size1 , arr2 , size2) ;

    
    if(res == 1)
    {
        cout << "True" << endl ; 
    }
    else
    {
        cout << "False" << endl ; 
    }

}