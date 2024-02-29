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
#include <iomanip>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ld cosh(ld &x)
{
    return (exp(x) + exp(-x)) / 2; 
}

ld sinh(ld &x)
{
    return (exp(x) - exp(-x)) / 2; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ld d, s;
    cin >> d >> s;

    ld low = 0;
    ld high = 1000000000000000000;
    ld epsilon = 0.000000000001;
    
    ld a;

    while (high - low > epsilon)
    {
        a = (high + low) / 2;
        ld left = a + s;
        ld right = a * cosh(d / (2*a));

        if (left >= right)
            high = a;
        else
            low = a;
    }

    a = high;

    ld l = 2*a * sinh(d / (2*a));
    cout << fixed << setprecision(9) << l << endl;
}