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
    // string Name;
    string Company;
    int Age;

protected:
    string Name;
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

    //The virtual keyword is used to tell the compiler to use the method that is in any derived child classes instead of the method in the parent class (depending on the child class that is used to call the method)
    virtual void Work(){
        cout << Name << " is checking email, task backlog, performing tasks..." << endl;
    }
};


//creating a child class of Employee called Developer,which inherits from Employee (all the attributes and methods of the Employee class
class Developer:public Employee{
private:
    string FavProgrammingLanguage;
    int bugsFixed;
public:

    Developer(string name, string company, int age, string favProgrammingLanguage):Employee(name, company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }

    void FixBug(){
        //we can access the attributes of the parent class using the methods of the parent class
        bugsFixed++;
        cout << getName() << " fixed bug using " << FavProgrammingLanguage << endl;
    }

    void Work(){
        cout << Name << " is writing " << FavProgrammingLanguage << " code" << endl;
    }

    // void AskForPromotion(){
    //     if (bugsFixed > 5){
    //         cout << getName() << " got promoted!" << endl;
    //     }
    //     else{
    //         cout << getName() << ", sorry no promotion for you!" << endl;
    //     }
    // }

};

class Teacher:public Employee{
private:
    string Subject;
    int lessonsPrepared;

public:
    void PrepareLesson(){
        lessonsPrepared++;
        cout << getName() << " is preparing a " << Subject << " lesson" << endl;
    }

    Teacher(string name, string company, int age, string subject):Employee(name, company, age)
    {
        Subject = subject;
    }

    void Work(){
        cout << Name << " is teaching " << Subject << endl;
    }

    // void AskForPromotion(){
    //     if (lessonsPrepared > 5){
    //         cout << getName() << " got promoted!" << endl;
    //     }
    //     else{
    //         cout << getName() << ", sorry no promotion for you!" << endl;
    //     }
    // }
};


int main()
{
    //There are 4 most important principles in OOP (Object Oriented Programming):
    //1. Encapsulation - the idea of wrapping data and code together as a single unit (class)
    //2. Abstraction - the idea of hiding the details and complexity and showing only the essentials (public methods)
    //3. Inheritance - the idea of a class (child class) inheriting the properties and methods of another class (parent class)
    //4. Polymorphism - the idea of using a single type of entity (method, operator or object) to represent different types in different scenarios (overloading)
    // the most common uses of polymorphism is method overloading, which is when a class has multiple methods with the same name but different parameters. And the correct method is chosen at compile time depending on the arguments passed to the method
    //And method overriding, which is when a child class has a method with the same name and parameters as a method in the parent class. And the correct method is chosen at run time depending on the object that is used to call the method
    
    // Employee employee1("AE", "Icl", 18);
    // Employee employee2("John", "Amazon", 35);
    Developer dev1 = Developer("Jack", "Google", 40, "C++");
    Teacher teacher1 = Teacher("Sally", "Best Skl", 35, "Math");

    // dev1.Work();
    // teacher1.Work();

    // employee1.AskForPromotion();
    // employee2.AskForPromotion();
    // dev1.AskForPromotion();
    // teacher1.PrepareLesson();

    Employee *e1= &dev1;
    Employee *e2= &teacher1;

    e1->Work();
    e2->Work();
}