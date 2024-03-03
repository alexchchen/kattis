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

const int INF = 100000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		
		vector<int> dist(m+1, INF);

		int highest = 0;

		for (int i = 1; i <= m; i++)
		{
			cin >> dist[i];
			highest += dist[i]; 
		}

		vector<vector<int>> dp(m+1, vector<int>(highest+1, INF));
		vector<vector<char>> moves(m+1, vector<char>(highest+1));

		dp[1][dist[1]] = dist[1];
		moves[1][dist[1]] = 'U';

		for (int i = 2; i <= m; i++)
		{
			for (int h = 0; h <= highest; h++)
			{
				if (dp[i-1][h] != INF)
				{
					if (dist[i] <= h)
					{
						if (dp[i-1][h] < dp[i][h - dist[i]])
						{
							dp[i][h - dist[i]] = dp[i-1][h];
							moves[i][h - dist[i]] = 'D';
						}
					}
					if (h + dist[i] <= highest)
					{
						int curr = max(h + dist[i], dp[i-1][h]);
						if (curr < dp[i][h + dist[i]])
						{
							dp[i][h + dist[i]] = curr;
							moves[i][h + dist[i]] = 'U';
						}
					}
				}
			}
		}

		if (dp[m][0] == INF)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			vector<char> v;

			int i = m;
			int h = 0;

			while (i >= 1 && h <= highest)
			{
				if (moves[i][h] == 'U')
				{
					h -= dist[i];
					v.push_back('U');
				}
				else
				{
					h += dist[i];
					v.push_back('D');
				}
				i--;
			}

			for (int i = v.size()-1; i >= 0; i--)
			{
				cout << v[i];
			}
			cout << endl;
		}
	}
}