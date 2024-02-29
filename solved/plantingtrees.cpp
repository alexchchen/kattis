#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

bool sortByDescend(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        v[i] = j;
    }

    sort(v.begin(), v.end(), sortByDescend);

    int maximum = 0;

    for (int i = 0; i < n; i++)
    {
        int t = i + 1 + v[i];
        if (t > maximum)
            maximum = t;
    }
    maximum++;

    cout << maximum << endl;
}