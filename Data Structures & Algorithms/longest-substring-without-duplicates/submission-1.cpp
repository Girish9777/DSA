class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head=-1;
        int tail=0;int ans=0;int n=s.length();
        map<char,int> mp;
        while(tail<s.length()){
            while(head+1<n && mp[s[head+1]]==0 ){
                head++;
                mp[s[head]]++;
            }
            ans=max(head-tail+1,ans);
            if(tail>head){
                tail++;
                head=tail-1;
            }else{
                mp[s[tail]]--;
                tail++;
            }

        }
        return ans;
    }
};
