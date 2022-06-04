class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>s;
        vector<long long> r(n, -1);
        for (int i{0}; i < n; ++i) {
            long long e{arr[i]};
            if (s.empty() || arr[s.top()] >= e) {
                s.push(i);
            } else {
                while (!s.empty() && arr[s.top()] < e) {
                    r[s.top()] = e;
                    s.pop();
                }
                s.push(i);
            }
        }
        return r;
    }
};
