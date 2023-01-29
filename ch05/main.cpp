#include"my_string.cpp"
#include <iostream>
// 只需要 x 的值，所以用只读引用防止复制开销和更改
bool isOk(const String& x) {
    return x == "Hello" || x == "Hi";
}
int main() {
    String a("Hello");
    if (isOk(a)) {
        std::cout << "How are you?" << std::endl;
    }
}
