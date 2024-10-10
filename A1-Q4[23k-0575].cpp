#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

class RollerCoaster
{
    string name ; 
    int height ; 
    int length ; 
    int speed ; 
    int capacity ; 
    int CurrentNumRiders ; 
    bool RideInProgress ; 

    public:
    //default constructor
    RollerCoaster() : name("roller coaster") , height(500) , length(2000) , capacity(20) , RideInProgress(false) {}

    //parameterized
    RollerCoaster(int Height , int Length , int Speed , int Capacity , int currentnumriders)
    {
        if(Capacity%2 !=0 || Capacity%3 != 0)
        {
            //rounding it off to nearest multiple of two
            Capacity = ((Capacity + 1) / 2) * 2 ; 
        }
        height = Height ;
        length = Length ; 
        speed = Speed ; 
        capacity = Capacity ; 
        CurrentNumRiders = currentnumriders ; 
    }

    
    void setName(string Name)
    {
        name = Name ; 
    }
    string getName()
    {
        return name ; 
    }
    
    void setHeight(int Height)
    {
        height = Height ;
    }
    int getHeight()
    {
        return height ; 
    }
    
    void setLength(int Length)
    {
        length = Length ; 
    }
    int getLength()
    {
        return length ; 
    }
    void setSpeed(float Speed)
    {
        speed = Speed ; 
    }
    int getSpeed()
    {
        return speed ; 
    }
    void setCapacity(int Capacity)
    {
        if(Capacity%2 !=0 || Capacity%3 != 0)
        {
            //rounding it off to nearest multiple of two
            Capacity = ((Capacity + 1) / 2) * 2 ; 
        }
        capacity = Capacity ;  
    }
    int getCapacity()
    {
        return capacity ; 
    }
    void setCurrentNumRiders(int currentNumRiders)
    {
        CurrentNumRiders = currentNumRiders ;
    }
    int getCurrentNumRiders()
    {
        return CurrentNumRiders ; 
    }
    void setRideInProgress(bool rideInProgress)
    {
        RideInProgress = rideInProgress ; 
    }
    bool isRideInProgress()
    {
        return RideInProgress ; 
    }

    public:

    //function to load the ride
    int load(int riders)
    {
        if(!RideInProgress)
        {
            if(capacity < riders)
            {
                riders = riders - capacity ; 
                return riders ; 
            }
            else
            {
                CurrentNumRiders = riders ; 
                return 0 ; 
            }
        }
    }

    //function to start the ride
    int start(int riders)
    {
        if(RideInProgress)
        {
            return -1 ; 
        }
        else
        {
            if(riders==capacity)
            {
                return 1 ;
            }
            else
            {
                return (capacity-riders) ;
            }
        }
    }

    //function to stop the ride
    void stop()
    {
        RideInProgress = false ; 
    }

    //function to unload the ride
    void unload()
    {
        if(!RideInProgress)
        {
            CurrentNumRiders = 0 ;
        }
    }

    //function to accelerate the roller coaster
    void accelerate()
    {
        int num , rollno = 0575;
        num = rollno % 10 ; //to get last digit
        if(num !=0)
        {
            speed = speed + num ; 
        }
        else
        {
            while(num ==0 && rollno != 0)
            {
                rollno = rollno /10 ; 
                num = rollno % 10 ; 
            }
            speed = speed + num ; 
        }
    }

    //function to apply brakes
    void brake()
    {
        int rollno = 0575 ; 
        int num = rollno ; 
        
        //finding first non zero digit
        while(num > 9)
        {
            num = num /10 ;
        }

        if(num !=0)
        {
            speed = speed - num ; 
        }

    }

};

int main()
{
    cout << "Name : Muhammad Anas Siddiqui" << endl ; 
    cout << "ID: 23k-0575" << endl ;
    
    //create objects using constructor
    RollerCoaster rollerCoaster ;
    RollerCoaster rollerCoaster1(600 , 2500 , 50 , 25 , 0) ;

    //Demonstrate loading passengers
    int excessPassengers = rollerCoaster1.load(15); 
    if (excessPassengers > 0)
    {
        cout << "Could not seat " << excessPassengers << " passengers in rollerCoaster1." << endl;
    } 
    else 
    {
        cout << "All passengers successfully seated in rollerCoaster1." << endl;
    }

    // Demonstrate starting the ride
    int emptySeats = rollerCoaster1.start(10);
    if (emptySeats == 1 || emptySeats == -1) 
    {
        cout << "Ride started with full capacity in rollerCoaster1." << endl;
    } 
    else 
    {
        cout << "Ride could not start. There are " << emptySeats << " empty seats." << endl;
    }

    // Demonstrate accelerating and braking
    rollerCoaster1.accelerate(); 
    cout << "Speed after accelerating: " << rollerCoaster1.getSpeed() << endl;

    rollerCoaster1.brake();
    cout << "Speed after braking: " << rollerCoaster1.getSpeed() << endl;

    // Demonstrate stopping the ride
    rollerCoaster1.stop(); 
    cout << "Ride stopped." << endl;

    // Demonstrate unloading passengers
    rollerCoaster1.unload(); 
    cout << "Passengers unloaded." << endl;

    return 0;
}