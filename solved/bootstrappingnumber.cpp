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
    double n;
    cin >> n;

    double min = 1;
    double max = 10;
    double mid;

    while (abs(max - min) > 0.0000001)
    {
        mid = (max + min) / 2;

        double result = pow(mid, mid);

        if (result == n)
        {
            break;
        }
        else if (result < n)
        {
            min = mid;
        }
        else
        {
            max = mid;
        }
    }

    printf("%f", mid);
}