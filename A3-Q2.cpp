#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std ;

template <typename T>
class Pet
{
    protected:
    T name ; 
    T age ; 

    public:
    //Parametrized Constructor
    Pet(T name , T age)
    {
        this->name = name ; 
        this->age = age ; 
    }

    //Pure Virtual function
    virtual string makesound()=0 ;
} ;

template <typename T>
class Cat : public Pet <T>
{
    public:
    //constructor
    Cat(T n , T a) : Pet<T>(n ,a) {}

    string makesound() override
    {
        return "Meow Meow" ; 
    }

    T getname()
    {
        return this->name ;
    }

    T getage()
    {
        return this->age ; 
    }


}  ;

template <typename T>
class Dog : public Pet <T>
{
    public:
    //constructor
    Dog(T n , T a) : Pet<T>(n ,a) {}

    string makesound() override
    {
        return "Woof Woof" ; 
    }

    T getname()
    {
        return this->name ;
    }

    T getage()
    {
        return this->age ; 
    }

}  ;

template <typename T>
class Bird : public Pet <T>
{
    public:
    //constructor
    Bird(T n , T a) : Pet<T>(n ,a) {}

    string makesound() override
    {
        return "Chirp Chirp" ; 
    }

    T getname()
    {
        return this->name ;
    }

    T getage()
    {
        return this->age ; 
    }

}  ;

int main()
{
    cout << "Muhammad Anas Siddiqui" << endl ; 
    cout << "23k-0575" << endl ; 
    Cat <string> cat1("Bano" , "12 years old") ;
    //Displaying details of the cat
    cout << "Name of the Cat: " << cat1.getname() << endl ; 
    cout << "Age of the cat: " << cat1.getage() << endl ; 
    cout << "Sound: " << cat1.makesound() << endl ;  

    cout << "-----------------------------------------" << endl ; 

    Dog <string> dog1("Tom" ,"5 years old") ;
    //displaying details of the dog
    cout << "Name of the Dog: " << dog1.getname() << endl ; 
    cout << "Age of the dog: " << dog1.getage() << endl ; 
    cout << "Sound: " << dog1.makesound() << endl ; 

    cout << "-----------------------------------------" << endl ; 

    Bird <string> bird1("Koyal" , "2 years old") ;
    //displaying details of the bird
    cout << "Name of the bird: " << bird1.getname() << endl ; 
    cout << "Age of the bird: " << bird1.getage() << endl ; 
    cout << "Sound of the bird: " << bird1.makesound() << endl; 

}

