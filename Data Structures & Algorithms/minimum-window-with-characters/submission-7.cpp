class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int formed=mp.size();
        unordered_map<char,int> window;
        int tail=0;
        int head=-1;int required=0;
        int n=s.length();
        int bestlen=INT_MAX;
        int besttail=-1;
        while(tail<n){
            while(head+1<n && required<formed ){
                head++;
                window[s[head]]++;
                if(window[s[head]]==mp[s[head]]){
                    required++;
                }

            }
            // ans

            if(formed==required){
                int currlen=head-tail+1;
                if(currlen<bestlen){
                    bestlen=currlen;
                    besttail=tail;
                }
            }
            if(tail>head){
                tail++;
                head=tail-1;
            }else{
                if(window[s[tail]]==mp[s[tail]]){
                    required--;
                }
                window[s[tail]]--;
                tail++;
            }
        }
        if(besttail==-1){
            return "";
        }else{
            return s.substr(besttail,bestlen);
        }
    }
};
