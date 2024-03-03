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

	ll s, p, m, n;
	cin >> s >> p >> m >> n;

	vector<ll> trips(n+1);

	for (ll i = 1; i <= n; i++)
		cin >> trips[i];

	vector<ll> opt(n+1);

	for (int i = 1; i <= n; i++)
	{
		int j = i;
		while (j > 0 && trips[j] > trips[i] - m) j--;
		opt[i] = min(s + opt[i-1], p + opt[j]);
	}

	cout << opt[n] << endl;
}