#include "my_string.h"
#include <cstring>

// 构造函数
String::String(const char *initVal){
    len = std::strlen(initVal);
    str = new char[len + 1];
    for (unsigned int i{0}; i <= len; i++)
        str[i] = initVal[i];
}

// 构造长为num的全为c的字符串
String::String(unsigned int num, char c){
    len = num;
    str = new char[len + 1];
    for (unsigned int i{0}; i < len; i++)
        str[i] = c;
    str[len] = '\0';
}

// 无参构造函数
String::String(){ 
    len = 0;
    str = new char[1]{'\0'};
}

// 深复制
String::String(const String &initVal){
    len = initVal.len;       // 复制长度
    str = new char[len + 1]; // 申请新的内存空间
    for (unsigned i{0}; i <= len; i++)
        str[i] = initVal.str[i]; // 然后把内存里的值逐一复制
}

// 解析函数，指示在变量离开存储期时要做的事，一般都是释放new出来的内存
String::~String(){
    delete[] str; // 释放 str 所指向的内存
}


// []运算符重载，实现类似数组的访问，非只读版本
char& String::operator[](unsigned n){
    return str[n];
}

// []运算符重载，只读版本
const char& String::operator[](unsigned n) const{
    return str[n];
}

// +重载，实现字符串拼接
String String::operator+(const String &b) const{   // 最好是 const T&，避免复制开销
    char *newstr{new char[len + b.len + 1]}; // 分配新的空间，大小为两个长度相加
    std::strcpy(newstr, str);                // 把 a 的字符串复制到新空间的前半段
    std::strcpy(newstr + len, b.str);        // 把 b 的字符串复制到新空间的后半段
    String result(newstr);                   // 从这个新空间建立新的 String 对象
    delete[] newstr;                         // 现在可以删除新空间了（因为数据复制到 result 里去了）
    return result;                           // 把 result 返回就可以
}

// +=重载
String& String::operator+=(const String &b){ // 返回a的引用
    String result(operator+(b));             // 直接调用 operator+ 成员函数
    operator=(result);                       // 调用 assign 成员把结果赋值给自己
    return *this;                            // this指向类
}

// =重载
String& String::operator=(const String &assignVal){
    if (str == assignVal.str)
        return *this; // 自赋值直接返回
    delete[] str;
    len = assignVal.len;
    str = new char[len + 1];
    for (unsigned int i{0}; i <= len; i++)
        str[i] = assignVal.str[i];
    return *this;
}

// ==重载
bool String::operator==(const String &rhs) const{
    if (len != rhs.len) return false;
    for (int i{0}; i < len; i++){
        if(str[i] != rhs.str[i])
            return false;
    }
    return true;
}

// String到bool类型的转换, explicit表示只能显式转换（if for while 条件；&& || ! 操作数，?: 第一操作数；也考虑显式类型转换）
String::operator bool() const{
    if (len == 0)
        return false;
    return true;
}

// 输出字符串长度
unsigned String::length() const{
    return len;
}