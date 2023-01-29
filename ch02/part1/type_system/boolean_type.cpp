// 编写一个程序：输入 5 个数 ，如果其中存在一个大于等于 10 的数就输出 NO ；如果所有数都小于 10 就输出 YES 。

#include<iostream>
using namespace std;

int main(){
    bool flag{true};
    int a{0};
    for (int i{0}; i < 5; i++){
        cin >> a;
        if (a >= 10){
            flag = false;
        }
    }
    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}