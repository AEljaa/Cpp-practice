#include <iostream>
using namespace std;
#include <string>

//3 types of access modifiers in C++ : 
//1. Public - can be accessed anywhere
//2. Private - can only be accessed by members or friends of the class
// friends of a class are functions or other classes that are granted access to private and protected members of the class
//3. Protected - can be accessed by members and friends of the class, but not from derived classes
// derived classes are classes that inherit from a base class (parent class) 


//Abstract class - a class that has at least one pure virtual function
class AbstractEmployee{
    //pure virtual function
    //the 0 means that this function is pure virtual
    virtual void AskForPromotion() = 0;
};
class Employee:AbstractEmployee{
private:
    //attributes
    string Name;
    string Company;
    int Age;

public:

//constructor - a special method that is called when an object is created.
//Rules for constructors:
//1. The constructor name must be the same as the class name
//2. The constructor must have no return type (not even void)
//3. The constructor is called when an object of a class is created
//4. At a beginner level, contrcuctors should be public


//if there is no data in the constructor, then the default constructor is called 
//the default constructor is a constructor that takes no parameters

    void setName(string name){
        Name = name;
    }

    string getName(){
        return Name;
    }

    void setCompany(string company){
        Company = company;
    }

    string getCompany(){
        return Company;
    }

    void setAge(int age){
        if(age >= 18){
            Age = age;
        }
    }

    int getAge(){
        return Age;
    }

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

    void AskForPromotion(){
        if(Age > 30){
            cout << Name << " got promoted!" << endl;
        }
        else{
            cout << Name << ", sorry no promotion for you!" << endl;
        }
    }
};

int main()
{
    //There are 4 most important principles in OOP (Object Oriented Programming):
    //1. Encapsulation - the idea of wrapping data and code together as a single unit (class)
    //2. Abstraction - the idea of hiding the details and complexity and showing only the essentials (public methods)
    //3. Inheritance - the idea of a class (child class) inheriting the properties and methods of another class (parent class)
    //4. Polymorphism - the idea of using a single type of entity (method, operator or object) to represent different types in different scenarios (overloading)

    Employee employee1("AE", "Icl", 18);
    Employee employee2("John", "Amazon", 35);
    employee1.AskForPromotion();
    employee2.AskForPromotion();
}