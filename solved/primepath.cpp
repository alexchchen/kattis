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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool isPrime(int &n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool differByOneDigit(int a, int b)
{
    bool diff = false;
    while (a > 0 && b > 0)
    {
        if ((a % 10) != (b % 10))
        {
            if (!diff)
                diff = true;
            else
                return false;
        }
        a /= 10;
        b /= 10;
    }
    return diff;
}

void bfs(set<int> &s, map<int, set<int>> &m, map<int, int> &pred, int src, int dest)
{
    set<int> visited;
    queue<int> q;

    visited.insert(src);
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto i : m[u])
        {
            if (visited.find(i) == visited.end())
            {
                visited.insert(i);
                pred[i] = u;
                q.push(i);

                if (i == dest)
                    return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    set<int> s;
    map<int, set<int>> m;

    for (int i = 1001; i <= 9999; i += 2)
    {
        if (isPrime(i))
        {
            s.insert(i);
        }
    }

    for (auto i : s)
    {
        for (auto j : s)
        {
            if (differByOneDigit(i, j))
            {
                m[i].insert(j);
                m[j].insert(i);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        map<int, int> pred;
        bfs(s, m, pred, a, b);
        
        vector<int> path;
        int c = b;
        path.push_back(c);
        while (pred[c] != 0)
        {
            path.push_back(pred[c]);
            c = pred[c];
        }

        cout << path.size()-1 << endl;
    }
}