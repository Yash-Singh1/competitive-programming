typedef long long ll;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        if (width >= (int)1e4 || height >= (int)1e4 || length >= (int)1e4 || (ll)length * (ll)width * (ll)height >= (ll)1e9) {
            if (mass >= 100) {
                return "Both";
            }
            return "Bulky";
        } else if (mass >= 100) {
            return "Heavy";
        }
        return "Neither";
    }
};
