class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int formed=mp.size();
        map<char,int> window;
        int head=-1;
        int tail=0;int n=s.length();
       
        int bestlen=INT_MAX;
        int beststart=-1;
        int required=0;int currlen=0;
        string ans="";
        while(tail<n){
            while(head+1<n && required<formed){
                head++;
                window[s[head]]++;
                if(window[s[head]]==mp[s[head]]){
                    required++;
                }

            }
            if(formed==required){
                currlen=head-tail+1;
                if(currlen<bestlen){
                    bestlen=currlen;
                    beststart=tail;
                }
            }
            if(tail>head){
                tail++;
                head=tail-1;
        }
        else{
            if(window[s[tail]]==mp[s[tail]]){
                required--;
            }window[s[tail]]--;
            tail++;
            
        }
    }
    if(beststart==-1){
        return ans;
    }
    return s.substr(beststart,bestlen);}
};
