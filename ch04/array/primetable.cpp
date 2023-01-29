#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    constexpr int N{100};
    bool isComopsite[N + 1]{};
    for (int i{2}; i <= sqrt(N); i++)
    {
        if (isComopsite[i])
            continue;
        for (int j{i*2}; j <= N; j += i)
            isComopsite[j] = true;
    }
    for (int i{2}; i <= N; i++)
    {
        if (!isComopsite[i])
        {
            cout << i << endl;
        }
    }
}