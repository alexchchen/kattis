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

    while(cin >> n && n != 0)
    {
        int pile1 = 0;
        int pile2 = 0;
        for (int i = 0; i < n; i++)
        {
            string operation;
            int m;
            cin >> operation >> m;
            
            if (operation == "DROP")
            {
                pile2 += m;
                cout << "DROP 2 " << m << endl;
            }
            else
            {
                if (pile1 >= m)
                {
                    pile1 -= m;
                    cout << "TAKE 1 " << m << endl;
                }
                else
                {
                    if (pile1 > 0)
                    {
                        m -= pile1;
                        cout << "TAKE 1 " << pile1 << endl;
                        pile1 -= pile1;
                    }
                    pile1 += pile2;
                    cout << "MOVE 2->1 " << pile2 << endl;
                    pile2 -= pile2;
                    pile1 -= m;
                    cout << "TAKE 1 " << m << endl;
                }
            }
        }
        cout << endl;
    }
}