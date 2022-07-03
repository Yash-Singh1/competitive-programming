class Solution
{
public:
    int setKthBit(int N, int K)
    {
        return N | (1 << K);
    }
    
};
