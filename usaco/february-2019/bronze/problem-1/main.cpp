#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);

  int arr[3];
  for (int i{0}; i < 3; ++i) cin >> arr[i];
  sort(arr,arr+3);

  int a{arr[0]}, b{arr[1]}, c{arr[2]};

  cout << (a == c-2 ? 0 : (c-b == 2 || b-a==2) ? 1 : 2) << "\n";
  cout << max(c-b, b-a)-1 << "\n";

  return 0;
}
