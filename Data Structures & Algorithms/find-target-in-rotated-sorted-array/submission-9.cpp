class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;int ans=0;
        int hi=nums.size()-1;
        if(nums.size()==1){
            if(nums[0]==target){
                return 0;
            }else{
                return -1;
            }
        }
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(check(nums,mid)){
                    ans=mid;
                    hi=mid-1;

            }else{
                lo=mid+1;
            }
        }
        lo=0;
        hi=nums.size()-1;
            int left=checkleft(nums,target,0,ans-1);
            int right=-1;
           
             right=checkright(nums,target,ans,hi); 
           
            if(left==-1 && right==-1){
                return -1;
            }
            else if(left!=-1)return left;
            
            return right;
            
    }
    bool check(vector<int>& nums,int mid){
        if(nums[mid]<=nums[nums.size()-1])return true;
        
        return false;
    }
    int checkleft(vector<int>& nums,int target,int s,int e){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>=target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return -1;
    }
     int checkright(vector<int>& nums,int target,int s,int e){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid] > target){
    e = mid - 1;   // ✅ target chhota hai → LEFT
}else{
    s = mid + 1;   // ✅ target bada hai → RIGHT
}
        }
        return -1;
    }
};
