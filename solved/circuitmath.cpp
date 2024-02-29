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
    
    int n;
    cin >> n;

    vector<int> v{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 
                  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
                  'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    unordered_map<char, bool> m;

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        
        if (c == 'T')
        {
            m[v[i]] = 1;
        }
        else
        {
            m[v[i]] = 0;
        }
    }

    stack<bool> s;
    
    string line;
    cin.ignore();
    getline(cin, line);
    stringstream ss(line);

    char c;
    while (ss >> c)
    {
        if (c == '*')
        {
            bool x, y, z;
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            z = x && y;
            s.push(z);
        }
        else if (c == '+')
        {
            bool x, y, z;
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            z = x || y;
            s.push(z);
        }
        else if (c == '-')
        {
            bool x, y;
            x = s.top();
            s.pop();
            y = !x;
            s.push(y);
        }
        else
        {
            s.push(m[c]);
        }
    }

    if (s.top())
    {
        cout << "T" << endl;
    }
    else
    {
        cout << "F" << endl;
    }
}