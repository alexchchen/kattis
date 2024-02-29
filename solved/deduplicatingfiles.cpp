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
    while ((cin >> n) && n != 0)
    {
        unordered_set<string> lines;
        unordered_map<int, vector<string>> m;

        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            string line;    
            getline(cin, line);
            lines.insert(line);

            int hash = 0;
            for (auto c : line)
            {
                hash ^= c;
            }

            m[hash].emplace_back(line);
        }

        int collisions = 0;
        for (auto p : m)
        {
            vector<string> v = p.second;
            if (v.size() > 1)
            {
                for (int i = 0; i < v.size()-1; i++)
                {
                    for (int j = i+1; j < v.size(); j++)
                    {
                        if (v[i] != v[j])
                        {
                            collisions++;
                        }
                    }
                }
            }
        }

        cout << lines.size() << " " << collisions << endl;
    }
}