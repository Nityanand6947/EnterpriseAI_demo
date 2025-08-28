#include <iostream>
#include <vector>
using namespace std;

int gGlobal_Var = 100;

class my_class {
public:
    int member_var;

    my_class(int val) : member_var(val) {}

    int GetValue() const {
        return member_var;
    }
};

int main() {
    my_class obj(42);
    cout << "Value: " << obj.GetValue() << endl;
    return 0;
}
