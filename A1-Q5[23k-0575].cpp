#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

class Restaurant
{
    public:

    string restaurant_name ; 
    string location ; 
    string menu_list[15] ;
    int price_list[15] ;
    string valid_coupon_list[10] ;
    static int coupons_redeemed_count ;

    void display_menu()
    {
        cout << "Menu List\n" << endl ; 
        for(int i = 0 ; i<15 ; i++)
        {
            cout << "Menu " << i+1 << ": " << menu_list[i] << endl ; 
        }
    }

    int generate_bill(int ordered_items[] , int quantities[] , int items) 
    {
        int bill ; 
        for(int i=0 ; i<15 ; i++)
        {
            if(i == ordered_items[i] - 1)
            {
                bill = bill + (price_list[i] * quantities[i]) ; 
            }
        }
    }

    void apply_discount()
    {

    }

};

class BOGOCoupon
{
    public: 

    string coupon_code ; 
    int valid_form ; 
    int valid_until ; 
    string restaurant_code ; 

    void isValid()
    {
        if(valid_until > valid_form)
        {
            cout <<"Your coupon is valid" << endl ; 
        }
        else
        {
            if(valid_until == valid_form)
            {
                cout << "Hurry up! It's your last day" << endl ; 
            }
            else
            {
                cout << "Coupon not valid" << endl ; 
            }
        }
    }

    
} ;

class User
{
    string name ; 
    int age ; 
    int mobile_num ; 
    string redeemed_coupon_list[5] ;

    public:
    string coupon_list[5] ;

    void setname(string Name)
    {
        name = Name ;
    }
    string getname()
    {
        return name ; 
    }

    void setage(int Age)
    {
        age = Age ; 
    }
    int getage()
    {
        return age ; 
    }

    void setnum(int Number)
    {
        mobile_num = Number ;
    }
    int getmob()
    {
        return mobile_num ;
    }

    void Accumulate_coupon(string couponcode)
    {
        for(int i=0 ; i<5 ; i++)
        {
            if(coupon_list[i] == "\0")
            {
                coupon_list[i] = couponcode ;
                break ; 
            }
        }
         
    }

    bool Has_valid_coupon()
    {
        Restaurant res1 ; 
        for(int i=0 ; i<5 ; i++)
        {
            if(res1.valid_coupon_list[i] == coupon_list[i] && coupon_list[i] != redeemed_coupon_list[i]) //validation for specific restaurant and unredeemed
            {
                cout << "Coupon is valid" << endl ; 
                return true ;
            }
            else
            {
                return false ; 
            }
        }
    }

    void redeem_coupon(string coupon_code)
    {
        for(int i=0 ; i<5 ; i++)
        {
            if(coupon_list[i] == coupon_code)
            {
                redeemed_coupon_list[i] = coupon_code ; 
                coupon_list[i] = " " ; //Reset the coupon code in coupon list
                cout << "Coupon "<< coupon_code << " has been redeemed successfully" << endl ; 
                break ; 
            }
            cout << "Coupon Code: " << coupon_code << " not found or already redeemed" << endl ;
            break ; 
        } 
    }

        
} ;

int main()
{
    cout << "Name : Muhammad Anas Siddiqui" << endl ; 
    cout << "ID: 23k-0575" << endl ;
    
    Restaurant food_haven ; 

    //Create Instance of Food Haven
    food_haven.restaurant_name ="Food Haven" ;
    food_haven.location = "Center City" ; 
    food_haven.menu_list[0] = "Sushi" ;
    food_haven.menu_list[1] = "Pad thai" ;
    food_haven.menu_list[2] = "Sushi" ;
    food_haven.price_list[0] = 10 ;
    food_haven.price_list[1] = 25 ;
    food_haven.price_list[2] = 15 ;

    Restaurant pixel_bites ; 

    //Create Instance of Pixel Bites
    pixel_bites.restaurant_name = "Pixel Bites" ;
    pixel_bites.location = "Cyber Street" ; 
    pixel_bites.menu_list[0] = "Binary Burger" ;
    pixel_bites.menu_list[1] = "Quantum Quinoa" ;
    pixel_bites.menu_list[2] = "Data Donuts" ;
    pixel_bites.price_list[0] = 13 ;
    pixel_bites.price_list[1] = 20 ;
    pixel_bites.price_list[2] = 25 ;

    //Display menus of both restaurant
    food_haven.display_menu() ;
    pixel_bites.display_menu() ;

    //BOGO coupons
    BOGOCoupon fh_coupons ; 
    fh_coupons.coupon_code = "FH-BOGO-1234" ;
    fh_coupons.valid_form = 10;
    fh_coupons.valid_until = 25 ; 
    fh_coupons.restaurant_code = "FH" ;   
    
    BOGOCoupon pb_coupons ;
    pb_coupons.coupon_code = "PB-BOGO-5678" ;
    pb_coupons.valid_form = 20 ;
    pb_coupons.valid_until = 29 ; 
    pb_coupons.restaurant_code = "PB" ;

    //Create instance of user
    User user ; 
    user.setname("Joe Tribiani") ;
    user.setage(27) ; 
    user.setnum(00022111112);
    user.coupon_list[0] = "FH-BOGO-1234" ; 

    user.redeem_coupon(fh_coupons.coupon_code) ;

    user.redeem_coupon(pb_coupons.coupon_code) ;
    
}