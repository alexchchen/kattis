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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin >> n;

    vector<ll> v(n);

    for (ll i = 0; i < n; i++)
    {
        ll j;
        cin >> j;
        v[i] = j;
    }

    sort(v.begin(), v.end());

    ll score = 0;
    for (ll i = 0; i < n-1; i++)
    {
        ll difference = abs(v[i] - v[i+1]);
        ll square = difference * difference;
        score += square;
    }

    cout << score << endl;
}