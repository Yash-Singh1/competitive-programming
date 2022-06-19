class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int> q;
        for (int i{0}; i < n; ++i) {
            q.push(arr[i]);
        }
        ++k;
        vector<int> ans;
        while (--k) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};
