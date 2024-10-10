#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std ; 

class Person
{
    protected:
    string name ; 
    string gender ;
    string number ; 

    public:
    Person(string name , string gender , string number)
    {
        this->name = name ; 
        this->gender = gender ; 
        this->number = number ; 
    }
    
};

class Password : public Person
{
    string password ; 
    
    public:
    Password(string namee , string gen , string nuum) : Person(namee , gen , nuum) {}

    string characters = "#$%&’()*+,-./:;<=>?@[\]ˆ_{‘|}" ;

    void generatepass()
    {
        int length , size_char , t_num ; 
        cout << "What is the minimun length: " << endl ; 
        cin >> length ;
        cout << "How many special characters: "<< endl ; 
        cin >> size_char ;
        cout << "How many numbers: " << endl;
        cin >> t_num ;

        string naame , nnum , sschar ; 

        for(int i=0 ; i<(length)-size_char + t_num ; i++)
        {  
            int randomIndex_name = rand() % Person::name.length() ;
            naame += Person::name[randomIndex_name] ; 
        }
        for(int i =0 ; i<t_num ; i++)
        {
            int randomIndex_num = rand() % Person::number.length() ;
            nnum += Person::number[randomIndex_num] ;
        }
        for(int i=0 ; i<size_char ; i++)
        {
            int randomIndex_char = rand() % characters.length() ;
            sschar += characters[randomIndex_char] ; 
        }

        password = naame + nnum + sschar ;         


    }

    void display()
    {
        cout << "Your password is: " << password << endl ; 
    }

};

int main()
{
    Password pass("Anas" , "Male" , "03342208686");
    pass.generatepass() ; 
    pass.display() ;
}

