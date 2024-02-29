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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    stack<char> s;

    string line;
    cin.ignore();
    getline(cin, line);

    for (int i = 0; i < n; i++)
    {
        if (line[i] == '(')
        {
            s.push('(');
        }
        else if (line[i] == '[')
        {
            s.push('[');
        }
        else if (line[i] == '{')
        {
            s.push('{');
        }
        else if (line[i] == ')' && s.size() > 0 && s.top() == '(')
        {
            s.pop();
        }
        else if (line[i] == ']' && s.size() > 0 && s.top() == '[')
        {
            s.pop();
        }
        else if (line[i] == '}' && s.size() > 0 && s.top() == '{')
        {
            s.pop();
        }
        else if (line[i] == ' ')
        {
            continue;
        }
        else
        {
            cout << line[i] << " " << i << endl;
            return 0;
        }
    }
    cout << "ok so far" << endl;
}