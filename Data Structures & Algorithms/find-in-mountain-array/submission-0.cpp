/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int lo=0;
        int n=mountainArr.length();
        int hi=mountainArr.length()-1;
        int ans =-1;
        int peak=mountainArr.get(n-1);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid-1)<mountainArr.get(mid) && mountainArr.get(mid)>mountainArr.get(mid+1)){
                peak=mid;
                break;
            }
            else if(mountainArr.get(mid)>mountainArr.get(mid+1))
            {
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        lo=0;
        hi=peak;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)==target)return mid;
            else if(mountainArr.get(mid)>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        lo=peak+1;
        hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)==target)return mid;
            else if(mountainArr.get(mid)>target){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return -1;

    }
};