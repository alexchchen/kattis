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
#include <tuple>
#include <climits>
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
   
    int P, T;
    cin >> P >> T;

    unordered_map<int, vector<int>> m;

    set<vector<int>> s;

    int i, j;
    while (cin >> i >> j) {
        m[i].push_back(j);
    }

    for (int k = 1; k <= P; k++) {
        auto& v = m[k];
        sort(v.begin(), v.end());
        s.insert(v);
    }

    cout << s.size() << endl;
}