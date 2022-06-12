#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> s;
        s.push(0);
        vector<int> ans;
        bool visited[V];
        for (int i{0}; i < V; ++i) {
            visited[i] = false;
        }
        while (!s.empty()) {
            int next{s.front()};
            s.pop();
            if (visited[next] == true) {
                continue;
            }
            ans.push_back(next);
            visited[next] = true;
            for (auto ad: adj[next]) {
                s.push(ad);
            }
        }
        return ans;
    }
};
