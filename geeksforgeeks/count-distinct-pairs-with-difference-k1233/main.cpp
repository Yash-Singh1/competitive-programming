class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	    map<int, bool> m;
	    set<int> s;
	    for (auto num: nums) {
	        if (m.find(num + k) != m.end()) {
	            s.insert(num);
	        }
	        if (m.find(num - k) != m.end()) {
	            s.insert(num -k);
	        }
	        m[num] = 1;
	    }
	    return s.size();
	}

};
