#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<string> in_names;
    vector<string> out_names;
    int set_n = 1;

    string output = "";

    cin >> n;
    while (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;
            in_names.push_back(name);
        }

        for (int i = 0; i < n; i += 2)
        {
            string name = in_names[i];
            out_names.push_back(name);
        }

        int j;
        if (n % 2 == 0)
            j = n - 1;
        else
            j = n - 2;

        for (j; j > 0; j -= 2)
        {
            string name = in_names[j];
            out_names.push_back(name);
        }

        output.append(string("SET ") + to_string(set_n) + "\n");
        for (int i = 0; i < n; i++)
        {
            string name = out_names[i];
            output.append(name + "\n");
        }

        set_n++;
        in_names.clear();
        out_names.clear();
        cin >> n;
    }
    cout << output;
}