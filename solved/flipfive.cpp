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
#include <functional>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int bfs(vector<vector<bool>> &dest)
{
    vector<vector<bool>> start = 
    {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    set<vector<vector<bool>>> visited;

    map<vector<vector<bool>>, int> m;

    queue<vector<vector<bool>>> q;

    q.push(start);
    m[start] = 0;

    while (!q.empty())
    {
        vector<vector<bool>> grid = q.front();
        q.pop();

        if (visited.count(grid)) continue;

        visited.insert(grid);

        if (grid == dest) break;

        vector<vector<bool>> newGrid = grid;
        newGrid[0][0] = !grid[0][0];
        newGrid[0][1] = !grid[0][1];
        newGrid[1][0] = !grid[1][0];
        q.push(newGrid);
        m[newGrid] = m[grid] + 1;

        newGrid = grid;
        newGrid[0][0] = !grid[0][0];
        newGrid[0][1] = !grid[0][1];
        newGrid[0][2] = !grid[0][2];
        newGrid[1][1] = !grid[1][1];
        q.push(newGrid);
        m[newGrid] = m[grid] + 1;

        newGrid = grid;
        newGrid[0][1] = !grid[0][1];
        newGrid[0][2] = !grid[0][2];
        newGrid[1][2] = !grid[1][2];
        q.push(newGrid);
        m[newGrid] = m[grid] + 1;

        newGrid = grid;
        newGrid[0][0] = !grid[0][0];
        newGrid[1][0] = !grid[1][0];
        newGrid[2][0] = !grid[2][0];
        newGrid[1][1] = !grid[1][1];
        q.push(newGrid);
        m[newGrid] = m[grid] + 1;

        newGrid = grid;
        newGrid[0][1] = !grid[0][1];
        newGrid[1][0] = !grid[1][0];
        newGrid[1][1] = !grid[1][1];
        newGrid[1][2] = !grid[1][2];
        newGrid[2][1] = !grid[2][1];
        q.push(newGrid);
        m[newGrid] = m[grid] + 1;

        newGrid = grid;
        newGrid[0][2] = !grid[0][2];
        newGrid[1][1] = !grid[1][1];
        newGrid[1][2] = !grid[1][2];
        newGrid[2][2] = !grid[2][2];
        q.push(newGrid);
        m[newGrid] = m[grid] + 1;

        newGrid = grid;
        newGrid[1][0] = !grid[1][0];
        newGrid[2][0] = !grid[2][0];
        newGrid[2][1] = !grid[2][1];
        q.push(newGrid);
        m[newGrid] = m[grid] + 1;

        newGrid = grid;
        newGrid[1][1] = !grid[1][1];
        newGrid[2][0] = !grid[2][0];
        newGrid[2][1] = !grid[2][1];
        newGrid[2][2] = !grid[2][2];
        q.push(newGrid);
        m[newGrid] = m[grid] + 1;

        newGrid = grid;
        newGrid[1][2] = !grid[1][2];
        newGrid[2][1] = !grid[2][1];
        newGrid[2][2] = !grid[2][2];
        q.push(newGrid);
        m[newGrid] = m[grid] + 1;
    }

    return m[dest];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int P;
    cin >> P;
    cin.ignore();
    while (P--)
    {
        vector<vector<bool>> grid(3, vector<bool>(3));

        for (int i = 0; i < 3; i++)
        {
            string line;
            getline(cin, line);
            for (int j = 0; j < 3; j++)
            {
                if (line[j] == '*')
                    grid[i][j] = 1;
                else if (line[j] == '.')
                    grid[i][j] = 0;
            }
        }

        cout << bfs(grid) << endl;
    }
}