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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    while (cin >> n && n != 0)
    {
        map<int, int> m;
        vector<int> v1(n);
        vector<int> v2(n);

        for (int i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            m[j] = i;
            v1[i] = j;
        }

        for (int i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            v2[i] = j;
        }

        sort(v2.begin(), v2.end());

        for (auto i : v1)
        {
            int index = distance(m.begin(), m.find(i));
            cout << v2[index] << endl;
        }

        cout << endl;
    }
}