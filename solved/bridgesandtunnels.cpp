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

class UF {
private:
    vector<int> parent;
    vector<int> size;
    
public:
    UF(int n) {
        parent.assign(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        size.assign(n, 1);
    }
    
    void make_set(int v) {
        if (v < parent.size()) {
            parent[v] = v;
            size[v] = 1;
        } else {
            parent.push_back(v);
            size.push_back(1);
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    bool same_set(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int set_size(int v) {
        return size[v];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int n;
    cin >> n;

    int buildingNum = 0;

    UF uf(1);
    unordered_map<string, int> m;

    for (int i = 0; i < n; i++) {
        string b1, b2;
        cin >> b1 >> b2;

        if (!m.count(b1)) {
            m[b1] = buildingNum;
            uf.make_set(buildingNum);
            buildingNum++;
        }
        if (!m.count(b2)) {
            m[b2] = buildingNum;
            uf.make_set(buildingNum);
            buildingNum++;
        }

        uf.union_sets(m[b1], m[b2]);

        cout << uf.set_size(uf.find_set(m[b1])) << endl;
    }
}