#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std ;

class Poly
{
    double a ;
    double b ;
    double c ; 

    public:

    //Default constructor
    Poly() : a(0) , b(0) , c(0) {}

    //Parameterized Constructor
    Poly(double a , double b , double c)
    {
        this->a = a ; 
        this->b = b ; 
        this->c = c ;
    }

    //Overloading addition operator
    Poly operator+(const Poly &eq) const
    {
        Poly temp ;
        temp.a = a + eq.a ;
        temp.b = b + eq.b ;
        temp.c = c + eq.c ; 

        return temp ; 
    }

    friend ostream &operator<<(ostream &os , const Poly &eq1) ;


} ;

ostream &operator<<(ostream &os , const Poly &eq1)
{
        //a=0
        if(eq1.a==0 && eq1.b >0 && eq1.c >0) 
        {
            os << eq1.b <<"x +" << eq1.c << endl ;  
        }
        if(eq1.a==0 && eq1.b <0 && eq1.c >0)
        {
            os << "-" <<eq1.b << "x +" << eq1.c << endl ; 
        }
        if(eq1.a==0 && eq1.b >0 && eq1.c <0)
        {
            os << eq1.b <<"x -" << eq1.c << endl ;
        }
        if(eq1.a==0 && eq1.b <0 && eq1.c <0)
        {
            os << "-" <<eq1.b <<"x -" << eq1.c << endl ;
        }
        //b=0
        if(eq1.b==0 && eq1.a >0 && eq1.c >0) 
        {
            os << eq1.a <<"x^2 +" << eq1.c << endl ;  
        }
        if(eq1.b==0 && eq1.a <0 && eq1.c >0)
        {
            os << "-" <<eq1.a << "x^2 +" << eq1.c << endl ; 
        }
        if(eq1.b==0 && eq1.a >0 && eq1.c <0)
        {
            os << eq1.a <<"x^2 -" << eq1.c << endl ;
        }
        if(eq1.b==0 && eq1.a <0 && eq1.c <0)
        {
            os << "-" <<eq1.b <<"x^2 -" << eq1.c << endl ;
        }

        //c=0
        if(eq1.c==0 && eq1.b >0 && eq1.a >0) 
        {
            os << eq1.a <<"x^2 + " << eq1.b << "x" << endl ;  
        }
        if(eq1.c==0 && eq1.b <0 && eq1.a >0)
        {
            os << eq1.a << "x^2 -" << eq1.b << endl ; 
        }
        if(eq1.c==0 && eq1.b >0 && eq1.a <0)
        {
            os << "-" << eq1.a <<"x^2 + " << eq1.b << endl ;
        }
        if(eq1.c==0 && eq1.b <0 && eq1.a <0)
        {
            os << "-" <<eq1.b <<"x^2 -" << eq1.b << endl ;
        }

}

int main()
{
    Poly poly1(3, 4, -2); 
    Poly poly2(-4, 0, 10); 

    // Printing polynomials
    cout << "q1: " << poly1 << endl;
    cout << "q2: " << poly2 << endl;

    Poly sum = poly1 + poly2;

    cout << "Sum of q1 and q2: " << sum << endl;

}