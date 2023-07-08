#include <iostream>
#include <string>
using namespace std;

class ClassB{

public:
    ClassB(int x){};

};

class Class1{
private:
    int& _num;
    ClassB _classB;

public:
//initialization list allowus to initialize fields that cant be initialized in the default cpp initializer
//and so we can initialise fields that are refrences 
//see below where we initialize _num and _classB
    Class1 (int& num): _num(num), _classB(10){};
    void print(){
        cout << _num << endl;
    }
};



int main(){
    int x = 5;
    Class1 c1(x);
    c1.print();


    return 0;

}