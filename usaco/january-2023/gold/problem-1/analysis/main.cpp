// This prob is so hard, I could only get first subtask

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll>> contrib(200001, vector<ll>(26, 1));
vector<pair<char,string>> ops(200001);
int n;
ll l, r;
int tot{0};
unordered_set<ll> vis;
vector<vector<int>> pre(200002, vector<int>(26, -1));

string ans;

void dfs(int level, char cur, ll l2, ll rr) {
  // cout << " ";
  // for (int i{0}; i < tot; ++i) cout << "  ";
  // cout << l2 << " (" << rr << ") " << cur << "\n";
  ++tot;
  if (l2 > r || l2 <= -1 || (rr != -1 && rr < l)) {
    --tot;
    return;
    // return "";
  }
  // We need to precompute the next level where the char is encountered
  int i{pre[level][cur-'a']};
  if (i != -1) {
    ll curl{l2};
    for (int j{0}; j < (int)ops[i].second.size(); ++j) {
      if (curl > r) break;
      // cout << curl << " " << curl + (ll)contrib[i+1][ops[i].second[j] - 'a'] - 1 << "\n";
      // cout << cur << " " << l2 << "-" << rr;
      if ((__int128)curl - 1 + contrib[i+1][ops[i].second[j] - 'a'] >= LLONG_MAX/2) {
        curl = -1;
        break;
      }
      dfs(i+1, ops[i].second[j], curl, contrib[i+1][ops[i].second[j] - 'a'] == -1 ? -1 : (curl + contrib[i+1][ops[i].second[j] - 'a'] - 1));
      curl += contrib[i+1][ops[i].second[j] - 'a'];
      // if (curl > LLONG_MAX) {
      //   curl = -1;
      //   break;
      // }
    }
  }
  --tot;
  if (i==-1 && vis.find(l2) == vis.end()) {
    ans += string(1, cur);
    vis.insert(l2);
  }
  // return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> l >> r >> n;
  --l; --r;

  for (int i{0}; i < n; ++i) {
    cin >> ops[i].first >> ops[i].second;
    ops[i].first = ops[i].first - 'a';
  }

  for (int i{0}; i < 26; ++i) {
    int curry{-1};
    for (int j{n - 1}; j >= 0; --j) {
      if (ops[j].first == i) {
        curry = j;
      }
      pre[j][i] = curry;
    }
  }

  for (int i{n - 1}; i >= 0; --i) {
    for (int j{0}; j < 26; ++j) {
      if (ops[i].first == j) {
        contrib[i][j] = 0;
        for (int k{0}; k < (int)ops[i].second.size(); ++k) {
          if (contrib[i + 1][ops[i].second[k] - 'a'] == -1) {
            contrib[i][j] = -1;
            break;
          } else {
            contrib[i][j] += contrib[i + 1][ops[i].second[k] - 'a'];
            if (contrib[i][j] > LLONG_MAX/2) {
              contrib[i][j] = -1;
              break;
            }
          }
        }
      } else {
        contrib[i][j] = contrib[i + 1][j];
      }
    }
  }

  // for (int i{0}; i < n; ++i) {
  //   for (int j{0}; j < 26; ++j) {
  //     cout << (ll)contrib[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  // We can run a DFS and eliminate out of bounds
  // cout << "a 0-" << (ll)(contrib[0][0]==-1?0:contrib[0][0])-1;
  dfs(0, 'a', 0, contrib[0][0]);
  cout << ans << "\n";

  return 0;
}
