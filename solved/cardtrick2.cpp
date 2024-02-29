#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <forward_list>

using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<int> v(n);

        int num = 1;
        int zeros = 1;
        int j = 0;
        while (num <= n)
        {
            
            
            if (zeros == 0 && v[j] == 0)
            {
                v[j] = num;
                num++;
                zeros = num;
            }
            else if (v[j] == 0)
            {
                zeros--;
            }

            if (j == n-1)
            {
                j = 0;
            }
            else 
            {
                j++;
            }
        }

        for (int k : v)
        {
            cout << k << " ";
        }

        cout << endl;
    }
}