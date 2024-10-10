#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std ;

//all good

template <typename T>  
class Matrix
{
    protected:
    int row ; 
    int column ;
    T ** arr;

    public:
    Matrix(int row ,int column)
    {
        this->row = row ; 
        this->column = column ;
        arr = new T*[row];
        for (int i = 0; i < row; ++i) 
        {
            arr[i] = new T[column];
        }
    }

    ~Matrix()
    {
        if(arr != nullptr)
        {
            for(int i=0 ; i<row ; i++)
            {
                delete arr[i] ;
            }   
        }
        delete arr ;
    }

    Matrix() : arr(nullptr)
    {
        row = 0 ; 
        column = 0 ; 
    }

    //getters and setters
    void setrow(int rows)
    {
        row = rows ; 
    }
    void setcolumn(int columns)
    {
        column = columns ; 
    }
    int getrow()
    {
        return row ; 
    }
    int getcolumn()
    {
        return column ; 
    }

    int getelement(int i , int j)
    {
        return arr[i][j] ; 
    }

    void setelement(int rr , int cc , T a)
    {
        arr[rr][cc] = a ;
    }

    //copy constructor+
    Matrix(const Matrix<T>& other) : row(other.row), column(other.column) {
        arr = new T *[row];
        for (int i = 0; i < row; ++i) {
            arr[i] = new T[column];
            for (int j = 0; j < column; ++j) {
                arr[i][j] = other.arr[i][j];
            }
        }
    }

    //operators overloading
    //+ operator
    Matrix<T> operator + (Matrix <T> mat1)
    {
        Matrix <T> temp(row , column) ;
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<column ; j++)
            {
                temp.arr[i][j] = mat1.arr[i][j] + arr[i][j] ;
            }
        }

        return temp ;
    }

    //- operator
    Matrix<T> operator - (Matrix <T> mat1)
    {
        Matrix <T> temp(row , column) ;
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<column ; j++)
            {
                temp.arr[i][j] = mat1.arr[i][j] - arr[i][j] ;
            }
        }

        return temp ;
    }

    Matrix<T> operator * (Matrix <T> mat1)
    {
        Matrix <T> temp(row, mat1.column);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < mat1.column; j++)
            {
                temp.arr[i][j] = 0;
                for (int k = 0; k < column; k++)
                {
                    temp.arr[i][j] += arr[i][k] * mat1.arr[k][j];
                }
            }
        }

        return temp;
    }

    virtual void display() 
    {
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<column ; j++)
            {
                cout << arr[i][j] << " " ;
            }
            cout << "\n" << endl ; 
        }
    }

} ;

class IntMatrix : public Matrix<int>
{
    public:
    IntMatrix(int r , int c) : Matrix <int> (r , c) {}

    IntMatrix(const Matrix<int>& m) : Matrix<int>(m) {}

    void display() override
    {
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<column ; j++)
            {
                cout << arr[i][j] << " " ;
            }
            cout << "\n" << endl ; 
        }
    }
} ;

class DoubleMatrix : public Matrix<double>
{
    public:
    DoubleMatrix(int r , int c) : Matrix <double> (r , c) {}

    DoubleMatrix(const Matrix<double>& m) : Matrix<double>(m) {}

    void display() override
    {
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<column ; j++)
            {
                cout << arr[i][j] << " " ;
            }
            cout << "\n" << endl ; 
        }
    }
} ;

int main()
{ 
    cout << "Muhammad Anas Siddiqui" << endl ; 
    cout << "23k-0575" << endl ; 
    IntMatrix matt1(2,2) ;
    matt1.setelement(0,0 , 2) ;
    matt1.setelement(0 , 1 , 1) ;
    matt1.setelement(1,0, 3) ;
    matt1.setelement(1,1 , 4) ;

    IntMatrix matt2(2,2) ;
    matt2.setelement(0,0 , 5) ;
    matt2.setelement(0 , 1 , 6) ;
    matt2.setelement(1,0, 7) ;
    matt2.setelement(1, 1 , 8) ;

    cout << "Integer" << endl ; 

    IntMatrix intmatsum = matt2 + matt1 ;

    intmatsum.display() ; 
    cout << "------------------------------------------" << endl ;

    IntMatrix intmatmul = matt2 * matt1 ; 
    intmatmul.display() ;

    cout<< "--------------------------------------------" << endl ; 

    IntMatrix intmatsub = matt2 - matt1 ; 
    intmatsub.display() ; 

    cout << "Double type" << endl ; 

    DoubleMatrix matt3(2,2) ;
    matt3.setelement(0,0 , 2) ;
    matt3.setelement(0 , 1 , 1) ;
    matt3.setelement(1,0, 3) ;
    matt3.setelement(1,1 , 4) ;

    DoubleMatrix matt4(2,2) ;
    matt4.setelement(0,0 , 5.0) ;
    matt4.setelement(0 , 1 , 6.0) ;
    matt4.setelement(1,0, 7.0) ;
    matt4.setelement(1, 1 , 8.0) ;


    DoubleMatrix doumatsum = matt3 + matt4 ;

    doumatsum.display() ; 
    cout << "------------------------------------------" << endl ;

    DoubleMatrix doumatmul = matt3*matt4 ; 
    doumatmul.display() ;

    cout<< "--------------------------------------------" << endl ; 

    DoubleMatrix doumatsub = matt4 - matt3 ; 
    doumatsub.display() ; 

    
}

