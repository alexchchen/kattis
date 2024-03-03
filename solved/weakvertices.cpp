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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;    
    while (cin >> n && n != -1)
    {
        vector<vector<int>> v(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int k;
                cin >> k;
                v[i][j] = k; 
            }
        }

        vector<int> v2;

        for (int i = 0; i < n; i++)
        {
            bool weak = true;
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == 1)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (v[i][k] == 1 && v[j][k] == 1 && k != i)
                        {
                            weak = false;
                        }
                    }
                }
            }
            if (weak)
                v2.push_back(i);
        }

        for (int i : v2)
            cout << i << " ";
        cout << endl;
    }
}