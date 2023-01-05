#include <bits/stdc++.h>

using namespace std;

class AveragesOfThree  {
  public:
    vector <int> restore(vector <int> B) {
        vector<int> A(B.size() + 2);
        A[0] = 0;
        A[1] = 0;
        for (int i{0}; i < B.size(); ++i) {
            int sm{0};
            for (int j{i}; j < i + 2; ++j) {
                sm += A[j];
            }
            A[i + 2] = 3 * B[i] - sm;
        }
        return A;
    }
};
