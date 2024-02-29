#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <iterator>

#define ull unsigned long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ull n, k;
    cin >> n >> k;

    vector<ull> fib(100001);

    fib[1] = 1;
    fib[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        if ((fib[i-2] + fib[i-1]) > 1000000000000000000)
            fib[i] = 1000000000000000001;
        else
            fib[i] = fib[i-2] + fib[i-1];
    }

    while (n > 2)
    {
        if (k > fib[n-2])
        {
            k -= fib[n-2];
            n--;
        }
        else
        {
            n -= 2;
        }
    }

    if (n == 1)
        cout << 'N' << endl;
    else
        cout << 'A' << endl;
}