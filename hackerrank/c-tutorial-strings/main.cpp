#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
    cin >> a >> b;
    cout << a.size() << " " << b.size() << endl;
    cout << a << b << endl;
    char firstb = b[0];
    b[0] = a[0];
    a[0] = firstb;
    cout << a << " " << b;
  
    return 0;
}
