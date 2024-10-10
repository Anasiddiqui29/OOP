#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
//#include <bcrypt/BCrypt.hpp>

using namespace std ; 

class User
{
    string username ; 
    string email ; 
    string Password ; 

    public: 
    User(string Username , string email , string password)
    {
        this->username = username ; 
        this->email = email ; 
        Password = BCrypt::generateHash(password); //encrypting password
    }

    //Verification
    void verification(string Username , string Passsword)
    {
        if(Username == username && Passsword == Password)
        {
            cout << "Login successful" << endl ;
        }
        else
        {
            cout << "Login failed" << endl ; 
        }
    }

} ;

class Post
{
    string content ; 

    public:
    Post(string content)
    {
        this->content = content;
    }

    string getcontent()
    {
        return content ; 
    }


} ;


class RegularUser : public User
{
    int n_post ;
    const int MAX_FEED_SIZE = 10 ;
    Post ** feed; 

    public:
    RegularUser(string username, string email, string password ,int n_post) : User(username , email , password)
    {
        this->n_post = n_post ;
        feed = new Post*[MAX_FEED_SIZE] () ;  //initializing with null ptr
    }

    void limit(int number) //number of posts
    {
        if(number >5)
        {
            cout << "Limit has been reached. You cannot post more for now" << endl;
        }
        else
        {
            cout << number << " posts has been uploaded" << endl ;
        }

        n_post = number ; 
    }

    void addtoFeed(string content)
    {
        if(n_post < MAX_FEED_SIZE)
        {
            feed[n_post] = new Post(content);
            ++n_post ;
        }
        else
        {
            cout << "Feed capacity has been reached" << endl ; 
        }
    }

    void viewfeed()
    {
        for(int i=0 ; i<n_post ; i++)
        {
            cout << "Post " << i+1 << ": "<< feed[i]->getcontent() << endl ; 
        }
    }

    ~RegularUser() 
    {
        // Deallocate memory for each Post object
        for (size_t i = 0; i < n_post ; ++i)
        {
            delete feed[i];
        }
        delete[] feed;
    }

} ;

class BusinessUser : public User
{
    int max_posts = 10 ;

    public:
    BusinessUser(string username, string email, string password )
    : User(username, email, password) {}

    void promotePost(Post &post)
    {
        cout << "Post promoted: " << post.getcontent() << endl ; 
    }

    void promotionlimit(int npost)
    {
        if(npost >=max_posts)
        {
            cout << "You have reached the limit to promote your post" << endl ;
        }
    }




} ;