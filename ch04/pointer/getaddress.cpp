#include <iostream>
using namespace std;
int main() {
    int a[5]{};
    cout << sizeof(*(&a)) << endl;
    cout << sizeof(*( a)) << endl;
}
