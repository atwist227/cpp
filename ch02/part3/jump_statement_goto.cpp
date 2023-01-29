#include <iostream>
using namespace std;

int main() {
    int a[10]{0, 3, 1, 4, 2, 3, 8, 7, 4, 5};
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (a[i] == a[j]) {
                cout << "Found" << endl;
                goto outer; // 直接跳转——
            }
        }
    }
outer: // ——到标号这里！
    cout << "Exit" << endl;
}
