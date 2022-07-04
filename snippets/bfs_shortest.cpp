#include <bits/stdc++.h>
using namespace std;

// Function to return shortest distance through BFS.
// This assumes that the graph is unweighted because the first time a node is visited is the shortest
// path to it assuming that, allowing us to complete in O(n)
int shortestBfs(int V, vector<int> adj[], int target)
{
    queue<int> s;
    s.push(0);
    bool visited[V];
    int dist[V];
    for (int i{0}; i < V; ++i)
    {
        visited[i] = false;
        dist[V] = -1;
    }
    dist[0] = 0;
    while (!s.empty())
    {
        int next{s.front()};
        s.pop();
        if (visited[next] == true)
        {
            continue;
        }
        visited[next] = true;
        for (auto ad : adj[next])
        {
            dist[ad] = dist[next] + 1;
            s.push(ad);
        }
    }
    return dist[target];
}
