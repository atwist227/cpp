// 编写一段程序，输入圆的半径（可能是小数），计算圆的面积的近似值。

#include<iostream>
using namespace std;

int main(){
    double pi{3.14159265358979323846l};
    double r{0};
    cout << "Please enter the radius of the circle:" << endl;
    cin >> r;
    cout << "The area of the circle is " << r*r*pi << endl;
}