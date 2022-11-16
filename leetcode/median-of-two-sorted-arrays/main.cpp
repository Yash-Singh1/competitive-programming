class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // find number with (m+n)/2 people in front
        int n{(int)nums1.size()}, m{(int)nums2.size()};
        int l{min(n > 0 ? nums1[0] : INT_MAX, m > 0 ? nums2[0] : INT_MAX)}, r{max(n > 0 ? nums1[n-1] : INT_MIN, m > 0 ? nums2[m-1] : INT_MIN)};
        double ans{-1};
        // vector<int> idk(1);
        while (l <= r) {
            int mid{(l+r)/2};
            auto query1 = lower_bound(nums1.begin(), nums1.end(), mid);
            auto query2 = lower_bound(nums2.begin(), nums2.end(), mid);
            int lookingforsomethingelse{(query1 == nums1.end()) ? (*query2) : (query2 == nums2.end() ? (*query1) : min(*query1, *query2))};
            // idk[0] = mid;
            auto query3 = upper_bound(nums1.begin(), nums1.end(), lookingforsomethingelse);
            auto query4 = upper_bound(nums2.begin(), nums2.end(), lookingforsomethingelse);
            int dist{(int)(query2 - nums2.begin()) + (int)(query1 - nums1.begin())};
            int dist2{(int)distance(nums1.begin(), query3) + (int)distance(nums2.begin(), query4) - 1};
            cout << l << " " << r << " " << dist << " " << dist2 << " " << mid << " " << n << " " << m << "\n";
            if (dist <= (n+m-1)/2 && dist2 >= (n+m-1)/2) {
                cout << "A" << dist << " " << dist2 << " " << mid << "\n";
                // break;
                ans = (double)((query1 == nums1.end()) ? (*query2) : (query2 == nums2.end() ? (*query1) : min(*query1, *query2)));
                if ((n+m+1)&1 && dist2 < (n+m-1)/2+1){
                    auto aftermedian1 = upper_bound(nums1.begin(), nums1.end(), ans);
                    auto aftermedian2 = upper_bound(nums2.begin(), nums2.end(), ans);
                    ans = (double)((aftermedian1 == nums1.end()) ? (aftermedian2 == nums2.end() ? ans : (ans+(*aftermedian2))/2) : (aftermedian2 == nums2.end() ? (ans+(*aftermedian1))/2 : (ans+min(*aftermedian1, *aftermedian2))/2));
                }
                break;
            } else if (dist < (n+m-1)/2) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
