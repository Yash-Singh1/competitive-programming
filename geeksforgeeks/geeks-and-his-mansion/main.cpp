class Solution {
  public:
    long tot_cost(int n, vector<int> &sides) {
        long cost{0};
        for (auto &a: sides) {
            if (a % 15 == 0 && a & 1) {
                cost += 40 * a * a;
                cost += 8 * a * a;
            } else if ((a & (a - 1)) == 0 && a != 1) {
                cost += 60 * a * a;
                cost += 12 * a * a;
            } else {
                cost += 12 * a * a;
                cost += a * a;
            }
        }
        return cost;
    }
};