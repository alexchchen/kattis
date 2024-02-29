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
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        string p;
        int n;
        cin >> p;
        cin >> n;

        deque<int> d;
        cin.ignore();
        for (int j = 0; j < n; j++)
        {
            int k;
            cin.ignore();
            cin >> k;
            d.push_back(k);
        }
        cin.ignore();
        if (n == 0)
            cin.ignore();

        bool error = false;
        bool reverse = false;

        for (char c : p)
        {
            if (c == 'R')
            {
                reverse = !reverse;
            }
            else if (c == 'D' && d.empty())
            {
                error = true;
            }
            else if (c == 'D')
            {
                if (reverse)
                {
                    d.pop_back();
                }
                else
                {
                    d.pop_front();
                }
            }
        }

        if (error)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << "[";
            while (!d.empty())
            {
                if (reverse)
                {
                    cout << d.back();
                    d.pop_back();
                }
                else
                {
                    cout << d.front();
                    d.pop_front();
                }

                if (d.size() != 0)
                {
                    cout << ",";
                }
            }
            cout << "]" << endl;
        }
    }
}