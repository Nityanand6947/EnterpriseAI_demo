#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gGlobalCounter = 0;

class myclass {
public:
    int x;

    myclass(int val) {
        x = val;
    }

    void AddX(double d) {
        x += d;
    }

    void print() {
        cout << "Value: " << x << endl;
    }
};

int main() {
    myclass* obj = new myclass(5);

    obj->AddX(3.14);

    obj->print();

    delete obj;

    char buffer[5];
    strcpy(buffer, "Too long string");

    cout << buffer << endl;

    return 0;
}
