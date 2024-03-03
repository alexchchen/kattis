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
	string founder;
	cin >> n >> m >> founder;

	unordered_map<string, ll> blood;
	unordered_map<string, unordered_set<string>> adj;

	for (int i = 0; i < n; i++) {
		string child, parent1, parent2;
		cin >> child >> parent1 >> parent2;
		adj[parent1].insert(child);
		adj[parent2].insert(child);
	}

	queue<pair<string, ll>> q;
	q.push({founder, (ll) 1 << 55});

	while (!q.empty()) {
		auto p = q.front();
		string person = p.first;
		ll blood_value = p.second;
		q.pop();

		blood[person] += blood_value;

		for (auto &child : adj[person]) {
			q.push({child, blood_value / 2});
		}
	}

	string heir = "";
	ll max_blood = 0;

	for (int i = 0; i < m; i++) {
		string claimant;
		cin >> claimant;
		if (blood[claimant] > max_blood) {
			heir = claimant;
			max_blood = blood[claimant];
		}
	}

	cout << heir << endl;
}