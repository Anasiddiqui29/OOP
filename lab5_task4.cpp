#include <iostream>
#include <cmath>

using namespace std ;

class Course
{
    string code ; 
    string name ; 
    int credit_hours ; 

    public:
    Course(string code, string name, int credit_hours)
    : code(code), name(name), credit_hours(credit_hours) {}

    int gethrs()
    {
        return credit_hours ;
    }
    string getcode()
    {
        return code ; 
    }
    string getname()
    {
        return name ; 
    }

} ;

class Student
{
    string id ; 
    string name ; 
    Course courses[2] ; 
    int num ;

    public:

    Student(string id , string name , Course &c1 ,Course &c2 )
    : courses{c1 , c2} , num(2)
    {
        this->id = id ; 
        this->name = name ; 
    }

    void enroll(Course &course1)
    {
        if (num < 2) 
        {
            courses[num++] = course1;
        } 
        else 
        {
            cout << "Maximum course enrollment reached for student " << id << endl;
        }
    }

    void drop(Course &course2)
    {
        bool found = false;
        for (int i = 0; i < num; ++i) 
        {
            if (courses[i].getcode() == course2.getcode()) 
            {
                found = true;
                for (int j = i; j < num - 1; ++j) 
                {
                    courses[j] = courses[j + 1];
                }
                // Decrement the number of enrolled courses
                --num;
                break; 
            }
        }
        if (!found) 
        {
            cout << "Course " << course2.getcode() << " not found in the student's enrolled courses" << endl;
        }    
    }

    int getTotalCreditHours()
    {
        int total ; 
        for(int i=0 ; i<2 ; i++)
        {
            total = total + courses[i].gethrs() ;
        }
        return total ; 
    }

    void printEnrolledCourses()
    {
        for(int i=0 ; i<2 ; i++)
        {
            cout << "Course Code: " << courses[i].getcode() << endl ;
            cout << "Course name: " << courses[i].getname() << endl ; 
            cout << "Course credit hour: " << courses[i].gethrs() << endl ;
        }

        cout << "Total credit hours: " << getTotalCreditHours() << endl ;
    }
} ;

int main()
{
    

    Course couse1("CS101" , "Introduction to computer science", 4) ;
    Course couse2("MATH101", "Calculus I", 4);

    Student std1("2453" , "Harsh" , couse1 , couse2) ;

    std1.enroll(couse1) ;
    std1.enroll(couse2) ;

    cout << "Details after enrolling" << endl ;
    std1.printEnrolledCourses() ;

    std1.drop(couse1) ;
    cout << "Details after dropping course(s)" << endl ;
    std1.printEnrolledCourses() ;

}