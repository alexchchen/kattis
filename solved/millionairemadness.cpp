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

		for (auto e : adj[u])
		{
			int v = e.first;
			int w = e.second;

			int ladder = max(dist[u], w);

			if (ladder < dist[v])
			{
				dist[v] = ladder;
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
    
    int M, N;
	cin >> M >> N;

	vector<vector<pair<int, int>>> adj(M*N);
	vector<vector<int>> vault(M, vector<int>(N));

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int h;
			cin >> h;
			vault[i][j] = h;
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int index = i*N + j;

			if (i-1 >= 0)
			{
				int diff = vault[i][j] - vault[i-1][j];

				if (diff < 0)
					adj[index].push_back(make_pair(index - N, -diff));
				else
					adj[index].push_back(make_pair(index - N, 0));
			}
			if (j+1 <= N-1)
			{
				int diff = vault[i][j] - vault[i][j+1];

				if (diff < 0)
					adj[index].push_back(make_pair(index + 1, -diff));
				else
					adj[index].push_back(make_pair(index + 1, 0));
			}
			if (i+1 <= M-1)
			{
				int diff = vault[i][j] - vault[i+1][j];

				if (diff < 0)
					adj[index].push_back(make_pair(index + N, -diff));
				else
					adj[index].push_back(make_pair(index + N, 0));
			}
			if (j-1 >= 0)
			{
				int diff = vault[i][j] - vault[i][j-1];

				if (diff < 0)
					adj[index].push_back(make_pair(index - 1, -diff));
				else
					adj[index].push_back(make_pair(index - 1, 0));
			}
		}
	}

	// for (int i = 0; i < M*N; i++)
	// {
	// 	for (int j = 0; j < adj[i].size(); j++)
	// 	{
	// 		cout << "(" << i << ", " << adj[i][j].first << ", " << adj[i][j].second << ")" << endl;
	// 	}
	// }

	int inf = numeric_limits<int>::max();
	vector<int> dist(M*N, inf);

	dijkstra(adj, dist, 0);

	cout << dist[M*N - 1] << endl;
}