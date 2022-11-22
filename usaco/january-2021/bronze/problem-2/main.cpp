#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int e{0}, o{0}, x;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    if (x & 1) {
      ++o;
    } else {
      ++e;
    }
  }

  bool even{1};
  int tot{0};
  while (o||e){
    if (even){
      if (e>0)--e;
      else if (o>1) o-=2;
      else break;
    }else{
      if(o>0&&(e||o!=2))--o;
      else break;
    }
    ++tot;
    even=!even;
  }

  cout << tot << "\n";

  return 0;
}
