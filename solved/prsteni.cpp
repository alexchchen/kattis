#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <set>
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
#include <functional>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const double pi = 3.14159265358979323846;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> rings(n);

    for (int i = 0; i < n; i++)
    {
        cin >> rings[i];
    }

    int a = rings[0];

    for (int i = 1; i < n; i++)
    {
        int r = rings[i];
        int divisor = gcd(a, r);
        cout << a/divisor << "/" << r/divisor << endl;
    }
}