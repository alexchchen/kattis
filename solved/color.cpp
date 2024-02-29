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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int s, c, k;
    cin >> s >> c >> k;

    vector<int> v(s);
    for (int i = 0; i < s; i++)
    {
        int j;
        cin >> j;
        v[i] = j;
    }
    sort(v.begin(), v.end());

    int machines = 1;
    int inMachine = 1;
    int curr = v[0];
    for (int i = 1; i < s; i++)
    {
        int j = v[i];

        if (abs(curr - j) > k)
        {
            machines++;
            curr = j;
            inMachine = 1;
        }
        else if (inMachine == c)
        {
            machines++;
            curr = j;
            inMachine = 1;
        }
        else
        {
            inMachine++;
        }
    }

    cout << machines << endl;
}