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


    void IntroduceYourself(){
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
};

int main()
{
    Employee employee1;
    employee1.Name = "AE";   
    employee1.Company = "Icl";
    employee1.Age = 18;
    employee1.IntroduceYourself();

    Employee employee2;
    employee2.Name = "John";
    employee2.Company = "Amazon";
    employee2.Age = 35;
    employee2.IntroduceYourself();
}