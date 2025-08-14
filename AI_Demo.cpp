#include <iostream>
#include <cstring>
using namespace std;  
 
class Vehicle {
public:
    int* speed;  
 
    Vehicle() {
        speed = (int*)malloc(sizeof(int)); 
        *speed = 0;
    }
 
    void setSpeed(const char* inputSpeed) {
        char buffer[5];
        strcpy(buffer, inputSpeed);  
 
       
        *speed = atoi(buffer);
    }
 
    void printSpeed() {
        cout << "Speed is: " << *speed << endl;
    }
 
    ~Vehicle() {
        free(speed);  
    }
};
 
int main() {
    Vehicle v;
    char input[10];
    cin >> input; 
 
    v.setSpeed(input);
 
    v.printSpeed();
 
    return 0; 
}