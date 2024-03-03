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

	int a, b;
	cin >> a >> b;

	int ar = 0, br = 0;
	int x = 100;
	for (int i = 0; i < 3; i++) {
		ar += (a % 10) * x;
		br += (b % 10) * x;
		a /= 10;
		b /= 10;
		x /= 10;
	}
	
	if (ar > br) {
		cout << ar << endl;
	} else {
		cout << br << endl;
	}
}