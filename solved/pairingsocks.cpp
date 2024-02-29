#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> original_pile; // top of pile is at front
    deque<int> aux_pile;      // top of pile is at back

    int moves = 0;

    int n;

    cin >> n;

    for (int i = 0; i < 2 * n; i++)
    {
        int j;
        cin >> j;
        original_pile.push_back(j);
    }

    int sock = original_pile.front();
    aux_pile.push_back(sock);
    original_pile.pop_front();
    moves++;

    while (!original_pile.empty())
    {
        if (aux_pile.empty())
        {
            sock = original_pile.front();
            aux_pile.push_back(sock);
            original_pile.pop_front();
            moves++;
        }

        if (original_pile.front() == aux_pile.back())
        {
            original_pile.pop_front();
            aux_pile.pop_back();
            moves++;
            continue;
        }

        sock = original_pile.front();
        aux_pile.push_back(sock);
        original_pile.pop_front();
        moves++;
    }

    if (!aux_pile.empty())
    {
        sock = aux_pile.back();
        original_pile.push_front(sock);
        aux_pile.pop_back();
        moves++;
    }
    while (!aux_pile.empty())
    {
        if (original_pile.front() == aux_pile.back())
        {
            original_pile.pop_front();
            aux_pile.pop_back();
            moves++;
        }

        sock = aux_pile.back();
        original_pile.push_front(sock);
        aux_pile.pop_back();
        moves++;
    }

    if (original_pile.empty())
    {
        printf("%d\n", moves);
    }
    else
    {
        printf("impossible\n");
    }

    return 0;
}