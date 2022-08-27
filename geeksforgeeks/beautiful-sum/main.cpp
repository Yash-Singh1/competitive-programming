class Solution{
public:
    int beautifulSum(int arr[], int n) {
	    int e{0};
	    int o{0};
	    for (int i{0}; i < n; ++i) {
	        if (i % 2 == 0) {
	            e+=arr[i];
	        }
	        else {
	            o+=arr[i];
	        }
	    }
	    return abs(e - o);
	}
};