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
    string line;
    vector<string> v(8, "");
    unordered_map<string, int> numbers = {
        {"**** ** ** ****", 0},
        {"  *  *  *  *  *", 1},
        {"***  *****  ***", 2},
        {"***  ****  ****", 3},
        {"* ** ****  *  *", 4},
        {"****  ***  ****", 5},
        {"****  **** ****", 6},
        {"***  *  *  *  *", 7},
        {"**** ***** ****", 8},
        {"**** ****  ****", 9},
    };

    int n;

    for (int i = 0; i < 5; i++)
    {
        getline(cin, line);
        n = line.length() / 4 + 1;

        for (int j = 0; j < n; j++)
        {
            v[j] += line.substr(j * 4, 3);
        }
    }

    int num = 0;
    int place = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (numbers.find(v[i]) == numbers.end())
        {
            cout << "BOOM!!" << endl;
            return 0;
        }
        num += numbers[v[i]] * place;
        place *= 10;
    }

    if (num % 6 == 0)
    {
        cout << "BEER!!" << endl;
    }
    else
    {
        cout << "BOOM!!" << endl;
    }
}