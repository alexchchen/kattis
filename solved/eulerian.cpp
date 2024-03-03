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

	vector<vector<int>> inAdj(n+1);
	vector<vector<int>> outAdj(n+1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		outAdj[a].push_back(b);
		inAdj[b].push_back(a);
	}

	bool canWalk = true;
	bool startDetermined = false;
	bool endDetermined = false;
	int start, end;

	for (int i = 1; i <= n; i++)
	{
		int inEdges = inAdj[i].size();
		int outEdges = outAdj[i].size();
		if (inEdges != outEdges)
		{
			if ((outEdges == inEdges + 1) && !startDetermined)
			{
				start = i;
				startDetermined = true;
			}
			else if ((inEdges == outEdges + 1) && !endDetermined)
			{
				end = i;
				endDetermined = true;
			}
			else
			{
				canWalk = false;
				break;
			}
		}
	}

	if (!canWalk)
		cout << "no" << endl;
	else if (startDetermined && endDetermined)
		cout << start << " " << end << endl;
	else
		cout << "anywhere" << endl;
}