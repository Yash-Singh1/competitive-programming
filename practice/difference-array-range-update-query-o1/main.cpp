// https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
// Given an array A and operations, run the operations
// Operations:
//   - update(L, R, S): Increment the values between indices L and R inclusive with S
//   - printArray(): Print out the current value of the array

#include <bits/stdc++.h>
using namespace std;

vector<int> A{10, 5, 20, 40};
vector<int> D{};

void initializeDifferenceArray() {
    D.push_back(A[0]);
    for (int i{1}; i < A.size(); ++i) {
        D.push_back(A[i] - A[i - 1]);
    }
}

void update(int l, int r, int s) {
    D[l] += s;
    if (r + 1 < D.size()) {
        D[r + 1] -= s;
    }
}

void printArray() {
    A[0] = D[0];
    for (int i{1}; i < D.size(); ++i) {
        A[i] = A[i - 1] + D[i];
    }
    for (auto el: A) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {
    initializeDifferenceArray();
    update(0, 1, 10);
    printArray();
    update(1, 3, 20);
    update(2, 2, 30);
    printArray();
}
