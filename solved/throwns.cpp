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
    
    int n, k;
    cin >> n >> k;

    int curr = 0;

    stack<int> s;

    for (int i = 0; i < k; i++)
    {
        string word;
        cin >> word;
        if (word == "undo")
        {
            int undoAmount;
            cin >> undoAmount;

            for (int j = 0; j < undoAmount; j++)
            {
                int t = s.top();
                s.pop();
                if (curr - t > n-1)
                {
                    int r = n-1 - curr;
                    t += r+1;
                    curr = 0;
                    curr -= t;
                }
                else if (curr - t < 0)
                {
                    int r = curr;
                    t -= r+1;
                    curr = n-1;
                    curr -= t;
                }
                else
                {
                    curr -= t;
                }
            }
        }
        else
        {
            int t = stoi(word);
            t %= n;
            s.push(t);
            if (curr + t > n-1)
            {
                int r = n-1 - curr;
                t -= r+1;
                curr = 0;
                curr += t;
            }
            else if (curr + t < 0)
            {
                int r = curr;
                t += r+1;
                curr = n-1;
                curr += t;
            }
            else
            {
                curr += t;
            }
        }
    }

    cout << curr << endl;
}