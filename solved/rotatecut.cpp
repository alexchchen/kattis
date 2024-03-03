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

	int cases;
	cin >> cases;

	while (cases--) {
		int n;
		string sentence;
		cin >> n >> sentence;

		for (int i = 1; i <= n; i++) {
			int cut_size = sentence.size() / 4;

			if (cut_size == 0) break;

			if (i % 2 == 1) {
				sentence = sentence.substr(cut_size, sentence.size()-cut_size);
			} else {
				sentence = sentence.substr(0, sentence.size()-cut_size);
			}
		}
		cout << sentence << endl;
	}
}