class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        rec(nums,output,ans,mp);
        return output;
    }
    void rec(vector<int>& nums,vector<vector<int>>& output,vector<int>& ans,map<int,int> mp)
    {
        if(ans.size()==nums.size()){
            output.push_back(ans);
            return ;
        }
        // choice take or not take 
        map<int,int> temp=mp;
        for(auto x:temp){
            if(x.second>0){
                ans.push_back(x.first);
                mp[x.first]--;
                rec(nums,output,ans,mp);
                mp[x.first]++;
                ans.pop_back();
            }
        }
    }
};
