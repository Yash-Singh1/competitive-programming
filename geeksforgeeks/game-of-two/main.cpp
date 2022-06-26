class Solution {
  public:
    int closestPower(int n) {
        int closest{1000000};
        int closestP{-1};
        int p{1};
        for (int i{0}; i < 18; ++i) {
            p *= 2;
            int d{abs(n - p)};
            if (d <= closest) {
                closest = d;
                closestP = p;
            }
        }
        return closestP;
    }
};