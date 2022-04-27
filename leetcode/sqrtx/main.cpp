class Solution {
public:
    int mySqrt(int x) {
        unsigned int num{0};
        for (unsigned int i{0}; i * i < x; ++i) {
            num = i;
        }
        if ((num + 1) * (num + 1) == x) return num +1;
        return num;
    }
};
