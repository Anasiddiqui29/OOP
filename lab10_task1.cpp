#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std ;

class Complex
{
    double realValue ;
    double imaginaryValue ;
    
    public:
    Complex(double realVaule , double imaginaryValue)
    {
        this->imaginaryValue = imaginaryValue ; 
        this->realValue = realValue ; 
    }
    Complex()
    {
        imaginaryValue = 0 ; 
        realValue = 0 ; 
    }

    //Overloaded opertor << for output
    friend ostream &operator<< (ostream &os , const Complex &c) ;

    //Overloaded opertaor >> for input
    friend istream &operator>>(istream &is , Complex c);

    //Addition operator
    Complex operator+(const Complex &c) const
    {
        Complex temp(2.34 , 5.34);
        temp.realValue = realValue + c.realValue ;
        temp.imaginaryValue = imaginaryValue + c.imaginaryValue ; 
        return temp ; 
    }

    Complex operator-()const
    {
        Complex temp(3.45 , 7.92) ;
        temp.realValue = -realValue ; 
        temp.imaginaryValue = -imaginaryValue ; 
        return temp ; 
    } 
    
} ;

ostream &operator<<(ostream &os , const Complex &c)
{
    if(c.imaginaryValue == 0)
    {
        cout << c.realValue ; 
    }
    if(c.imaginaryValue < 0)
    {
        cout << c.realValue << " - " << c.imaginaryValue << "i" << endl ; 
    }
    if(c.imaginaryValue > 0)
    {
        cout << c.realValue << " + " << c.imaginaryValue << "i" << endl ; 
    }
    return os ; 
}

istream &operator>>(istream &is , Complex c)
{
    char operand ; 
    is >> c.realValue >> operand >> c.imaginaryValue ;    
    return is ; 
}

