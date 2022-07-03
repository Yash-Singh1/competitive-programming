// Speed implemented in 2.5 minutes :)

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int s{0}, e{n - 1};
        while (s <= e) {
            int mid{(s + e) / 2};
            if (arr[mid] > k) {
                e = mid - 1;
            } else if (arr[mid] < k) {
                s = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
