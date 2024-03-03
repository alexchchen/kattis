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

void prim(vector<vector<pair<int, int>>> &adj)
{
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

	vector<bool> visited(adj.size(), false);

	pq.push(make_tuple(0, 0, 1));

	while (!pq.empty())
	{
		auto t = pq.top();
		int u = get<2>(t);
		int p = get<1>(t);
		int wu = get<0>(t);
		pq.pop();

		if (visited[u]) continue;

		visited[u] = true;

		if (wu != 0)
			cout << p << " " << u << endl;

		for (auto e : adj[u])
		{
			int v = e.first;
			int wv = e.second;

			if (!visited[v])
				pq.push(make_tuple(wv, u, v));
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
	cin >> n;

	vector<vector<pair<int, int>>> adj(n+1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int k;
			cin >> k;
			adj[i].push_back(make_pair(j, k));
			adj[j].push_back(make_pair(i, k));
		}
	}	

	prim(adj);
}