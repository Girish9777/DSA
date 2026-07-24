class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair<int,double>> ans(position.size());
       // store position and time
       for(int i=0;i<position.size();i++){
        double time=(double)(target-position[i])/speed[i];
        ans[i]={position[i],time};
       } 
       sort(ans.begin(),ans.end());
       double prev=0;
        int fleet=0;
       for(int i=position.size()-1;i>=0;i--)
       { double currtime=ans[i].second;
            if(currtime>prev){
                fleet++;
                prev=currtime;
            }

       } return fleet;
    }
};
