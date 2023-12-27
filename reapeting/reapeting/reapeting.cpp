#include <iostream>
#include <string>

using namespace std;

class numbers {
public:
    virtual string foo() = 0;
};
class numberOne:public numbers {
public:
    string foo() override {
        return "number one";
    }
};
class numberTwo:public numbers {
public:
    string foo() override {
        return "number one";
    }
};

void print(numbers *Class) {
    cout << Class->foo() << endl;
}

int main()
{
    numberOne one;
    print(&one);
}