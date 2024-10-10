#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std ;

//Abstract class
class Artist
{
    protected:
    string name ; 

    public:
    Artist(string name)
    {
        this->name = name ; 
    }

    //Pure virtual function
    virtual string getType()=0 ;

} ;

class Musician : public Artist
{
    public:
    Musician(string n) : Artist(n) {}

    string getType() override
    {
        return "Musician" ; 
    }

} ;

class Band : public Artist
{
    Musician mus;

    public:
    Band(string n , string mus_name) : Artist(n) , mus(mus_name) {}

    string getType() override
    {
        return "Band" ; 
    } 

} ;

class Song 
{
    Artist *performer ; //cannot create the object of the abstract class directly so need to use pointer
    Artist *writer ; 

    public:
    //Constructor
    Song(Artist *performer , Artist *writer) :performer(performer) , writer(writer){}
    Song() ; 

    //getter and setter
    void setperformer(Artist *performer)
    {
        this->performer = performer ; 
    }
    Artist *getperformer() //cannot return obj directly so pointer is needed
    {
        return performer ; 
    }

    void setwriter(Artist *writer)
    {
        this->writer = writer ; 
    }
    Artist *getwriter()
    {
        return writer ; 
    }
} ;

class Track
{
    int duration ; 
    int birate ; 
    Song *songs ; //dynamically allocating memory
    int numSongs ;  

    public:
    Track() ; 
    Track(int duration , int birate,int numSongs)
    {
        this->duration = duration ; 
        this->birate = birate ;        
        this->numSongs = numSongs ;  

        songs = new Song[numSongs] ;
    }
    //deallocating memory
    ~Track()
    {
        delete[] songs ;
    }

    void display()
    {
        cout << "Duration of each song: " << duration<< endl ; 
        cout << "Birate for each song in the track: " << birate << endl ; 
    }

} ;

class Album 
{
    Track *tracks ; 
    int numTracks ; 
    int maxTracks ; 

    public:
    Album(int numTracks , int maxTracks)
    {
        this->numTracks = numTracks ; 
        this->maxTracks = maxTracks ; 

        tracks = new Track[numTracks] ; 
    }
    ~Album()
    {
        delete[] tracks ; 
    }

    bool addTrack(Track &track)
    {
        if(numTracks<maxTracks)
        {
            tracks[numTracks] = track ; 
            numTracks++ ;
            cout << "Track added successfully" << endl ; 
            return true ;  
        }
        else
        {
            cout << "Not enough space" << endl ; 
            return false ; 
        }
    }

    Track *getTracks()
    {
        return tracks ; 
    }


};