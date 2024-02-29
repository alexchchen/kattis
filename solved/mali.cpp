#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

#define ll long long

using namespace std;

int findMaxSum(vector<int> v1, vector<int> v2)
{
    int i = 1;
    int j = 100;
    int sum = 0;

    while (i <= 100 && j >= 1)
    {
        while (v1[i] == 0)
            i++;

        while (v2[j] == 0)
            j--;

        if (i > 100 || j < 1)
            break;
        
        sum = max(i+j, sum);

        int m = min(v1[i], v2[j]);
        v1[i] -= m;
        v2[j] -= m;
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> v1(101);
    vector<int> v2(101);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        v1[a]++;
        v2[b]++;

        int sum = findMaxSum(v1, v2);

        cout << sum << endl;
    }
}