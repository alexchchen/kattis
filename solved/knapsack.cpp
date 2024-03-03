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

void knapsack(int n, int C, vector<pair<int, int>> &items)
{
	vector<vector<int>> A(n+1, vector<int>(C+1));

	for (int i = 1; i <= n; i++)
	{
		int vi = items[i].first;
		int wi = items[i].second;

		for (int w = 1; w <= C; w++)
		{
			if (wi > w)
			{
				A[i][w] = A[i-1][w];
			}
			else
			{
				A[i][w] = max(vi + A[i-1][w-wi], A[i-1][w]);
			}
		}
	}

	vector<int> chosen;
	int i = n;
	int w = C;
	while (i > 0 && w > 0)
	{
		int vi = items[i].first;
		int wi = items[i].second;

		if (A[i][w] == vi + A[i-1][w-wi])
		{
			chosen.push_back(i);
			i = i-1;
			w = w-wi;
		}
		else
		{
			i = i-1;
		}
	}

	cout << chosen.size() << endl;
	for (int i : chosen)
		cout << i-1 << " ";
	cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int C, n;
	while (cin >> C)
	{
		cin >> n;
		
		vector<pair<int, int>> items(n+1);

		for (int i = 1; i <= n; i++)
		{
			int v, w;
			cin >> v >> w;
			items[i] = make_pair(v, w);
		}

		knapsack(n, C, items);
	}
}