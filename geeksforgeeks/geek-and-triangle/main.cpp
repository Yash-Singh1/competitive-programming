class Solution{
    public:
    bool triangle(int a, int b, int c)
    {
        if (a + b > c && b + c > a && a + c > b) {
            return 1;
        }
        return 0;
    }
};