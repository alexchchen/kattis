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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	while (!(n == 0 && m == 0))
	{
		unordered_set<int> s;

		int total = 0;

		for (int i = 0; i < n; i++)
		{
			int j;
			cin >> j;
			s.insert(j);
		}

		for (int i = 0; i < n; i++)
		{
			int j;
			cin >> j;
			if (s.count(j))
				total++;
		}

		cout << total << endl;

		cin >> n >> m;
	}
}