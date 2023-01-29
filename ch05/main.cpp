#include"my_string.cpp"
#include <iostream>
int main() {
    String a("Hello");
    // String::npos 指明 npos 是“命名空间” String 的名字
    if (a.find('a') == String::npos) {
        std::cout << "string doesn't contain char a" << std::endl;
    }
}
