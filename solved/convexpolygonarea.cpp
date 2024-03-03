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
#include <functional>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

double shoelace(vector<pair<int, int>> &points)
{
    double total = 0;
    
    int n = points.size();

    for (int i = 0; i < n-1; i++)
    {
        int x1 = points[i].first;
        int y1 = points[i].second;
        int x2 = points[i+1].first;
        int y2 = points[i+1].second;
        total += x1*y2 - x2*y1;
    }

    total += points[0].second*points[n-1].first - points[0].first*points[n-1].second;

    total = abs(total);
    total *= 0.5;
    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    while (n--)
    {
        int m;
        cin >> m;
        
        vector<pair<int, int>> points(m);

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            points[i] = make_pair(x, y);
        }

        cout << shoelace(points) << endl;
    }
}