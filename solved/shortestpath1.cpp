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

void dijkstra(vector<vector<pair<int, int>>> &adj, vector<int> &dist, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto p : adj[u])
        {
            int v = p.first;
            int w = p.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, q, s;
    while (cin >> n >> m >> q >> s)
    {
        if (n == 0 && m == 0 && q == 0 && s == 0)
            break;

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back(make_pair(v, w));
        }

        int inf = numeric_limits<int>::max();
        vector<int> dist(adj.size(), inf);
        
        dijkstra(adj, dist, s);

        for (int i = 0; i < q; i++)
        {
            int dest;
            cin >> dest;
            if (dist[dest] == inf)
                cout << "Impossible" << endl;
            else
                cout << dist[dest] << endl;
        }
        cout << endl;
    }
}