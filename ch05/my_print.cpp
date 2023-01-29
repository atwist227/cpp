#include<iostream>
// 函数重载：函数名相同，参数列表类型不同时程序自动选择最接近的。
void print(const String& s){
    std::cout << s.str << std::endl;
}

void print(int n){
    std::cout << n << std::endl;
}

void print(unsigned n){
    std::cout << n << std::endl;
}

void print(const char& str){
    std::cout << str << std::endl;
}

void print(bool tag){
    if (tag) {
        std::cout << "True" << std::endl;
    }
    else{
        std::cout << "False" << std::endl;
    }

}