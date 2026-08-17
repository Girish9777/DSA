class Solution {
public:
    void rec(vector<int>& nums,map<int,int>& mp,vector<vector<int>>& ans,vector<int>& perm,int idx){
        if(idx==nums.size()){
            ans.push_back(perm);
            return ;
        }

        // take or nor to take
        map<int,int> temp=mp;
        for(auto &x:mp){
            if(x.second>0){
                perm.push_back(x.first);
                x.second--;
                 rec(nums,mp,ans,perm,idx+1);
                 perm.pop_back();
                x.second++;
                

            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> ans;
        vector<int> perm;
        rec(nums,mp,ans,perm,0);
        return ans;
    }
};
