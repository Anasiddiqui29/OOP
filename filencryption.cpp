#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std ;

class FileEncryption
{
    string line ; 

    public:
    void input() //taking input from the user
    {
        cout << "Enter the text: " ;
        getline(cin , line) ; 
    }

    void inputFile()
    {
        ofstream fp ; 
        fp.open("input.txt" , ios::out) ;
        if(!fp)
        {
            cerr << "Failed to open file" << endl ; 
        }
        else
        {
            fp << line ; 
            fp.close() ; 
        }
    }

    void encryption()
    {
        char alphabet[26] , ch = 'A' ;
        for(int i=0 ; i<26 ; i++)
        {
            alphabet[i] = ch ; 
            ch++ ; 
        }
        int arr[26] ;
        for(int i=0 ; i<26 ; i++)
        {
            arr[i] =i+1 ; 
        }
        string s ; 
        fflush(stdin) ;

        ifstream fp1("input.txt" , ios::in) ; //opening file in read mode
        ofstream fp2("k230575.txt" , ios::out) ; //opening file in writing mode

        if(!fp1 || !fp2)
        {
            cerr << "Failed to open file" << endl ; 
        }
        else
        {
            while(!fp1.eof())
            {
                fp1>>s ; //storing the data from file into 's'
                stringstream ss ; //using stringstream lib to convert string into integer
                ss << s ; //storing converted string into integer in ss
                int num ; 
                ss >> num ; 
                cout << num ; 
                if(num<1 || num>26)
                {
                    fp2 << 'Z'  ; 
                } 
                for(int i = 0 ; i<26 ; i++)
                {
                    if(num==arr[i])
                    {
                        fp2 << alphabet[i] ;
                    }
                }
            }
        }
        fp1.close() ;
        fp2.close() ; 
    }
} ;

int main()
{
    FileEncryption obj ;
    obj.input() ; 
    obj.inputFile() ; 
    obj.encryption() ; 

}