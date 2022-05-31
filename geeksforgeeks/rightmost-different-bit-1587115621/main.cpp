class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        int x{m ^ n};
        //std::cout << x <<" " << (x & 1 == 0) << " " << (x << 1) << " " << (x >> 1 == 0) << " ";
        if (x == 0) {
            return -1;
        }
        int change{0};
        while ((x & 1) == 0) {
            x >>= 1;
            ++change;
        }
        return change + 1;
    }
};
