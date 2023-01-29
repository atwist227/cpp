 #include <iostream>
using namespace std;
struct Student {
    unsigned int number;
    char name[30];
};
// 打印学生信息的函数
void printStudentInfo(Student stu) {
    cout << "No." << stu.number << ": "<< stu.name << endl;
}

int main() {
    Student classmates[3]{
        {10001, "Alice"}, // classmates[0]
        {10002, "Bob"},   // classmates[1]
        {10086, "Carol"}, // classmates[2]
    };
    for (int i{0}; i < 3; i++) {
        printStudentInfo(classmates[i]);
        cout << endl;
    }
}
