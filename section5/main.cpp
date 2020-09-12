#include <iostream>

struct TestStr
{
    int id;
    std::string name;
    std::string sex;
};

int main() {
    std::cout << "hello dbus" << std::endl;

    TestStr test;
    test.id = 1;
    test.name = "";
    test.sex = "boy";
    std::cout << test.name << std::endl;
    std::cout << test.sex << std::endl;
    test.sex.clear();
    std::cout << test.sex << std::endl;
    return 0;
}