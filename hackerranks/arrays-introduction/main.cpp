#include <iostream>

using namespace std;

int main() {
    int length {0};
    cin >> length;
    
    int nums [length];
    for (int i {0}; i < length; ++i) {
        cin >> nums[i];
    }
    for (int i {length - 1}; i >= 0; --i) {
        cout << nums[i] << " ";
    }
    return 0;
}
