#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

//not running properly

class MATRIX 
{
    int rows ;
    int column ;
    int elements[2][2] ; 

    public:

    void setsize(int r , int c)
    {
        rows = r ;
        column = c ;
    }

    void setposition(int i , int j , int val)
    {
        if(i>0 && i<rows && j>0 && j<column)
        {
            elements[i][j] = val ;
        }
        else
        {
            cout << "Invalid position" << endl ; 
        }
    }
    
    void add(MATRIX mat2)
    {
        MATRIX result ; 

        result.setsize(2 , 2) ;

        for(int i=0 ; i<rows ; i++)
        {
            for(int j=0 ; j<column ; j++)
            {
                result.elements[i][j] = this->elements[i][j] + mat2.elements[i][j] ;
            }
        }

        //printing resultant matrix
        for(int i=0 ; i<rows ; i++)
        {
            for(int j=0 ; j<column ; j++)
            {
                cout << result.elements[i][j] << " " << endl ; 

            }
            cout << "\n"<< endl ; 
        }

    }

    void multiply(MATRIX mat2)
    {
        MATRIX result ; 

        result.setsize(2 , 2) ;

        for(int i=0 ; i<rows ; i++)
        {
            for(int j=0 ; j<column ; j++)
            {
                result.elements[i][j] = this->elements[i][j] * mat2.elements[i][j] ;
            }
        }

        //printing resultant matrix
        for(int i=0 ; i<rows ; i++)
        {
            for(int j=0 ; j<column ; j++)
            {
                cout << result.elements[i][j] << " " << endl ; 

            }
            cout << "\n"<< endl ; 
        }
    }
};

int main()
{
    MATRIX mat1 , mat2 ; 

    mat1.setsize(2,2) ;

    mat2.setsize(2,2) ;

    //setting elements of mat1
    mat1.setposition(0, 0, 1);
    mat1.setposition(0, 1, 2);
    mat1.setposition(1, 0, 3);
    mat1.setposition(1, 1, 4);

    //setting elements of mat2
    mat2.setposition(0, 0, 5);
    mat2.setposition(0, 1, 6);
    mat2.setposition(1, 0, 7);
    mat2.setposition(1, 1, 8);

    cout << "Resultant matrix for addition" <<endl ; 
    
    mat1.add(mat2) ;
    
    cout << "Resultant matrix for multiplication" << endl ; 

    mat1.multiply(mat2) ;
    

}
