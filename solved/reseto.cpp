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
    
    int n, k;
    cin >> n >> k;

    set<int> s;

    for (int i = 2; i <= n; i++)
    {
        s.insert(i);
    }

    int counter = 0;
    while (!s.empty())
    {
        int smallest = *s.begin();
        s.erase(smallest);
        counter++;
        if (counter == k)
        {
            cout << smallest << endl;
            return 0;
        }

        for (int i = smallest*2; i <= n; i += smallest)
        {
            if (s.count(i))
            {
                counter++;
                if (counter == k)
                {
                    cout << i << endl;
                    return 0;
                }
                s.erase(i);
            }
        }
    }
}