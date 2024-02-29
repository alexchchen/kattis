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
    
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> m;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;

        if (i == n-1 && j != n+1)
        {
            cout << "Error" << endl;
            return 0;
        }
        
        m[j]++;
        q.push(j);
    }

    for (int i = 1; i <= n+1; i++)
    {
        if (m.find(i) == m.end())
        {
            pq.push(i);
        }
    }

    if (pq.empty())
    {
        cout << "Empty" << endl;
    }

    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        
        int j = pq.top();
        pq.pop();

        cout << j << endl;
        
        m[i]--;

        if (m[i] == 0)
        {
            pq.push(i);
        }
    }
}