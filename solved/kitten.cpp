#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
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

void bfs(vector<vector<int>> &v, vector<int> &pred, int src, int dest)
{
    vector<bool> visited(v.size());
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < v[u].size(); i++)
        {
            if (visited[v[u][i]] == false)
            {
                visited[v[u][i]] = true;
                pred[v[u][i]] = u;
                q.push(v[u][i]);

                if (v[u][i] == dest)
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
    
    int k;
    cin >> k;
    cin.ignore();

    vector<vector<int>> v(101);

    int root;
    bool first = true;

    while (true)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int n;
        ss >> n;

        if (n == -1)
            break;

        if (first)
        {
            root = n;
            first = false;
        }

        int i;
        while (ss >> i)
        {
            v[n].push_back(i);
            v[i].push_back(n);
        }
    }

    vector<int> pred(v.size());
    
    bfs(v, pred, root, k);

    vector<int> path;
    int crawl = k;
    path.push_back(crawl);
    while (pred[crawl] != 0)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    for (int i : path)
    {
        cout << i << " ";
    }
}