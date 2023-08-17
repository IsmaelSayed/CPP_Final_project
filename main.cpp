#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
// Write file function
void writeFile(string filename, string content)
{
    ofstream outFile(filename, ios::app); // Open file in append mode

    if (outFile.is_open())
    {
        outFile <<endl<< content ;
        outFile.close();
        cout << "Content appended to the file successfully." << endl;
    }
    else
    {
        cout << "Unable to open file for writing." << endl;
    }
}
/////read file function
string readFile(string filename)
{
    ifstream inFile(filename);
    string content;
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            content += line + "\n";
        }
        inFile.close();
    }
    else
    {
        cout << "Unable to open file for reading." <<endl;
    }
    return content;
}

// person class
class Person
{
public :
    string Name;
    int Age ;
    int Id;
    Person ()
    {
    }
    Person (string n, int a, int id )
    {
        Name = n ;
        Age = a;
        Id =id;
    }
    virtual void role ()=0;

};
//manager class
class Manager : public Person
{
    static Manager *instance;
    int salary;
public :
    static Manager* getinctance()
    {
        if (instance == nullptr)
        {
            instance = new Manager() ;
        }
        return instance;
    }
    void role ()
    {
        cout<<"I'm manager"<<endl;
    }
    void setSalary(int s)
    {
        salary=s;
    }
    int getSalart()
    {
        return salary;
    }
};
Manager* Manager::instance = nullptr;

//Student class
class Student : public Person
{
public :
    float GPA ;
    Student (float g)
    {
        GPA = g;
    }
    student()
    {
    }
    void role()
    {
        cout<<"I'm Student"<<endl;
    }
};

//class Instructor
class Instructor : public Person
{
public :
    int Salary;
    int Hours;
    Instructor(int h, int s)
    {
        Salary=s;
        Hours=h;
    }
    Instructor()
    {
    }
    void role()
    {
        cout<<"I'm instructor"<<endl;
    }
};


//class Employee
class Employee : public Person
{
public :
    int salary ;
    Employee( int s)
    {
        salary = s;
    }
    Employee()
    {
    }
    void role()
    {
        cout<<"I'm Employee"<<endl;
    }
};


//class Course
class Course
{
public:
    string title;
    int Icourse_id;
    Course(string t, int I_id)
    {
        title=t;
        Icourse_id=I_id ;
    }
    Course()
    {

    }
    void details()
    {
        cout <<"Course name is : "<<title<<endl;
        cout <<"Course id is : "<<Icourse_id<<endl;
    }

};

//Department class
class Department
{
public:
    string title;
    vector<Course>course;
    Department (string t )
    {
        title =t;
    }
    Department()    {    }
    void addCourse(Course c)
    {
        writeFile("Courses.txt",c.title);
        course.push_back(c);
    }
    void details()
    {
        cout<<"Department name is : "<<title<<endl;
        cout<<"Courses in this Department is : "<<readFile("Courses.txt")<<endl;
        cout<<" number of Courses in this Department is : "<<course.size()<<endl;
    }
};

//faculty
class Faculity
{
public :
    string title;
    vector<Student>stundent;
    vector<Instructor>instructor;
    vector<Employee>employee;
    vector<Department>department;
    Faculity(string t )
    {
        title =t;
    }
    Faculity()
    {
    }
    void details ()
    {
        cout<<"Faculty name is : "<<title<<endl;
        cout<<"Students in this Faculty are : "<<readFile("Student.txt")<<endl;
        cout<<"number of students in this Faculty are : "<<stundent.size()<<endl;
            cout<<"Instructors in this Faculty are : "<<readFile("Instructors.txt")<<endl;
            cout<<"number of Instructors in this Faculty are : "<<instructor.size()<<endl;
        cout<<"Employees in this Faculty are : "<<readFile("Emplyees.txt")<<endl;
        cout<<"number of Employees in this Faculty are : "<<employee.size()<<endl;
            cout<<"Departments in this Faculty are : "<<readFile("Departmens.txt")<<endl;
            cout<<"number of Departments in this Faculty are : "<<department.size()<<endl;
    }
    void addStudent(Student s)
    {
        writeFile("Student.txt",s.Name);
        stundent.push_back(s);
    }
    void addInstructor(Instructor i)
    {
        writeFile("Instructor.txt",i.Name);
        instructor.push_back(i);
    }
    void addEmployee(Employee e)
    {
        writeFile("Employee.txt",e.Name);
        employee.push_back(e);
    }
    void addDepartment(Department d)
    {
        writeFile("Department.txt",d.title);
        department.push_back(d);

    }
};



//University class
class University
{
public :
    string title;
    vector<Faculity>faculty ;
    Manager manager;
    University(string t, Manager m )
    {
        title =t;
        manager=m;
    }
    University(){}
    void ditails()
    {
        cout<<"University name is : "<<title<<endl;
        cout<<"Faculties name are : "<<readFile("Faculities.txt")<<endl;
        cout<<"number of Faculities in this Faculty are : "<<faculty.size()<<endl;
        }
    void addFaculity(Faculity f)
    {
        writeFile("Faculities.txt",f.title);
        faculty.push_back(f);
    }};



int main()
{
    Department d1;
    Course c1;
    c1.title="it";
    Course c2;
    c2.title="cs";
    Course c3;
    c3.title="oop";
    d1.addCourse(c3);
    d1.details();
    University u;
    u.title="SVU";
    Faculity f;
    f.title="computer science";
    Faculity f1;
    f1.title="eng";
    u.addFaculity(f1);
    u.ditails();
    c1.title="cs";
    c1.Icourse_id=2010;
    c2.title="it";
    c2.Icourse_id=2110;
    c1.details();
    c2.details();
    return 0;
}






cout << "Hello world!" << endl;
