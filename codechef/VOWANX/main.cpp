// TLE

#include <bits/stdc++.h>

using namespace std;

// From gfg queue-reversal
queue<pair<string, int>> rev(queue<pair<string, int>> q)
{
  stack<pair<string, int>> rq;
  while (!q.empty())
  {
    rq.push(q.front());
    q.pop();
  }
  while (!rq.empty())
  {
    q.push(rq.top());
    rq.pop();
  }
  return q;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  ++t;
  while (--t)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int vowi{0};
    queue<pair<string, int>> q;
    int tot{0};
    for (int i{1}; i < n; ++i)
    {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u')
      {
        q = rev(q);
        q.push({s.substr(vowi, i - vowi), tot});
        vowi = i;
        ++tot;
      }
    }
    int i{0};
    q = rev(q);
    while (!q.empty())
    {
      string x;
      x = q.front().first;
      if (q.front().second % 2 != tot % 2)
      {
        reverse(x.begin(), x.end());
      }
      cout << x;
      q.pop();
      ++i;
    }
    cout << s.substr(vowi, n - vowi) << "\n";
  }
}
