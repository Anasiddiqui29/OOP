#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std ;

class Image
{
    int width ;
    int height ;
    int * imagedata ; 

    public:
    Image(int width , int height , int * data)
    {
        this->width = width ; 
        this->height = height ; 

        imagedata = new int[width * height] ;

        for(int i=0 ; i<width*height ; i++)
        {
            imagedata[i] = data[i] ; 
        }

    }

    //copy constructor
    Image(const Image &image1)
    {
        width = image1.width ; 
        height = image1.height ;  
         
        imagedata = new int[width * height] ;

        for(int i=0 ; i<width*height ; i++)
        {
            imagedata[i] = image1.imagedata[i] ; 
        }
    }

    //destructor
    ~Image()
    {
        delete imagedata ; 
    }

    void display()
    {
        cout << "Width of the image: "<< width << endl ; 
        cout << "Height of the image: " << height << endl ; 
        cout << "------------------------------------" << endl ; 

        for(int i=0 ; i<width*height ; i++)
        {
            cout << imagedata[i] << " "   ;
        }
        
    }

    void updatedata()
    {
        for(int i=0 ; i<width*height ; i++)
        {
            if(imagedata[i] <=0)
            {
                imagedata[i]= rand() %255  ;
            }
        }

    }

} ;

int main()
{
    int imageeData[] = 
    {   
        5, 0, // Row 1
        8, 4, // Row 2
        2, 2 // Row 3
    } ;
    
    Image imagee1(2 , 3 , imageeData) ;

    //calling copy constructor
    Image imagee2(imagee1) ;

    //Display the original image
    imagee1.display() ;

    //Display the copy image
    imagee2.display() ; 

    //update data
    imagee1.updatedata() ;

    //display function
    imagee1.display() ; 

}