#include <bits/stdc++.h>

using namespace std;

// q: quantities, r: recipes
int q[105];
vector<int> r[105];

bool cook(int pos) {
  // If this is a leaf node that can't be created
  // we have to rely on the given supply in that case
  if (r[pos].empty()) {
    if (q[pos] == 0) {
      return false;
    }
    --q[pos];
    return true;
  }
  // If we have existing supply
  if (q[pos] != 0) {
    --q[pos];
    return true;
  }
  // No existing supply, but yes recipe
  for (auto ing: r[pos]) {
    // Does the ingredient have an existing supply
    if (q[ing] > 0) {
      --q[ing];
    }
    // Otherwise try to cook the ingredient
    else if (!cook(ing)) {
      return false;
    }
  }
  return true;
}

int main() {
  // Read in quantities, recipes, and other input
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  for (int i{0}; i < n; ++i) {
    cin >> q[i + 1];
  }

  int k;
  cin >> k;
  while (k--) {
    vector<int> re;
    int to, qua;
    cin >> to >> qua;
    while (qua--) {
      int x;
      cin >> x;
      re.push_back(x);
    }
    r[to] = re;
  }

  // Keep cooking metal N until it isn't possible anymore
  // In that case the function cook will return false
  int ans{0};
  while (cook(n)) {
    ++ans;
  }

  cout << ans;

  return 0;
}
