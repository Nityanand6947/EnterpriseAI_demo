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
        // x += d;  // implicit narrowing conversion
        x += static_cast<int>(d);
    }

    void print() {
        cout << "Value: " << x << endl;
    }

    void dangerousCast() {
        // reinterpret_cast abuse - SCA violation
        // long* lp = reinterpret_cast<long*>(&x);
        // *lp = 1234567890;
        x = 1234567890; // Direct assignment instead of type punning
    }
};

int globalFunc(int a, int b) {
    // No input validation or error handling
    // return a / b;  // potential divide by zero
    if (b == 0) {
	        // Handle error case, e.g., return an error code or a default value
	        return 0;  // Or another appropriate error handling strategy
	    }
	    return a / b;
}

int main() {
    myclass* obj = new myclass(5);
    obj->AddX(3.14);
    obj->print();
    obj->dangerousCast();
    obj->print();

    delete obj;

    // char buffer[5];
    // strcpy(buffer, "Too long string");  // buffer overflow
    char buffer[5];
	    strncpy(buffer, "Too", sizeof(buffer) - 1); buffer[sizeof(buffer) - 1] = '\0';  // Prevent buffer overflow

    cout << buffer << endl;

    // int result = globalFunc(10, 0);  // divide by zero
    int result = globalFunc(10, 2); // Use a non-zero divisor

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
