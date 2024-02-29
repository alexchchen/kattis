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

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        int sCount = 0;
        int qCount = 0;
        int pqCount = 0;

        for (int i = 0; i < n; i++)
        {
            int o, x;
            cin >> o >> x;

            if (o == 1)
            {
                s.push(x);
                q.push(x);
                pq.push(x);

                sCount++;
                qCount++;
                pqCount++;
            }
            else
            {
                if (!s.empty() && s.top() == x)
                {
                    s.pop();
                    sCount++;
                }
                if (!q.empty() && q.front() == x)
                {
                    q.pop();
                    qCount++;
                }
                if (!pq.empty() && pq.top() == x)
                {
                    pq.pop();
                    pqCount++;
                }
            }
        }

        if (!(sCount == n || qCount == n || pqCount == n))
        {
            cout << "impossible" << endl;
        }
        else if ((sCount == n && qCount == n) || (sCount == n && pqCount == n) || (qCount == n && pqCount == n))
        {
            cout << "not sure" << endl;
        }
        else if (sCount == n)
        {
            cout << "stack" << endl;
        }
        else if (qCount == n)
        {
            cout << "queue" << endl;
        }
        else
        {
            cout << "priority queue" << endl;
        }
    }
}