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

#define ll long long

using namespace std;

bool sortLegs(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        v[i] = i;

    vector<pair<int, int>> legs(k);

    for (int i = 0; i < k; i++)
    {
        pair<int, int> leg;
        int a, b;
        cin >> a >> b;
        leg.first = a;
        leg.second = b;
        legs[i] = leg;
    }

    sort(legs.begin(), legs.end(), sortLegs);

    for (auto leg : legs)
    {
        int i = leg.first;
        swap(v[i], v[i+1]);
    }

    for (auto i : v)
    {
        cout << i << " ";
    }
}