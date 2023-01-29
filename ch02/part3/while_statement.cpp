#include <iostream>
using namespace std;
int main()
{
    int x{123456};
    do
    {
        cout << x % 10 << endl;
    } while (x /= 10);
}
