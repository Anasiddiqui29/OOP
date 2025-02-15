#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

class calendar
{
    int yeardetail ;
    
    string jan[31] ;
    string feb[28] ;
    string mar[31] ;
    string apr[30] ;
    string may[31] ;
    string jun[30] ;
    string july[31] ;
    string aug[30] ;
    string sept[31] ;
    string oct[30] ;
    string nov[31] ;
    string dec[30] ;
    
    public:

    void addtask(string detail , int month , int date)
    {
        switch(month)
        {
            case 1:
                if(date>=1 && date<=31)
                {
                    jan[date-1] = detail ;
                }
                break;
            case 2:
            if (date >= 1 && date <= 28)
                {
                    feb[date - 1] = detail;
                }
                break;
            case 3:
                if (date >= 1 && date <= 31)
                {    
                    mar[date - 1] = detail;
                }
                break;
            case 4:
                if (date >= 1 && date <= 30)
                {
                    apr[date - 1] = detail;
                }
                break;
            case 5:
                if (date >= 1 && date <= 31)
                {
                    may[date - 1] = detail;
                }
                break;
            case 6:
                if (date >= 1 && date <= 30)
                {
                    jun[date - 1] = detail;
                }
                break;
            case 7:
                if (date >= 1 && date <= 31)
                {
                    july[date - 1] = detail;
                }
                break;
            case 8:
                if (date >= 1 && date <= 31)
                {
                    aug[date - 1] = detail;
                }
                break;
            case 9:
                if (date >= 1 && date <= 30)
                {
                    sept[date - 1] = detail;
                }
                break;
            case 10:
                if (date >= 1 && date <= 31)
                {
                    oct[date - 1] = detail;
                }
                break;
            case 11:
                if (date >= 1 && date <= 30)
                {
                    nov[date - 1] = detail;
                }
                break;
            case 12:
                if (date >= 1 && date <= 31)
                {
                    dec[date - 1] = detail;
                }
                break;
            default:
                cout << "Invalid month!" << endl;
                break;
        }
    }

    void removetask(int month , int date)
    {
        switch(month)
        {
            case 1:
                if(date>=1 && date<=31)
                {
                    jan[date-1] = " " ;
                }
                break;
            case 2:
            if (date >= 1 && date <= 28)
                {
                    feb[date - 1] = " ";
                }
                break;
            case 3:
                if (date >= 1 && date <= 31)
                {    
                    mar[date - 1] = " ";
                }
                break;
            case 4:
                if (date >= 1 && date <= 30)
                {
                    apr[date - 1] = " ";
                }
                break;
            case 5:
                if (date >= 1 && date <= 31)
                {
                    may[date - 1] = " ";
                }
                break;
            case 6:
                if (date >= 1 && date <= 30)
                {
                    jun[date - 1] = " ";
                }
                break;
            case 7:
                if (date >= 1 && date <= 31)
                {
                    july[date - 1] = " ";
                }
                break;
            case 8:
                if (date >= 1 && date <= 31)
                {
                    aug[date - 1] = " ";
                }
                break;
            case 9:
                if (date >= 1 && date <= 30)
                {
                    sept[date - 1] = " ";
                }
                break;
            case 10:
                if (date >= 1 && date <= 31)
                {
                    oct[date - 1] = " ";
                }
                break;
            case 11:
                if (date >= 1 && date <= 30)
                {
                    nov[date - 1] = " ";
                }
                break;
            case 12:
                if (date >= 1 && date <= 31)
                {
                    dec[date - 1] = " ";
                }
                break;
            default:
                cout << "Invalid month!" << endl;
                break;
        }
    }

    void updatedlist()
    {
        for(int i=0 ; i<12 ; i++)
        {
            cout << "January" << endl ; 
            for(int i=0 ; i<31 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << jan[i] << endl ;  
            }
            cout << "Feb" << endl ; 
            for(int i=0 ; i<28 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << feb[i] << endl ;  
            }
            cout << "March" << endl ; 
            for(int i=0 ; i<31 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << mar[i] << endl ;  
            }
            cout << "April" << endl ; 
            for(int i=0 ; i<31 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << apr[i] << endl ;  
            }
            cout << "May" << endl ; 
            for(int i=0 ; i<31 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << may[i] << endl ;  
            }
            cout << "June" << endl ; 
            for(int i=0 ; i<31 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << jun[i] << endl ;  
            }
            cout << "July" << endl ; 
            for(int i=0 ; i<31 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << july[i] << endl ;  
            }
            cout << "August" << endl ; 
            for(int i=0 ; i<31 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << aug[i] << endl ;  
            }
            cout << "September" << endl ; 
            for(int i=0 ; i<31 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << sept[i] << endl ;  
            }
            cout << "October" << endl ; 
            for(int i=0 ; i<31 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << oct[i] << endl ;  
            }
            cout << "November" << endl ; 
            for(int i=0 ; i<31 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << nov[i] << endl ;  
            }
            cout << "December" << endl ; 
            for(int i=0 ; i<31 ; i++)
            {
                cout << "Details for day " << i+1 << ": " << dec[i] << endl ;  
            }
        }
    }
};

int main()
{
    calendar me ; 

    me.addtask("party" , 1 , 1); 
    me.addtask("sports" , 3 , 25);
    me.addtask("gym" , 4 , 12);
    me.addtask("Sleeping" , 8 , 23);
    me.addtask("Vote" , 9 , 17);
    me.addtask("Chill" , 10 , 15);

    me.removetask(3,25) ;

    me.updatedlist() ;
}