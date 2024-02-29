#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    long long n, d;
    cin >> n >> d;

    unordered_map<long long, long long> m;

    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        m[a / d]++;
    }

    long long total = 0;

    for (auto p : m)
    {
        long long indices = p.second;

        total += indices * (indices - 1) / 2;
    }

    cout << total << endl;
}