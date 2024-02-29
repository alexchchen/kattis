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
    cin.ignore();

    while (t--)
    {
        list<char> l;
        
        string line;
        getline(cin, line);

        auto curr = l.begin();

        for (char c : line)
        {
            if (c == '[')
            {
                curr = l.begin();
            }
            else if (c == ']')
            {
                curr = l.end();
            }
            else if (c == '<')
            {
                if (curr != l.begin())
                {
                    curr--;
                    curr = l.erase(curr);
                }
            }
            else
            {
                curr = l.insert(curr, c);
                curr++;
            }
        }

        for (char c : l)
        {
            cout << c;
        }

        cout << endl;
    }
}