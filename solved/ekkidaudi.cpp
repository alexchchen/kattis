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
   
    string line;
    getline(cin, line);

    int pos = line.find("|");
    string first = line.substr(0, pos);
    string second = line.erase(0, pos+1);

    getline(cin, line);

    pos = line.find("|");
    first += line.substr(0, pos);
    second += line.erase(0, pos+1);

    cout << first << " " << second;
}