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
    
    string line;
    getline(cin, line);
    stringstream ss(line);

    int h;
    ss >> h;

    string path;

    long long pos = 1;

    if (ss >> path)
    {
        for (char c : path)
        {
            if (c == 'L')
            {
                pos = pos * 2;
            }
            else
            {
                pos = pos * 2 + 1;
            }
        }        
    }

    pos = pow(2, h+1) - pos;
    cout << pos << endl;
}