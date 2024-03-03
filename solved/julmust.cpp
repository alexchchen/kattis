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

    int R;
    cin >> R;

    int low = 1;
    int high = R;
    int guess;

    string response;
    
    int day = 1;
    while (response != "exact") {

        guess = (low + high) / 2;

        cout << guess * day << endl;

        cin >> response;

        if (response == "less") {
            high = guess - 1;
        } else {
            low = guess + 1;
        }

        day++;
    }
}