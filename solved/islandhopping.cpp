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

double prim(vector<vector<pair<int, double>>> &adj)
{
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    vector<bool> visited(adj.size(), false);

    double sum = 0;

    pq.push(make_pair(0, 0));

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        int u = p.second;
        double wu = p.first;

        if (visited[u]) continue;

        sum += wu;
        visited[u] = true;

        for (auto e : adj[u])
        {
            int v = e.first;
            double wv = e.second;

            if (!visited[v])
                pq.push(make_pair(wv, v));
        }
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        
        vector<pair<double, double>> islands;

        for (int j = 0; j < m; j++)
        {
            double x, y;
            cin >> x >> y;
            islands.push_back(make_pair(x, y));
        }

        vector<vector<pair<int, double>>> adj(m);
        for (int a = 0; a < m; a++)
        {
            double ax = islands[a].first;
            double ay = islands[a].second;
            for (int b = 0; b < m; b++)
            {
                if (a != b)
                {
                    double bx = islands[b].first;
                    double by = islands[b].second;
                    double x = abs(bx - ax);
                    double y = abs(by - ay);
                    double hyp = sqrt(x*x + y*y);
                    adj[a].push_back(make_pair(b, hyp));
                    adj[b].push_back(make_pair(a, hyp));
                }
            }
        }

        cout << fixed;
        cout.precision(6);
        cout << prim(adj) << endl;
    }
}