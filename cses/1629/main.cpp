#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>>v;
    for (int i{0}; i <n;++i) {
        int x, y;
        cin >> x >> y;
        pair<int,int>p = {x, y};
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    int c {1};
    int ed{v[0].second};
    for (int i{1}; i < n; ++i) {
        if (v[i].first > ed) {
            ed = v[i].second;
            ++c;
        }
    }
    std::cout << c;
}
