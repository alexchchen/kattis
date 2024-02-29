#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int main()
{
    int w, l;
    cin >> w >> l;

    vector<string> v(20);

    int n = 1;

    while (!(w == 0 && l == 0))
    {
        string line;
        getline(cin, line);
        for (int i = 0; i < l; i++)
        {
            getline(cin, line);
            v[i] = line;
        }

        int x, y;

        for (int i = 0; i < w; i++)
        {
            if (v[0][i] == '*')
            {
                y = 0;
                x = i;
            }

            if (v[l - 1][i] == '*')
            {
                y = l - 1;
                x = i;
            }
        }

        for (int i = 0; i < l; i++)
        {
            if (v[i][0] == '*')
            {
                y = i;
                x = 0;
            }

            if (v[i][w - 1] == '*')
            {
                y = i;
                x = w - 1;
            }
        }

        char dir;

        if (y == 0)
        {
            dir = 'S';
        }
        else if (y == l - 1)
        {
            dir = 'N';
        }
        else if (x == 0)
        {
            dir = 'E';
        }
        else
        {
            dir = 'W';
        }

        while (v[y][x] != 'x')
        {
            if (dir == 'N')
            {
                y--;
            }
            else if (dir == 'E')
            {
                x++;
            }
            else if (dir == 'S')
            {
                y++;
            }
            else
            {
                x--;
            }

            if (v[y][x] == '/')
            {
                if (dir == 'N')
                {
                    dir = 'E';
                }
                else if (dir == 'E')
                {
                    dir = 'N';
                }
                else if (dir == 'S')
                {
                    dir = 'W';
                }
                else
                {
                    dir = 'S';
                }
            }
            else if (v[y][x] == '\\')
            {
                if (dir == 'N')
                {
                    dir = 'W';
                }
                else if (dir == 'E')
                {
                    dir = 'S';
                }
                else if (dir == 'S')
                {
                    dir = 'E';
                }
                else
                {
                    dir = 'N';
                }
            }
        }

        v[y][x] = '&';

        cout << "HOUSE " << n << endl;
        n++;

        for (int i = 0; i < l; i++)
        {
            cout << v[i] << endl;
        }

        cin >> w >> l;
    }
}