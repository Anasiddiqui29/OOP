#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std ;

int approvedCourses[5] ; //global variable

//abstract class
class user
{
    protected:
    int userID ; 

    public:
    user(int userID)
    {
        this->userID = userID ; 
    }

    virtual void login()=0 ;

    virtual void logout()=0 ; 

} ;

class Course
{
    int course_code ; 
    string course_des ; 
    string section ; 

    public:
    Course(int course_code , string course_des , string section)
    {
        this->course_code = course_code ; 
        this->course_des = course_code ; 
        this->section = section ; 
    }

    int getCourseCode()
    {
        return course_code ; 
    }

} ;

class Student : public user
{
    string transcript ; 
    int number ; 

    public:
    Student(int id , string transcript , int number):user(id)
    {
        this->transcript = transcript ;
        this->number = number ; 
    }

    string getTranscript()
    {
        return transcript ; 
    }

    int getnumber()
    {
        return number ; 
    }

    int getStudentid()
    {
        return userID ;
    }

    void login() override
    {
        cout << "Student logged in successfully" << endl ; 
    }

    void logout()
    {
        cout << "Student logged out" << endl ; 
    }

    void addcourse(Course &course)
    {
        cout << "Course added successfully" << endl ; 
    }

};

class Advisor : public user
{
    int prerequisite ;

    public:
    Advisor(int prerequisite , int id) : user(id)
    {
        this->prerequisite = prerequisite ; 
    }

    void login()
    {
        cout << "Advisor logged in successfully" << endl ;
    }

    void logout()
    {
        cout << "Logged out" << endl ; 
    }

    void approveCourse(Student &student , Course &course)
    {
        //int approvedCourses[5] ;
        int count = 0 ;
        if(prerequisite==1) //condition is met
        {
            student.addcourse(course) ;
            approvedCourses[count] = course.getCourseCode() ; 
            count++ ; 
            cout << "Student ID: " << student.getStudentid() << " , Course approved: " << course.getCourseCode() << endl ;  
        }
        else
        {
            cout << "Course not approved" << endl ; 
        }
    }

} ;

class Registrar : public user
{

    public:
    
    void login()
    {
        cout << "Logged in successfully" << endl ; 
    }

    void logout()
    {
        cout << "Logged out successfully" << endl ; 
    }

    void generateBill()
    {
        cout << "Price for each course = 2000" << endl ; 
        int sum=0 ; 
        for(int i=0 ; i<5 ; i++)
        {
            if(approvedCourses[i] !=0)
            {
                cout << "Approve Course ID: " << approvedCourses[i] << endl ; 
                sum += 2000 ;
            } 
        }
        cout << "Total bill: " << sum << endl ; 
    }

    void addStudent(Student & st)
    {
        cout << "New student added with ID: " << st.getStudentid() << endl ; 

    }

    void cancelClass(Course &course)
    {
        cout << "Class for Course ID " << course.getCourseCode() << " canceled" << endl;
    }

    void resolveClassroomConflict(Course &course) 
    {
        cout << "Classroom conflict resolved for Course ID " << course.getCourseCode() << endl;
    }

} ;

class Faculty : public user 
{
    public:

    void login() override
    {
        cout << "Faculty looged in successfully" << endl ; 
    }

    void logout() override
    {
        cout << "Logged out successfully" << endl ; 
    }

    bool checkEnrollment(Student &student)
    {
        cout << "Student with ID: " << student.getStudentid() << endl; 
        return true ; 
    }

    void getClasslist()
    {
        
    }

    void Studentdetail(Student &st)
    {
        cout << "Student Transcript: " << st.getTranscript() << endl ; 
        cout << "Student phone number: " << st.getnumber() << endl ; 

    }


} ;


