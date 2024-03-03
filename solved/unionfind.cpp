#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <tuple>
#include <climits>
#include <functional>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const double pi = 3.14159265358979323846;

struct UF {
    vector<int> v;
    
    UF(int n) : v(n, -1) {}
    
    bool sameSet(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return -v[find(x)];
    }

    int find(int x) {
        if (v[x] < 0) {
            return x;
        } else {
            return v[x] = find(v[x]);
        }
    }

    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a == b) {
            return false;
        }

        if (v[a] > v[b]) {
            swap(a, b);
        }
        v[a] += v[b];
        v[b] = a;

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int N, Q;
    cin >> N >> Q;

    UF uf(N);

    for (int i = 0; i < Q; i++) {
        char operation;
        int a, b;
        cin >> operation >> a >> b;

        if (operation == '=') {
            uf.join(a, b);
        } else {
            if (uf.sameSet(a, b)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
}