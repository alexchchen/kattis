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
    
    int l, d, n;
    cin >> l >> d >> n;
    
    int total = 0;

    if (n == 0)
    {
        total = ((l-12) / d) + 1;
        cout << total << endl;
        return 0;
    }

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        v[i] = j;
    }

    sort(v.begin(), v.end());

    int low = 6;
    int high = l-6;
    int curr = low;
    
    for (int i = 0; i < n; i++)
    {
        while (v[i] - curr >= d)
        {
            total++;
            curr += d;
        }
        curr = v[i] + d;
    }

    while (curr <= high)
    {
        total++;
        curr += d;
    }

    cout << total << endl;
}