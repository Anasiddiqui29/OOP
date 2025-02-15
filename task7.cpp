#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

void findpair(int arr[] , int n , int num)
{
    int pairsInteger[n] , num1 , num2 , paircount=0 ;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[i]+arr[j] == num)
            {
                cout << "Pair found: " << arr[i] << "," << arr[j] << endl ;
                pairsInteger[paircount++] = arr[i] ;
                pairsInteger[paircount++] = arr[j] ;
            } 
        }
    }

    //sorting new array in ascending order
    for(int i=0 ; i<paircount ; i++)
    { 
        for(int j = i+1 ; j<paircount ; j++)
        {
            if(pairsInteger[i]>pairsInteger[j])
            {
                int temp = pairsInteger[j] ;
                pairsInteger[j] = pairsInteger[i] ;
                pairsInteger[i] = temp ; 
            }
        } 
    }

    //printing sorted array
    for(int i=0 ; i<n ; i++)
    {
        cout << " " << pairsInteger[i] ; 
    }

}

int main()
{
    int n , num ; 

    cout << "Enter the size of an array: " << endl ; 
    cin >> n ;

    int arr[n] ;

    for(int i=0 ; i<n ; i++)
    {
        cout << "Enter the value: " << endl ; 
        cin >> arr[i] ;
    }

    cout << "Enter the specified number: " << endl ;
    cin >> num ; 

    findpair(arr , n , num) ;

}