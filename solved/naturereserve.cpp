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

ll prim(vector<vector<pair<ll, ll>>> &adj)
{
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

	vector<bool> visited(adj.size(), false);

	ll sum = 0;

	pq.push(make_pair(0, 0));

	while (!pq.empty())
	{
		auto p = pq.top();
		ll u = p.second;
		ll wu = p.first;
		pq.pop();

		if (visited[u]) continue;

		sum += wu;
		visited[u] = true;

		for (auto e : adj[u])
		{
			ll v = e.first;
			ll wv = e.second;

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
	while (n--)
	{
		ll N, M, L, S;
		cin >> N >> M >> L >> S;

		vector<vector<pair<ll, ll>>> adj(N+1);

		for (ll i = 0; i < S; i++)
		{
			ll s;
			cin >> s;
			adj[0].push_back(make_pair(s, 0));
		}

		for (ll k = 0; k < M; k++)
		{
			ll i, j, Eij;
			cin >> i >> j >> Eij;
			adj[i].push_back(make_pair(j, Eij + L));
			adj[j].push_back(make_pair(i, Eij + L));
		}

		cout << prim(adj) << endl;
	}
}