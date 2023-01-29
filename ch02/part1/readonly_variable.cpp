// 再次编写一个程序，输入圆的半径，输出该圆的面积。这一次，尝试使用 constexpr 关键字。

#include<iostream>
using namespace std;

int main(){
    constexpr double pi{3.14159265358979323846l};
    double r{0}, s{0.0};
    cout << "Please enter the radius of the circle:" << endl;
    cin >> r;
    s = r*r*pi;
    cout << "The area of the circle is " << s << endl;
}