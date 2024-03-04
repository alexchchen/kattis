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

/**
 * Union-find disjoint set data struture
 */
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

/**
 * Union-find disjoint set data struture
 */
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

/**
 * Breadth-First Search
 * Traversal of a graph by visiting all adjacent vertices first.
 * 
 * @param adj Adjacency list representation of the graph.
 * @param pred Vector that stores the predecessor of each vertex that was visited. (Should be initialized with 0 or -1)
 * @param src Source vertex to begin the search at.
 * @param dest Destination vertex to end the search at.
 */
void bfs(vector<vector<int>> &adj, vector<int> &pred, int src, int dest)
{
    // Keep track of visited vertices so that we do not visit them again
    vector<bool> visited(adj.size());
    
    // Uses a queue so that we visit adjacent vertices that were discovered first
    queue<int> q;

    // Visit the source vertex
    visited[src] = true;
    q.push(src);

    // Traverse until all vertices are visited
    while (!q.empty())
    {
        // Visit the vertex at the front of the queue
        int u = q.front();
        q.pop();

        // For every adjacent vertex to u
        for (int i = 0; i < adj[u].size(); i++)
        {
            // Add the vertex to the queue if it hasn't been visited already
            if (visited[adj[u][i]] == false)
            {
                visited[adj[u][i]] = true;
                pred[adj[u][i]] = u;
                q.push(adj[u][i]);

                // Stop the algorithm when the destination vertex has been reached
                if (adj[u][i] == dest)
                    return;
            }
        }
    }
}

/**
 * BFS Path
 * Given the predecessor array from performing BFS,
 * gets the path taken by that BFS to the vertex of interest.
 * 
 * @param pred The predecessor array after performing BFS.
 * @param v The vertex of interest.
 */
vector<int> bfs_path(vector<int> &pred, int v)
{
    vector<int> path;

    // Start at the vertex of interest
    path.push_back(v);

    // Traverse backwards until there is no more predecessors
    while (pred[v] != 0) // Either 0 or -1, depending on how pred is initialized
    {
        // Add the predecessor to the path
        path.push_back(pred[v]);
        v = pred[v];
    }

    return path;
}

/**
 * Depth First Search (recursive)
 * Traversal of a graph by going as deep as possible first.
 *
 * @param adj Adjacency list representation of the graph.
 * @param visited Array that keeps track of visited vertices.
 * @param u Vertex to search at.
 */
void recursive_dfs(vector<vector<int>> &adj, vector<bool> &visited, int u)
{
    // Vertex already visited
    if (visited[u]) return;

    // Otherwise visit this vertex
    visited[u] = true;

    // Continue DFS on adjacent vertices
    for (auto v : adj[u])
    {
        if (!visited[v])
            recursive_dfs(adj, visited, v);
    }
}

/**
 * Depth First Search (iterative)
 * Traversal of a graph by going as deep as possible first.
 *
 * @param adj Adjacency list representation of the graph.
 * @param src Source vertex to begin search at.
 */
void iterative_dfs(vector<vector<int>> &adj, int src)
{
    // Keep track of visited vertices
    vector<bool> visited(adj.size());

    // Uses a stack to visit vertices in depth first fashion
    stack<int> s;

    // Visit source vertex
    s.push(src);

    // Traverse until all vertices are visited
    while (!s.empty())
    {
        // Visit the vertex at the top of the stack
        int u = s.top();
        s.pop();

        // Skip if this vertex is already visited
        if (visited[u]) continue;

        // Otherwise we set this vertex as visited
        visited[u] = true;

        // Continue DFS on adjacent vertices
        for (auto v : adj[u])
        {
            if (!visited[v])
                s.push(v);
        }
    }
}

/**
 * Dijkstra's Algorithm
 * Starting from a source vertex, finds the minimum cost path to every other vertex in a graph.
 * Only works for non-negative weights.
 * 
 * @param adj Adjacency list representation of the graph.
 * @param dist Vector that stores minimum cost path to each vertex. 
 *             Should be initialized with INFINITY (arbitrary large value).
 * @param src Source vertex to start at.
 */ 
