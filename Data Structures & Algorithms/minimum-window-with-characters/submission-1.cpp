class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> mp;
       for(int i=0;i<t.length();i++){
        mp[t[i]]++;
       } 
       int required=mp.size();
       unordered_map<char,int> window;
       int tail=0;
       int head=-1;
       int n=s.length();
       int formed=0;
       int currlength=0;
       int bestlength=INT_MAX;
       int beststart=-2;
       string ans="";
       while(tail<n){
            while(head+1<n && formed<required){
                head++;
                window[s[head]]++;
                if( mp[s[head]]==window[s[head]]){
                    formed++;
                }
            }
            if(formed==required){
                currlength=head-tail+1;
                if(currlength<bestlength){
                    bestlength=currlength;
                    beststart=tail;
                }
            }
            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                char ch=s[tail];
                if( mp[ch]==window[ch]){
                    formed--;
                }
                window[ch]--;
                tail++;
            }

       }
       if(beststart==-2){
        return "";
       }
       else{
        return s.substr(beststart,bestlength);
       }














    }
};
