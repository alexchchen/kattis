#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    unsigned long long n;
    int b;
    cin >> n >> b;

    int count = 0;

    while (n != 0)
    {
        n /= (b + 1);
        count++;
    }

    cout << count;
}