void dijkstra(vector<vector<pair<int, int>>> &adj, vector<int> &dist, int src)
{
    // Minheap priority queue to get minimum cost edge
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with source vertex
    pq.push(make_pair(0, src));
    dist[src] = 0;

    // Perform algorithm until all vertices are visited
    while (!pq.empty())
    {
        // Get vertex with minimum cost edge from priority queue
        int u = pq.top().second;
        pq.pop();

        // For every adjacent edge
        for (auto e : adj[u])
        {
            // Edge connects to vertex v with weight w
            int v = e.first;
            int w = e.second;

            // If the cost of going through vertex u to get to vertex v is
            // smaller than the minimum cost path of vertex v,
            // then it is the new minimum cost path of vertex v
            if (dist[u] + w < dist[v])
            {
                // Update the minimum cost path of vertex v and add vertex v to be visited
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

/**
 * Prim's Algorithm 
 * Finds the sum of the weights of a minimum spanning tree in a graph.
 * 
 * @param adj Adjacency list representation of the graph.
 * @return Sum of the weights of the edges in a minimum spanning tree of the graph.
 */
double prim(vector<vector<pair<int, double>>> &adj)
{
    // Uses a minheap priority queue to get the edge with minimal cost
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    // Keep track of visited vertices, so that they are not visited again
    vector<bool> visited(adj.size(), false);

    // The sum of the weights to be returned
    double sum = 0;

    // Start with vertex 0
    pq.push(make_pair(0, 0));

    // Perform algorithm until all vertices are visited
    while (!pq.empty())
    {
        // Get minimal cost edge
        auto p = pq.top();
        pq.pop();

        // Edge is connected to vertex u with weight wu
        int u = p.second;
        double wu = p.first;

        // Skip if u is already visited
        if (visited[u]) continue;

        // Add the edge to the MST and mark the vertex as visited
        sum += wu;
        visited[u] = true;

        // Add adjacent edges and vertices to be visited
        for (auto e : adj[u])
        {
            int v = e.first;
            double wv = e.second;
            
            if (!visited[v])
                pq.push(make_pair(wv, v));
        }
    }

    return sum;
}

/**
 * Bellman-Ford Algorithm
 * Starting from a source vertex, finds the minimum cost path to every other vertex in a graph.
 * Works with negative weights and can detect negative cycles.
 * 
 * @param adj Adjacency list representation of the graph.
 * @param dist Vector that stores minimum cost path to each vertex. 
 *             Should be initialized with INFINITY (arbitrary large value, like 1000000000).
 * @param src Source vertex to start at.
 */
void bellman_ford(vector<vector<pair<int, int>>> &adj, vector<int> &dist, int &src)
{
    // Large value to represent infinity
    int inf = 1000000000;

    // Shortest path to the source vertex is 0
    dist[src] = 0;

    // Relax edges n-1 times, where n is the number of vertices
    for (int i = 0; i < adj.size() - 1; i++)
    {
        // For every vertex u
        for (int u = 0; u < adj.size(); u++)
        {
            // If u is reachable from the source
            if (dist[u] != inf)
            {
                // Loop through vertices v adjacent to u
                for (auto e : adj[u])
                {
                    int v = e.first;
                    int w = e.second;
                    
                    // If the path through u to get to v is smaller than
                    // the current path to v, then update the distance 
                    dist[v] = min(dist[v], dist[u] + w);
                }
            }
        }
    }

    // If we relax all the edges once more and the shortest distance for a vertex
    // decreases, then a negative cycle is present.
    // Relaxing all the edges n-1 times again will include negative cycles in 
    // the shortest distance for all vertices.
    for (int i = 0; i < adj.size() - 1; i++)
    {
        for (int u = 0; u < adj.size(); u++)
        {
            if (dist[u] != inf)
            {
                for (auto e : adj[u])
                {
                    int v = e.first;
                    int w = e.second;

                    // Shortest distance to v is decreased, 
                    // marked as -infinity to indicate negative cycle
                    if (dist[v] > dist[u] + w)
                        dist[v] = -inf;
                }
            }
        }
    }
}

/**
 * Shoelace Formula
 * Finds the area of a polygon, given its vertices in counterclockwise order.
 * 
 * @param points The vertices of the polygon in (x, y) form.
 * @return The area of the polygon.
 */
double shoelace(vector<pair<int, int>> &points)
{
    double total = 0;
    
    int n = points.size();

    for (int i = 0; i < n-1; i++)
    {
        int x1 = points[i].first;
        int y1 = points[i].second;
        int x2 = points[i+1].first;
        int y2 = points[i+1].second;
        total += x1*y2 - x2*y1;
    }

    // Vn-1_x * V0_y - Vn-1_y * V0_x 
    total += points[n-1].first*points[0].second - points[n-1].second*points[0].first;

    total = abs(total);
    total *= 0.5;
    return total;
}


/**
 * Euclid's Algorithm
 * Finds the greatest common divisor between two numbers.
 */
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}