class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        int change{0};
        if (n == 0) {
            return change;
        }
        while ((n & 1) == 0) {
            ++change;
            n >>= 1;
        }
        return change + 1;
    }
};
