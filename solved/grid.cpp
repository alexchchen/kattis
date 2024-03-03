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

void bfs(vector<vector<int>> &v, vector<int> &pred, int src, int dest)
{
    vector<bool> visited(v.size());
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < v[u].size(); i++)
        {
            if (visited[v[u][i]] == false)
            {
                visited[v[u][i]] = true;
                pred[v[u][i]] = u;
                q.push(v[u][i]);

                if (v[u][i] == dest)
                    return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
	cin >> n >> m;
	cin.ignore();

	vector<vector<int>> v1(n, vector<int>(m));

 	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin, line);
		for (int j = 0; j < m; j++)
		{
			v1[i][j] = line[j] - '0';
		}
	}

	vector<vector<int>> v2(n*m);
	int index = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i - v1[i][j] >= 0)
			{
				v2[index].push_back(index - m*v1[i][j]);
			}
			if (j + v1[i][j] <= m-1)
			{
				v2[index].push_back(index + v1[i][j]);
			}
			if (i + v1[i][j] <= n-1)
			{
				v2[index].push_back(index + m*v1[i][j]);
			}
			if (j - v1[i][j] >= 0)
			{
				v2[index].push_back(index - v1[i][j]);
			}
			index++;
		}
	}

	vector<int> pred(n*m, -1);
	bfs(v2, pred, 0, n*m-1);

	vector<int> path;
	int crawl = n*m-1;
	path.push_back(crawl);
	while (pred[crawl] != -1)
	{
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}

	if (path.size() == 1)
		cout << -1 << endl;
	else
		cout << path.size()-1 << endl;
}