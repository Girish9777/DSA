class Solution {
public:
    int characterReplacement(string s, int k) {
        int head=-1;
        int tail=0;
        vector<int> check(26,0);
        int ans=0;int n=s.length();
        while(tail<n){
            while(head+1<n){
                int x=s[head+1]-'A';
                check[x]++;
                int maxfreq=0;
                for(int i=0;i<26;i++){
                    maxfreq=max(maxfreq,check[i]);
                }
                int len=head+1-tail+1;
                if(len-maxfreq<=k){
                    head++;
                }else{
                    check[x]--;
                    break;
                }

            }
            ans=max(ans,head-tail+1);
            if(tail>head){
                tail++;
                head=tail-1;
            }else{
                check[s[tail]-'A']--;
                tail++;
            }
        }
        return ans;
    }
};
