#include<iostream>

struct Coordinate {
    int x, y;
    int z{42};
}; // 别忘了这有一个分号

int main(){
    Coordinate a{1,2}; //这是聚合初始化。能够使用聚合初始化的前提是没有显式给出的构造函数；然而在面向对象编程中这很罕见。所以在之后的学习中我们可能很少使用聚合初始化。
    std::cout << a.x << std::endl;
    std::cout << a.y << std::endl;
    std::cout << a.z << std::endl;
    Coordinate b{};
    std::cout << b.x << std::endl;
    std::cout << b.y << std::endl;
    std::cout << b.z << std::endl;
    Coordinate c;
    std::cout << c.x << std::endl;
    std::cout << c.y << std::endl;
    std::cout << c.z << std::endl;
}