#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std ;

class Employee 
{
    protected:
    string EmployeeName, EmployeeDesignation, EmployeeDept;
    double EmployeeSalary;
    public:
    Employee(string name, string desig, string dept, double salary) 
    {
        EmployeeName = name;
        EmployeeDesignation = desig;
        EmployeeDept = dept;
        EmployeeSalary = salary;
    }
    string getEmployeeName() 
    { 
        return EmployeeName; 
    }
    string getDesignation() 
    { 
        return EmployeeDesignation; 
    }
    string getDepartment() 
    { 
        return EmployeeDept; 
    }
    double getSalary() 
    { 
        return EmployeeSalary; 
    }
    double operator++(int);
};
class Course 
{
    private:
    string CourseName, CourseCode;
    int CourseCreditHours;
    bool Assigned;
    public:
    Course(string name, string code, int hours, bool assigned) 
    {
        CourseName = name;
        CourseCode = code;
        CourseCreditHours = hours;
        Assigned = assigned;
    }
    string getCourseName() 
    { 
        return CourseName; 
    }
    string getCourseCode() 
    { 
        return CourseCode; 
    }
    int getCreditHours() 
    { 
        return CourseCreditHours; 
    }

    bool isAssigned() 
    { 
        return Assigned; 
    }
    void setAssigned(bool f) 
    {
        Assigned = f;
    }
};

void Faculty::Salary() 
{
    int baseSalary = EmployeeSalary;
    int extraHours = workingHours - 36;
    if (extraHours > 0) 
    {
        baseSalary += extraHours * 1000;
    }
    cout << "Current Salary: " << baseSalary << " Rs" << std::endl;
}
void Faculty::AssignCourse(Course courseList[]) 
{
    int totalCreditHours = AssignedCourseCount * 3;
    int allCourses = 20;
    if (totalCreditHours > 12) 
    {
        cout << "Warning: Assigned credit hours (" << totalCreditHours << ") exceed
        maximum limit of 12." << endl;
    for (int i = 0; i < allCourses; i++) 
    {
        if (!courseList[i].isAssigned()) {
            if (EmployeeDept == "Computer Science" && courseList[i].getCourseCode().substr(0, 1) == "C") 
            {
                courseList[i].setAssigned(true);
                totalCreditHours += courseList[i].getCreditHours();
                cout << "Course " << courseList[i].getCourseName() << " assigned to" << getEmployeeName() << endl;
                i = allCourses;
            }
            else if (EmployeeDept == "Management Science" && courseList[i].getCourseCode().substr(0, 1) == "M") 
            {
                courseList[i].setAssigned(true);
                totalCreditHours += courseList[i].getCreditHours();
                cout << "Course " << courseList[i].getCourseName() << " assigned to" << getEmployeeName() << endl;
            i = allCourses;
            }
            else if (EmployeeDept == "Electrical Engineering" &&
            courseList[i].getCourseCode().substr(0, 1) == "E") {
            courseList[i].setAssigned(true);
            totalCreditHours += courseList[i].getCreditHours();
            cout << "Course " << courseList[i].getCourseName() << " assigned to" << getEmployeeName() << endl;
            i = allCourses;
            }
        }   
    }
    }
}


double Employee::operator++(int) 
{
    double increase = EmployeeSalary * 0.1;
    EmployeeSalary += increase;
    return EmployeeSalary;
}

// Overloaded ++ operator for Faculty class
Faculty Faculty::operator++(int) 
{
    double increase = EmployeeSalary * 0.2;
    EmployeeSalary += increase;
    if (EmployeeDesignation == "Instructor") 
    {
        EmployeeDesignation = "Lecturer";
    } 
    else if (EmployeeDesignation == "Lecturer") 
    {
        EmployeeDesignation = "Assistant Professor";
    }
    return *this;
}

// Overloaded + operator for Staff class
int Staff::operator + (Faculty & ob)
{
    return EmployeeSalary + ob.getSalary();
}