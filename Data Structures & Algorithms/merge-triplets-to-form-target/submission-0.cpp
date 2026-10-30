class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> res(target.size(),0);
        for(int i=0;i<triplets.size();i++){
            bool valid=true;
            for(int j=0;j<triplets[i].size();j++){
                if(triplets[i][j]>target[j]){
                    valid=false;
                }
            }
              if (valid) {
                for (int j = 0; j < target.size(); j++) {
                    res[j] = max(res[j], triplets[i][j]);
                }
            }
        }
        if(res==target){
            return true;
        }
        return false;
    }
};
