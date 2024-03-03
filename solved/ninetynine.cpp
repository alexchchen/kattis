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
#include <functional>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const double pi = 3.14159265358979323846;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int myAnswer = 2;
    cout << myAnswer << endl;

    while (myAnswer < 99) {
        int enemyAnswer;
        cin >> enemyAnswer;

        if (enemyAnswer % 3 == 0) {
            myAnswer = enemyAnswer + 1;
        } else if (enemyAnswer % 3 == 1) {
            myAnswer = enemyAnswer + 2;
        } else {
            myAnswer = enemyAnswer + 1;
        }

        cout << myAnswer << endl;
    }
}