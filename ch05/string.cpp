#include<iostream>
#include<cstring>
class String {
private:
    unsigned len;

public:
    char* str;

    String();
    String(const String&);
    String(const char*);
    String(unsigned, char);
    ~String();

    char operator[](unsigned);
    String operator+(const String&);
    String& operator+=(const String&);
    String& operator=(const String&);
    bool operator==(const String&);
    explicit operator bool();
    explicit operator unsigned();

    unsigned length();
};


String::String(const char *initVal){ // 构造函数
    len = std::strlen(initVal);
    str = new char[len + 1];
    for (unsigned int i{0}; i <= len; i++)
        str[i] = initVal[i];
}

String::String(unsigned int num, char c){ // 构造长为num的全为c的字符串
    len = num;
    str = new char[len + 1];
    for (unsigned int i{0}; i < len; i++)
        str[i] = c;
    str[len] = '\0';
}

String::String(){ // 无参构造函数
    len = 0;
    str = new char[1]{'\0'};
}

String::String(const String &initVal){// 深复制
    len = initVal.len;       // 复制长度
    str = new char[len + 1]; // 申请新的内存空间
    for (unsigned i{0}; i <= len; i++)
        str[i] = initVal.str[i]; // 然后把内存里的值逐一复制
}

String::~String(){// 解析函数，指示在变量离开存储期时要做的事，一般都是释放new出来的内存
    delete[] str; // 释放 str 所指向的内存
}


// []运算符重载，实现类似数组的访问
char String::operator[](unsigned int n){
    return str[n];
}

// +重载，实现字符串拼接
String String::operator+(const String &b){   // 最好是 const T&，避免复制开销
    char *newstr{new char[len + b.len + 1]}; // 分配新的空间，大小为两个长度相加
    std::strcpy(newstr, str);                // 把 a 的字符串复制到新空间的前半段
    std::strcpy(newstr + len, b.str);        // 把 b 的字符串复制到新空间的后半段
    String result(newstr);                   // 从这个新空间建立新的 String 对象
    delete[] newstr;                         // 现在可以删除新空间了（因为数据复制到 result 里去了）
    return result;                           // 把 result 返回就可以
}

String& String::operator+=(const String &b){ // 返回a的引用
    String result(operator+(b));             // 直接调用 operator+ 成员函数
    operator=(result);                       // 调用 assign 成员把结果赋值给自己
    return *this;                            // this指向类
}

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

bool String::operator==(const String &rhs){
    if (len != rhs.len) return false;
    for (int i{0}; i < len; i++){
        if(str[i] != rhs.str[i])
            return false;
    }
    return true;
}

// 类型转换重载
// String到bool类型的转换, explicit表示只能显式转换（if for while 条件；&& || ! 操作数，?: 第一操作数；也考虑显式类型转换）
String::operator bool(){
    if (len == 0)
        return false;
    return true;
}

String::operator unsigned(){
    return len;
}

unsigned String::length(){
    return len;
}

// 函数重载：函数名相同，参数列表类型不同时程序自动选择最接近的。
void print(const String& s){
    std::cout << s.str << std::endl;
}

void print(int n){
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

int main(){
    // String a("Hello"),b("Hi");
    // b=a;
    // if (a){
    //     print("String is not empty.");
    // }
    // else{
    //     print("String is empty. Aborted.");
    // }

    String a("42"),b("24");
    print(a==b);
}