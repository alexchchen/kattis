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

int prim(vector<vector<pair<int, int>>> &adj)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	vector<bool> visited(adj.size(), false);

	int sum = 0;

	pq.push(make_pair(0, 0));

	while (!pq.empty())
	{
		auto p = pq.top();
		int u = p.second;
		int wu = p.first;
		pq.pop();

		if (visited[u]) continue;

		sum += wu;
		visited[u] = true;

		for (auto e : adj[u])
		{
			int v = e.first;
			int wv = e.second;

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
    
    int T;
	cin >> T;
	while (T--)
	{
		int M, C;
		cin >> M >> C;

		vector<vector<pair<int, int>>> adj(C);
		
		int n = C * (C-1) / 2;
		for (int k = 0; k < n; k++)
		{
			int i, j, Dij;
			cin >> i >> j >> Dij;
			adj[i].push_back(make_pair(j, Dij));
			adj[j].push_back(make_pair(i, Dij));
		}

		if (prim(adj) + C <= M)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}