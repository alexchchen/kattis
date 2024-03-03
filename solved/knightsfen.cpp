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
#include <tuple>
#include <climits>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

void bfs(map<vector<vector<char>>, int> &m)
{
	queue<vector<vector<char>>> q;

	vector<vector<char>> startBoard =
	{
		{'1', '1', '1', '1', '1'},
		{'0', '1', '1', '1', '1'},
		{'0', '0', ' ', '1', '1'},
		{'0', '0', '0', '0', '1'},
		{'0', '0', '0', '0', '0'}
	};

	m[startBoard] = 0;

	q.push(startBoard);

	while (!q.empty())
	{
		auto board = q.front();
		q.pop();

		int i = 0;
		int j = 0;
        for (int x = 0; x < 5; x++)
		{
            for (int y = 0; y < 5; y++)
			{
                if (board[x][y] == ' ')
				{
                    i = x;
                	j = y;
                }
            }
        }

		if (m[board] == 10) break;
		
		auto newBoard = board;

		if (i - 2 >= 0)
		{
			if (j - 1 >= 0)
			{
				swap(newBoard[i][j], newBoard[i-2][j-1]);
				if (m.count(newBoard) == 0)
				{
					q.push(newBoard);
					m[newBoard] = m[board] + 1;
				}
				swap(newBoard[i][j], newBoard[i-2][j-1]);
			}
			if (j + 1 < 5)
			{
				swap(newBoard[i][j], newBoard[i-2][j+1]);
				if (m.count(newBoard) == 0)
				{
					q.push(newBoard);
					m[newBoard] = m[board] + 1;
				}
				swap(newBoard[i][j], newBoard[i-2][j+1]);
			}
		}
		if (j + 2 < 5)
		{
			if (i - 1 >= 0)
			{
				swap(newBoard[i][j], newBoard[i-1][j+2]);
				if (m.count(newBoard) == 0)
				{
					q.push(newBoard);
					m[newBoard] = m[board] + 1;
				}
				swap(newBoard[i][j], newBoard[i-1][j+2]);
			}
			if (i + 1 < 5)
			{
				swap(newBoard[i][j], newBoard[i+1][j+2]);
				if (m.count(newBoard) == 0)
				{
					q.push(newBoard);
					m[newBoard] = m[board] + 1;
				}
				swap(newBoard[i][j], newBoard[i+1][j+2]);
			} 
		}
		if (i + 2 < 5)
		{
			if (j - 1 >= 0)
			{
				swap(newBoard[i][j], newBoard[i+2][j-1]);
				if (m.count(newBoard) == 0)
				{
					q.push(newBoard);
					m[newBoard] = m[board] + 1;
				}
				swap(newBoard[i][j], newBoard[i+2][j-1]);
			}
			if (j + 1 < 5)
			{
				swap(newBoard[i][j], newBoard[i+2][j+1]);
				if (m.count(newBoard) == 0)
				{
					q.push(newBoard);
					m[newBoard] = m[board] + 1;
				}
				swap(newBoard[i][j], newBoard[i+2][j+1]);
			}
		}
		if (j - 2 >= 0)
		{
			if (i - 1 >= 0)
			{
				swap(newBoard[i][j], newBoard[i-1][j-2]);
				if (m.count(newBoard) == 0)
				{
					q.push(newBoard);
					m[newBoard] = m[board] + 1;
				}
				swap(newBoard[i][j], newBoard[i-1][j-2]);
			}
			if (i + 1 < 5)
			{
				swap(newBoard[i][j], newBoard[i+1][j-2]);
				if (m.count(newBoard) == 0)
				{
					q.push(newBoard);
					m[newBoard] = m[board] + 1;
				}
				swap(newBoard[i][j], newBoard[i+1][j-2]);
			} 
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	map<vector<vector<char>>, int> m;
	bfs(m);
    
    int N;
	cin >> N;
	cin.ignore();
	while (N--)
	{
		vector<vector<char>> board(5, vector<char>(5));

		for (int i = 0; i < 5; i++)
		{
			string line;
			getline(cin, line);
			for (int j = 0; j < 5; j++)
			{
				board[i][j] = line[j];
			}
		}

		if (m.count(board) > 0)
			cout << "Solvable in " << m[board] << " move(s)." << endl;
		else
			cout << "Unsolvable in less than 11 move(s)." << endl;
	}
}