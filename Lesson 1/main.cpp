#include <iostream>
using namespace std;
#include <string>

//3 types of access modifiers in C++ : 
//1. Public - can be accessed anywhere
//2. Private - can only be accessed by members or friends of the class
// friends of a class are functions or other classes that are granted access to private and protected members of the class
//3. Protected - can be accessed by members and friends of the class, but not from derived classes
// derived classes are classes that inherit from a base class (parent class) 
class Employee{
public:
    string Name;
    string Company;
    int Age;

//constructor - a special method that is called when an object is created.
//Rules for constructors:
//1. The constructor name must be the same as the class name
//2. The constructor must have no return type (not even void)
//3. The constructor is called when an object of a class is created
//4. At a beginner level, contrcuctors should be public


//if there is no data in the constructor, then the default constructor is called 
//the default constructor is a constructor that takes no parameters

    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }

    void IntroduceYourself(){
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
};

int main()
{
    Employee employee1("AE", "Icl", 18);

    employee1.IntroduceYourself();

    Employee employee2("John", "Amazon", 35);

    employee2.IntroduceYourself();
}