class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(freq[t[i]]>0){
                    freq[t[i]]--;
                    if(freq[t[i]]==0)freq.erase(t[i]);
            }
            
        }
            if(freq.empty()){
                return true;
            }else{
                return false;
            }
    }
};
