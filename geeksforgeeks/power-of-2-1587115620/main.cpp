class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        return n == 0 ? false : (n & (n - 1)) == 0;
        
    }
};
