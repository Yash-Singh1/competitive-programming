#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("dishes.in", "r", stdin);
  freopen("dishes.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i <n ; ++i) cin >> a[i];

  int l{1}, r{n}, ans{-1};
  while (l <= r) {
    int mid{(l+r)/2};
    deque<deque<int>> q;
    bool failure{0}, flag{0};
    deque<int> req;
    for (int i{0}; i < mid; ++i) {
      req.push_back(a[i]);
    }
    sort(req.begin(), req.end());
    for (int i{0}; i < mid; ++i) {
      // Technique for inserting
      // - While beginning of leftmost stack is what is req next, clean dish
      // - Otherwise insert in whatever stack it is closest to top (create new stack if upperbound == end)
      //   - If in best fitting stack, it is less than end of prev stack, fail
      bool lookAway{1};
      if (q.size()) {
        int l2{0}, r2{(int)q.size()-1}, ans2{-1};
        while (l2 <= r2) {
          int mid2{(l2+r2)/2};
          if (q[mid2].front() > a[i]) {
            ans2 = mid2;
            r2 = mid2-1;
          } else if (q[mid2].front() < a[i]) {
            l2 = mid2+1;
          }
        }
        lookAway = (ans2 == -1);
        if (!lookAway) {
          if (ans2 && q[ans2-1].back() > a[i]) {
            failure = 1;
            goto end;
          }
          q[ans2].push_front(a[i]);
        }
      }
      if (lookAway) {
        q.push_back(deque<int>());
        q[q.size() - 1].push_back(a[i]);
      }
      while (req.size() && q.size() && q.front().front() == req.front()) {
        q.front().pop_front();
        req.pop_front();
        if (q.front().empty()) {
          q.pop_front();
        }
      }
    }
    end: flag = 1;
    if (failure || req.size()) {
      r = mid - 1;
    } else {
      l = mid + 1;
      ans = mid;
    }
  }

  cout << ans << "\n";

  return 0;
}
