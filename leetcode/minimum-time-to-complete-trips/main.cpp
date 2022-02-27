class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        int trips{0};
        vector<int> leftForTrip;
        for (auto timeLeft: time) {
          leftForTrip.push_back(timeLeft);
        }
      int taken{0};
        while (trips < totalTrips) {
          for (int i{0}; i < leftForTrip.size(); ++i) {
            --leftForTrip[i];
            if (leftForTrip[i] == 0) {
              ++trips;
              leftForTrip[i] = time[i];
            }
          }
          ++taken;
        }
      return taken;
    }
};
