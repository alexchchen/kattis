#include <iostream>

using namespace std;

void guess(int lower, int upper)
{
    int mid = (lower + upper) / 2;

    bool found = false;

    while (!found)
    {
        cout << mid << endl;

        string response;
        cin >> response;

        if (response == "lower")
        {
            upper = mid-1;
            mid = (lower + upper) / 2;
        }
        else if (response == "higher")
        {
            lower = mid+1;
            mid = (lower + upper) / 2;
        }
        else
        {
            found = true;
        }
    }
}

int main()
{
    int lower = 1;
    int upper = 1000;

    guess(lower, upper);

    return 0;
}