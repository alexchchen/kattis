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

void dijkstra(vector<vector<pair<int, int>>> &adj, vector<int> &dist, vector<int> &paths, int src)
{
    set<pair<int, int>> s;

    s.insert(make_pair(0, src));
    dist[src] = 0;
    paths[src] = 1;

    while (!s.empty())
    {
        pair<int, int> p = *s.begin();
        int u = p.second;
        s.erase(p);

        for (auto e : adj[u])
        {
            int v = e.first;
            int w = e.second;

            if (dist[u] + w < dist[v])
            {
                if (s.find(make_pair(dist[v], v)) != s.end())
                    s.erase(make_pair(dist[v], v));
                paths[v] = paths[u];
                dist[v] = dist[u] + w;
                s.insert(make_pair(dist[v], v));
            }
            else if (dist[u] + w == dist[v])
            {
                paths[v] += paths[u];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);
    vector<int> paths(V);

    int inf = numeric_limits<int>::max();
    vector<int> dist(V, inf);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    int s, t;
    cin >> s >> t;
    
    dijkstra(adj, dist, paths, s);

    cout << paths[t] << endl;
}