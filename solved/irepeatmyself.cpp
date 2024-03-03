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

	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		int l = s.size();
		
		for (int j = 1; j <= l; j++) {
			string p = s.substr(0, j);
			string str = "";

			for (int k = 0; k < (l/p.size() + 1); k++) {
				str += p;
			}
			str.resize(l);

			if (str == s) {
				cout << p.size() << endl;
				break;
			}
		}
	}
}