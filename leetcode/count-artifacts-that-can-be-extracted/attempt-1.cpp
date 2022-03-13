class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
      int dugUp{0};
      int usedDigs[dig.size()];
      for (auto artifact: artifacts) {
        int artifactEntries{(artifact[2] - artifact[0] + 1) * (artifact[3] - artifact[1] + 1)};  
        bool used{false};
        for (int i{0}; i < dig.size(); ++i) {
            if (usedDigs[i] == 0) continue; 
            vector<int> digSpot {dig[i]};
            if (digSpot[0] >= artifact[0] && digSpot[1] >= artifact[1] && digSpot[0] <= artifact[2] && digSpot[1] <= artifact[3]) {
              --artifactEntries;
              usedDigs[i] = 1;
            }
        }
        if (artifactEntries == 0) {
          ++dugUp;
        }
      }
      return dugUp;
    }
};
