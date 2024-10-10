#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

class Pet
{
    public:

    string healthStatus ;
    int hungerLevel ; 
    int happinessLevel ; 
    string specialSkills[5] ;  

    //constructor
    Pet(const char* health = "Healthy", int hunger = 0) : healthStatus(health), hungerLevel(hunger), happinessLevel(5) {}
    
    void displayPetDetails()
    {
        cout << "Pet details" << endl ; 
        cout << "Health Status: " << healthStatus << endl ; 
        cout << "Hunger level: " << hungerLevel << endl ; 
        cout << "Happiness Level : " << happinessLevel << endl ; 
        cout << "Special Skills: " <<endl ; 
        for(int i=0 ; i<5 ; i++)
        {
            cout << "Skill " << i+1 << specialSkills[i] << endl ; 
        }
    }

    void updateHappiness(int hunger)
    {
        happinessLevel = 10 ; 
        if(hunger==0)
        {
            happinessLevel = 10 ; 
        }
        if(hunger==1)
        {
            happinessLevel = 9 ; 
        }
        if(hunger==2)
        {
            happinessLevel = 8 ;
        }
        if(hunger==3)
        {
            happinessLevel = 7 ;
        }
        if(hunger==4)
        {
            happinessLevel = 6 ;
        }
        if(hunger==5)
        {
            happinessLevel = 5 ;
        }
        if(hunger==6)
        {
            happinessLevel = 4 ;
        }
        if(hunger==7)
        {
            happinessLevel = 3 ;
        }
        if(hunger==8)
        {
            happinessLevel = 2 ;
        }
        if(hunger==9)
        {
            happinessLevel = 1 ;
        }
        if(hunger==10)
        {
            happinessLevel = 0 ;
        } 
    }

    void updateHealth()
    {
        if(hungerLevel <5)
        {
            healthStatus = "Happy" ;
        }
        else
        {
            if(hungerLevel >=5)
            {
                healthStatus = "Happy" ; 
            }
        }
    }

    void updateHunger(bool isFed)
    {
        if(isFed==1)
        {
            if(hungerLevel>0)
            {
                hungerLevel-- ; 
            }
        }
        else
        {
            hungerLevel++ ; 
        }
    }
} ;

class Adopter
{
    public:

    string adopterName ;
    int adopterMobileNum ;
    Pet adoptedPetRecords[5] ; 

    //initialize
    Adopter(string name , int number) : adopterName(name) , adopterMobileNum(number){} ;
    
    void adoptPet(Pet pet)
    {
        string pname;  
        cout << "Enter the name of the pet: "<< endl ;
        cin >> pname ; 

        int hunger ; 
        cout << "Enter the hunger level: "<< endl ; 
        cin >> hunger ;

        Pet newpet("Healthy" , hunger) ;
        adoptedPetRecords[0] = newpet ; 
    }

    void returnPet()
    {
        string r_name ; 
        cout << "Enter the name of the pet: "<< endl ;
        cin >> r_name ; 

        adoptedPetRecords[0].healthStatus = "" ;
        adoptedPetRecords[0].hungerLevel = 0 ;

    }

    void displayAdoptedPets()
    {
        cout << "Adopted pets details\n" << endl ;
        for(int i=0 ; i<5 ; i++)
        {
            if (!adoptedPetRecords[i].healthStatus.empty()) 
            {
                cout << "Pet " << i + 1 << ":" << endl;
                adoptedPetRecords[i].displayPetDetails();
                break ; 
            }
        }

    }

} ;

int main()
{
    cout << "Name : Muhammad Anas Siddiqui" << endl ; 
    cout << "ID: 23k-0575" << endl ; 

    Pet pet("Happiness" , 3) ;

    //Display pet details
    cout << "Pet details" << endl ; 
    pet.displayPetDetails() ; 

    pet.updateHappiness(3) ;
    pet.updateHealth() ;   

    //display updated pet details
    cout << "Updated pet details" << endl ;
    pet.displayPetDetails() ;

    //Adopt class
    Adopter adopter("John cena" , 23334433434) ; 

    adopter.adoptPet(pet) ;

    //display adopted pets by adopter
    cout << "Adopter's Adopted Pets: " << endl ;
    adopter.displayAdoptedPets() ;

}