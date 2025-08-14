#include <iostream>
#include <cstring>
using namespace std;  // MISRA and AUTOSAR violation: avoid using directives in global scope
 
class Vehicle {
public:
    int* speed;  // MISRA: Avoid naked pointers, use smart pointers or references
 
    Vehicle() {
        speed = (int*)malloc(sizeof(int)); // AUTOSAR & MISRA violation: Use of malloc instead of new
        *speed = 0;
    }
 
    void setSpeed(const char* inputSpeed) {
        char buffer[5];
        strcpy(buffer, inputSpeed);  // SCA violation: unsafe function, buffer overflow risk
 
        // No validation on speed input (could be non-numeric or out of range)
        *speed = atoi(buffer);
    }
 
    void printSpeed() {
        cout << "Speed is: " << *speed << endl; // MISRA/AUTOSAR violation: std::cout usage not allowed in safety-critical code
    }
 
    ~Vehicle() {
        free(speed);  // MISRA/AUTOSAR violation: mixing malloc/free with C++
    }
};
 
int main() {
    Vehicle v;
    char input[10];
    cin >> input; // No input validation, unsafe
 
    v.setSpeed(input);
 
    v.printSpeed();
 
    return 0; // Missing return 0 from main is not an error in C++14 but good practice to include
}