#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>

#define pi 3.14159265358979323846
//Running  fine
using namespace std ;

//abstract class
class Drone
{
    protected:
    float latitude ; //position of drone
    float longitude ; //position of drone
    float altitude ; 
    float speed ; 

    public:
    Drone(float latitude , float longitude , float altitude , float speed)
    {
        this->latitude = latitude ; 
        this->longitude = longitude ; 
        this->altitude = altitude ;
        this->speed = speed ; 
    }

    void adjustAltitude(float meters)
    {
        altitude = meters ; 
    }

    void setSpeed(float Speed)
    {
        speed = Speed ; 
    }

    //pure virtual functions
    virtual void takeoff() = 0 ; 
    virtual void land() = 0 ; 

    virtual void navigateTo(float Lat , float Long , float alt)
    {
        latitude = Lat ; 
        longitude = Long ; 
        altitude = alt ; 
    }
} ;

class ReconDrone : public Drone
{
    int cameraResolution ; 
    int maxFlightTime ; 

    public:
    ReconDrone(float Lat , float Long , float a , float s , int cameraResolution , int maxFlightTime) 
    : Drone(Lat , Long , a , s)
    {
        this->cameraResolution = cameraResolution ; 
        this->maxFlightTime = maxFlightTime ; 
    }

    void navigateTo(float L , float Lo , float Alt) override
    {
        try
        {
            if(Alt > 100) //assuming if altitude is greater than 100 than GPS signal is lost
            {
                throw runtime_error("GPS signal is lost. ") ;
            }
            else
            {
                //distance between current position and target position
                double distance ; 
                distance = sin(latitude) * sin(L) + cos(latitude) * cos(L) * cos(longitude - Lo);
                distance = acos(distance);
                distance = (6371 * pi * distance) / 180;

                cout << "Distance between current position and target position: " << distance <<"m" << endl ;

                //calculating time
                float time ; 
                time = altitude/speed ; 

                cout << "Time required to reach the destination: " << time <<"s" << endl ;
            }
        }
        catch(const exception &e)
        {
            cout << "Error during navigation. " << e.what() << endl ; 
        }
    }

    void scanArea(float radius)
    {
        try
        {
            if(radius >200) //assuming that radius is greater than 200 so drone is unable to scan the area
            {
                throw runtime_error("Drone is unable to scan. ") ;
            }
            else
            {
                cout << "There are 5 objects within this " << radius <<"m radius" << endl ; 

                cout << "Their co-ordinates are as follows: " << endl ; 
                cout << "Object 1 : Tree \n longitude: 17.900 \n latitude: 9.867" << endl ; 
                cout << "Object 2 : Rock \n longitude: 20.305 \n latitude: 17.560" << endl ;
                cout << "Object 3 : See Saw \n longitude: 5.930 \n latitude: 14.700" << endl ;
                cout << "Object 4 : Car \n longitude: 11.950 \n latitude: 22.670" << endl ;
                cout << "Object 5 : Bike \n longitude: 15.120 \n latitude: 16.340" << endl ;

            }   
        }
        catch(const exception &e)
        {
            cout << "Error during scanning. " << e.what() << endl ; 
        }        
    }

    void takeoff() override
    {
        cout << "Drone has taken off" << endl ; 
    }

    void land() override
    {
        cout << "Drone has landed successfully" << endl ; 
    }


} ;

int main()
{
    cout << "Muhammad Anas Siddiqui" << endl ; 
    cout << "23k-0575" << endl ; 
    ReconDrone drone1(17.45674 , 4.56473 , 90.74 , 56.12 , 1080 , 60) ;

    drone1.takeoff() ;

    cout << "--------------------------------------" << endl ; 

    drone1.navigateTo(16.87451 , 7.98123 , 100) ;
    drone1.scanArea(90) ;

    cout << "--------------------------------------" << endl ; 

    drone1.land() ;
    
}