class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26);
        vector<int> window(26);
        for(int i=0;i<s1.length();i++){
            need[s1[i]-'a']++;
        }
        int tail=0;
        int head=-1;
        while(tail<s2.length()){
            while(head+1<s2.length()&& head-tail+1<s1.length()){
               window[s2[head+1]-'a']++;
                head++;
            }
            if(head-tail+1==s1.length()){
                if(need==window)return true;
            }
            if(tail>head){
                tail++;
                head=tail-1;
            }else{
                window[s2[tail]-'a']--;
                tail++;
            }
        }
        return false;
    }
};
