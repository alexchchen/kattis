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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

void dijkstra(vector<vector<pair<int, double>>> &adj, vector<double> &dist, int &src)
{
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

	pq.push(make_pair(0.0, src));
	dist[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for (auto e : adj[u])
		{
			int v = e.first;
			double w = e.second;

			if (dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

double stoneCost(int &a, int &b, int &h)
{
	double area = ((double)(a + b)) / 2 * h;
	return 0.02 * area;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
	while (cin >> n && n != 0)
	{
		vector<vector<pair<int, double>>> adj(1001);

		for (int i = 0; i < n; i++)
		{
			int a, b, h;
			cin >> a >> b >> h;

			double cost = stoneCost(a, b, h);

			adj[a].push_back(make_pair(b, cost));
			adj[b].push_back(make_pair(a, cost));
		}

		int src, dest;
		cin >> src >> dest;

		double inf = numeric_limits<double>::max();
		vector<double> dist(1001, inf);

		dijkstra(adj, dist, src);

		cout << fixed << setprecision(2) << dist[dest] << endl;
	}
}