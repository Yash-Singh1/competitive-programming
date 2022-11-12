#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int m;
  cin >> m;

  multiset<pair<int,int>> unsets,sets;
  multiset<int> unsetsl,setsl;
  for (int i{0}; i < (int)s.size(); ++i) {
    if (s[i] == '0') {
      if (!unsets.empty() && prev(unsets.end())->second == i-1) {
        unsets.insert({prev(unsets.end())->first, i});
        unsets.erase({prev(unsets.end())->first, i-1});
        unsetsl.erase(unsetsl.find(i-prev(unsets.end())->first));
        unsetsl.insert(i-prev(unsets.end())->first+1);
      } else {
        unsets.insert({i, i});
        unsetsl.insert(1);
      }
    } else {
      if (!sets.empty() && prev(sets.end())->second == i-1) {
        sets.insert({prev(sets.end())->first, i});
        sets.erase({prev(sets.end())->first, i-1});
        setsl.erase(setsl.find(i-prev(sets.end())->first));
        setsl.insert(i-prev(sets.end())->first+1);
      } else {
        sets.insert({i, i});
        setsl.insert(1);
      }
    }
  }

  int c;
  pair<int,int> actual;
  while (m--) {
    cin >> c;
    --c;
    multiset<pair<int,int>> *setsp{&sets};
    multiset<int> *setslp{&setsl};
    multiset<pair<int,int>> *unsetsp{&unsets};
    multiset<int> *unsetslp{&unsetsl};
    if (s[c] == '1') {
      s[c] = '0';
    } else {
      setsp = &unsets;
      setslp = &unsetsl;
      unsetsp = &sets;
      unsetslp = &setsl;
      s[c] = '1';
    }
    auto query = (*setsp).lower_bound({c, INT_MIN});
    actual = *query;
    if (query != (*setsp).end() && query->first == c) {
      (*setsp).erase(query);
      (*setslp).erase((*setslp).find(actual.second-actual.first+1));
      ++actual.first;
      if (actual.second != c) {
        (*setsp).insert(actual);
        (*setslp).insert(actual.second-actual.first+1);
      }
    } else if (query != (*setsp).begin() && prev(query)->second >= c) {
      actual = *prev(query);
      if (prev(query)->second == c) {
        (*setsp).erase(actual);
        (*setslp).erase((*setslp).find(actual.second-actual.first+1));
        --actual.second;
        (*setsp).insert(actual);
        (*setslp).insert(actual.second-actual.first+1);
      } else {
        (*setsp).erase(actual);
        (*setsp).insert({actual.first, c-1});
        (*setsp).insert({c+1, actual.second});
        (*setslp).erase((*setslp).find(actual.second-actual.first+1));
        (*setslp).insert(actual.second-(c+1)+1);
        (*setslp).insert(c-actual.first);
      }
    }
    query = (*unsetsp).upper_bound({c, INT_MIN});
    int otherwayround{-1};
    if (query != (*unsetsp).end() && query->first == c + 1) {
      actual = *query;
      (*unsetsp).erase(actual);
      (*unsetslp).erase((*unsetslp).find(actual.second-actual.first+1));
      --actual.first;
      (*unsetsp).insert(actual);
      (*unsetslp).insert(actual.second-actual.first+1);
      otherwayround = actual.second;
    }
    query = (*unsetsp).lower_bound({c, INT_MIN});
    if (query != (*unsetsp).begin() && prev(query)->second == c-1) {
      actual = *prev(query);
      (*unsetsp).erase(actual);
      (*unsetslp).erase((*unsetslp).find(actual.second-actual.first+1));
      if (otherwayround == -1) {
        ++actual.second;
      } else {
        (*unsetsp).erase({c, otherwayround});
        (*unsetslp).erase((*unsetslp).find(otherwayround-c+1));
        actual.second = otherwayround;
      }
      (*unsetsp).insert(actual);
      (*unsetslp).insert(actual.second-actual.first+1);
    } else if (otherwayround == -1) {
      (*unsetsp).insert({c, c});
      (*unsetslp).insert(1);
    }
    cout << max((setsl.empty() ? 0 : *setsl.rbegin()), (unsetsl.empty() ? 0 : *unsetsl.rbegin())) << " ";
  }
  cout << "\n";

  return 0;
}
