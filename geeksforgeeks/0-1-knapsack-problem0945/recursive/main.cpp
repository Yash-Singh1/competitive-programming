class Solution
{
    public:
    int validate(int W, int wt[], int val[], int n, int start) {
        if (start == n || W == 0) {
            return 0;
        }
        int no{validate(W, wt, val, n, start + 1)};
        if (W - wt[start] < 0) {
            return no;
        }
        int yes{validate(W - wt[start], wt, val, n, start + 1) + val[start]};
        return max(no, yes);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return validate(W, wt, val, n, 0);
    }
};
