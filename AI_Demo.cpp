#include <iostream>
#include <string>
#include <vector>
using namespace std;

int gGlobalCounter = 0;
int magicNumber = 42;

class myclass {
public:
    int x;
    int* ptr;

    myclass(int val) {
        x = val;
        // no initialization for ptr - MISRA violation (uninitialized pointer)
    }

    void AddX(double d) {
        x += static_cast<int>(d);  // explicit conversion from double to int
    }

    void print() {
        cout << "Value: " << x << endl;
    }

    void dangerousCast() {
        // reinterpret_cast abuse - SCA violation
        long* lp = reinterpret_cast<long*>(&x);
        *lp = 1234567890;
    }
};

int globalFunc(int a, int b) {
    // No input validation or error handling
    return a / b;  // potential divide by zero
}

int main() {
    myclass* obj = new myclass(5);
    obj->AddX(3.14);
    obj->print();
    obj->dangerousCast();
    obj->print();

    delete obj;

    char buffer[5];
    strcpy(buffer, "Too long string");  // buffer overflow

    cout << buffer << endl;

    int result = globalFunc(10, 0);  // divide by zero

    cout << "Result: " << result << endl;

    int uninitializedVar;  // used without initialization
    cout << "Uninitialized var: " << uninitializedVar << endl;

    vector<int> v(5);
    v[10] = 100;  // out-of-bounds write, SCA violation

    if (magicNumber == 42) {
        cout << "Magic number is 42" << endl;
    }

    return 0;
}
