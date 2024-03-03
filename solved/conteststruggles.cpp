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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int n, k, d, s;
    cin >> n >> k >> d >> s;

    int b = s*k;
    int a = d*n - b;
    double avg = (double) a / (n-k);

    if (avg >= 0 && avg <= 100)
        cout << fixed << setprecision(9) << avg << endl;
    else
        cout << "impossible" << endl;
}