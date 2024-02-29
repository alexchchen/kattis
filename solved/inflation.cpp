#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
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
    
    int n;
    cin >> n;

    vector<int> b(n);
    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        c[i] = j;

        b[i] = i+1;
    }

    sort(c.begin(), c.end());

    double minimum = 1.0;

    for (int i = 0; i < n; i++)
    {
        int difference = b[i] - c[i];
        if (difference < 0)
        {
            cout << "impossible" << endl;
            return 0;
        }
        else
        {
            double fraction = (double)c[i] / (double)b[i];
            if (fraction < minimum)
            {
                minimum = fraction;
            }
        }
    }

    printf("%f", minimum);
}