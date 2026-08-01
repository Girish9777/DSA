class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> ans;
        rec(nums,output,ans,0);
        return output;
    }
    void  rec(vector<int>&nums,vector<vector<int>>& output,vector<int>& ans,int index){
        if(index==nums.size()){
            output.push_back(ans);
            return ;
        }
        // choice 
        //take or not take
        // if take
        ans.push_back(nums[index]);
        rec(nums,output,ans,index+1);
        ans.pop_back();

        //exclude if not take
        rec(nums,output,ans,index+1);
    }
};
