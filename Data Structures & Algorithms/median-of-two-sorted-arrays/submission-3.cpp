class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n=nums1.size();
        int lo=0;
        int hi=n;

        int n1=nums2.size();
        int t=n+n1;
        int left=(n+n1+1)/2;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int mid1=left-mid;
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            if(mid<n)r1=nums1[mid];
            if(mid-1>=0)l1=nums1[mid-1];
            if(mid1<n1)r2=nums2[mid1];
            if(mid1-1>=0)l2=nums2[mid1-1];
            if(l1<=r2 && l2<=r1){
                if(t%2==0){
                    return double(max(l1,l2)+min(r1,r2))/2.0;
                }
                else{
                    return max(l1,l2);
                }
            }
            else if(l1>r2){
                hi=mid-1;
            }else{
                lo=mid+1;
            }



        }return -1.0;
    }
};
