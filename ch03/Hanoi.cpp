#include <iostream>
using namespace std;
void moveDisk(int n, char src, char dest, char trans) {
    if (n == 1) {
        cout << "Move disk 1 from " << src << " to " << dest << endl;
        return;
    } // 因为这里 return 了，所以不需要写 else
    moveDisk(n - 1, src, trans, dest);
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    moveDisk(n - 1, trans, dest, src);
}
int main() {
    int n;
    cin >> n;
    moveDisk(n, 'A', 'C', 'B');
}
