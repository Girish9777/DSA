class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }
        vector<int> ans;
        int i;
        for(i=0;i<n;i++){
            if(i==0){
                ans.push_back(suffix[i+1]);
            }
            else if(i==n-1){
                ans.push_back(prefix[i-1]);
            }
            else{
                ans.push_back(suffix[i+1]*prefix[i-1]);
            }
        }
        return ans;
    }
};
