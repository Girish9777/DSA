class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> output;
        vector<int> curr;
        rec(nums,output,curr,0);
        return output;

    }
    void rec(vector<int>& nums, vector<vector<int>>& output,vector<int>& curr,int idx)
    {
        if( idx== nums.size()){
            output.push_back(curr);
            return ;
        }
        // choice
        curr.push_back(nums[idx]);
        rec(nums,output,curr,idx+1);
        curr.pop_back();


        // exclude tab krna hai same elements ho and hamre pass duplicate subsets wapis na aye
        int i=idx+1;
        while(i<nums.size() && nums[i]==nums[i-1]){
            i++;
        }
        rec(nums,output,curr,i);
    }
};
