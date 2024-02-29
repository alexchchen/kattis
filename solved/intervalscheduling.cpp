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

bool sortBySecond(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        v[i] = p;
    }

    sort(v.begin(), v.end(), sortBySecond);

    pair<int, int> p = v[0];
    int intervals = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= p.second)
        {
            intervals++;
            p = v[i];
        }
    }

    cout << intervals << endl;
}