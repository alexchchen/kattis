#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<string> words;
    bool repeat = false;

    string word;
    while (cin >> word)
    {
        if (words.count(word) == 0)
            words.insert(word);
        else
        {
            repeat = true;
            break;
        }
    }

    if (repeat)
        cout << "no";
    else
        cout << "yes";
}