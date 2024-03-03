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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n+1);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		int c = g[i].size() - i;
		cout << c << " ";
	}
}