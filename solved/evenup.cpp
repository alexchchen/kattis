#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> cards;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        cards.push_back(j);
    }

    int i = 0;
    int num_cards = cards.size() - 1;
    while (i < num_cards)
    {
        int card1 = cards[i];
        int card2 = cards[i + 1];
        if ((card1 + card2) % 2 == 0)
        {
            cards.erase(cards.begin() + i);
            cards.erase(cards.begin() + i);
            i = -1;
        }
        i++;
        num_cards = cards.size() - 1;
    }

    cout << cards.size();
}