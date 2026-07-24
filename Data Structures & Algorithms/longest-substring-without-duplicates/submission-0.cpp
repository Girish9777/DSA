class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int tail=0;
        int head=-1;
        int ans=0;
        int curr=0;
        int n=s.length();
        while(tail<s.length()){
            while(head+1<n && mp[s[head+1]]==0){
                head++;
                mp[s[head]]++;
            } curr=mp.size();
            ans=max(ans,curr);
            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{

                if(mp[s[tail]]==1){
                    mp[s[tail]]--;
                    mp.erase(s[tail]);
                } tail++;

            }
        }
        return ans;
    }
};
