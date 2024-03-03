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
#include <tuple>
#include <climits>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int inf = 1000000000;

void bellman_ford(vector<vector<pair<int, int>>> &adj, vector<int> &dist, int &src)
{
    dist[src] = 0;

    for (int i = 0; i < adj.size() - 1; i++)
    {
        for (int u = 0; u < adj.size(); u++)
        {
            if (dist[u] != inf)
            {
                for (auto e : adj[u])
                {
                    int v = e.first;
                    int w = e.second;
                    dist[v] = min(dist[v], dist[u] + w);
                }
            }
        }
    }

	for (int i = 0; i < adj.size() - 1; i++)
	{
		 for (int u = 0; u < adj.size(); u++)
		{
			if (dist[u] != inf)
			{
				for (auto e : adj[u])
				{
					int v = e.first;
					int w = e.second;
					if (dist[v] > dist[u] + w)
						dist[v] = -inf;
				}
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
        vector<int> dist(n, inf);

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
        }

        bellman_ford(adj, dist, s);

        for (int i = 0; i < q; i++)
        {
            int j;
            cin >> j;

            if (dist[j] == -inf)
                cout << "-Infinity" << endl;
            else if (dist[j] == inf)
                cout << "Impossible" << endl;
            else
                cout << dist[j] << endl;
        }

        cout << endl;
    }
}