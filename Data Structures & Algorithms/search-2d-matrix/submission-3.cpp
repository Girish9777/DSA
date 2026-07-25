class Solution {
    int check(int mid,vector<vector<int>>& matrix,int target,int m){
            int row=mid/m;
            int col=mid%m;
            return matrix[row][col];
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int lo=0;
        int hi=n*m-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int val=check(mid,matrix,target,m);
            if(val==target)return true;
            else if(val>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }return false;

    }
};
