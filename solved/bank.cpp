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

bool sortByMaxValue(const pair<int,int> &a, const pair<int, int> &b) 
{
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        v[i] = p;
    }

    sort(v.begin(), v.end(), sortByMaxValue);

    vector<int> v2(t);

    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = v[i];
        
        for (int j = p.second; j >= 0; j--)
        {
            if (v2[j] == 0)
            {
                v2[j] = p.first;
                break;
            }
        }
    }

    int total = 0;
    for (int i : v2)
    {
        total += i;
    }

    cout << total << endl;
}