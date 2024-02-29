#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> set;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        set.insert(j);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int j;
        cin >> j;
        if (!(set.find(j) == set.end()))
        {
            set.erase(j);
        }
    }

    cout << *(set.begin()) << endl;
}