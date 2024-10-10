#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std ;

void Faculty::Salary() 
{
    int baseSalary = EmployeeSalary;
    int extraHours = workingHours - 36;
    if (extraHours > 0) {
    baseSalary += extraHours * 1000;
    }
cout << "Current Salary: " << baseSalary << " Rs" << std::endl;
}
void Faculty::AssignCourse(Course courseList[]) 
{
    int totalCreditHours = AssignedCourseCount * 3;
    int allCourses = 20;
    if (totalCreditHours > 12) {
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


class Staff : public Employee 
{
    private:
    int overtimeHours;
    public:
    Staff(string name, string desig, string dept, float salary, int overtime)
    : Employee(name, desig, dept, salary), overtimeHours(overtime){}

    bool Verify(string deptName) const 
    {
        return (EmployeeDept == deptName);
    }
    
    bool Verify(float minSalary, float maxSalary) const 
    {
        return (EmployeeSalary >= minSalary && EmployeeSalary <= maxSalary);
    }
    
};