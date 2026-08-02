class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;vector<int> ans;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && dq.back()<nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            if(i-k>=0){
                if(dq.front()==nums[i-k]){
                    dq.pop_front();
                }
            }
            if(i>=k-1){
                ans.push_back(dq.front());
            }
            
            
            
        } return ans;
    }
};
