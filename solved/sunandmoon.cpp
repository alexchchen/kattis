#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    int ds, ys, dm, ym, currYear;

    cin >> ds >> ys >> dm >> ym;

    currYear = ys - ds;
    if ((dm + currYear) % ym == 0)
    {
        cout << currYear << endl;
    }
    else
    {
        bool found = false;
        while (!found)
        {
            currYear += ys;
            if ((dm + currYear) % ym == 0)
            {
                cout << currYear << endl;
                found = true;
            }
        }
    }
}