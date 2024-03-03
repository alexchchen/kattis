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

const double pi = 3.14159265358979323846;

void dfs(vector<vector<bool>> &visited, vector<vector<char>> &planet, int r, int c, int i, int j)
{
    if (visited[i][j]) return;

    visited[i][j] = true;

    if (i-1 >= 0)
    {
        if (planet[i-1][j] == 'L' || planet[i-1][j] == 'C')
            dfs(visited, planet, r, c, i-1, j);
    }
    if (i+1 < r)
    {
        if (planet[i+1][j] == 'L' || planet[i+1][j] == 'C')
            dfs(visited, planet, r, c, i+1, j);
    }
    if (j-1 >= 0)
    {
        if (planet[i][j-1] == 'L' || planet[i][j-1] == 'C')
            dfs(visited, planet, r, c, i, j-1);
    }
    if (j+1 < c)
    {
        if (planet[i][j+1] == 'L' || planet[i][j+1] == 'C')
            dfs(visited, planet, r, c, i, j+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int r, c;
    cin >> r >> c;
    cin.ignore();

    vector<vector<char>> planet(r, vector<char>(c));

    for (int i = 0; i < r; i++)
    {
        string line;
        getline(cin, line);
        for (int j = 0; j < c; j++)
        {
            planet[i][j] = line[j];
        }
    }

    vector<vector<bool>> visited(r, vector<bool>(c));
    int islands = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (planet[i][j] == 'L' && !visited[i][j])
            {
                dfs(visited, planet, r, c, i, j);
                islands++;
            }
        }
    }

    cout << islands << endl;
}