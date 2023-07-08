#include <iostream>
using namespace std;

//In this function we are passing the address of the string as a copy
void PrintString(string* str){
    cout << *str << endl;
}

//In this function we are passing the string as a reference
void PrintString2(string& str){
// a reference is like a pointer but with limiations
// you can't change the address of a reference
    cout << str << endl;
}


int main(){
    //refernes can be of all types
    string blegh ="Hey";
    //this & is the address of operator
    PrintString(&blegh);
    PrintString2(blegh);

    int number1=5,number2=6;
    //we are settign the number pointer to the address of number1
    int* numberPtr = &number1;
    //we are setting the value of the address of number2 to the value of the address of number1
    *numberPtr=number2;


    return 0;
}