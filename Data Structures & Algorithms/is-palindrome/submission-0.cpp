class Solution {
public:
    bool isPalindrome(string s) {
        int st=0;
        
        string ans="";

        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
               ans+= s[i]+=32;
            }
            else if(s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9'){
                ans+=s[i];
            }
        }
        int e=ans.length()-1;
        while(st<e){
            if(ans[st]!=ans[e])return false;
            else{
                st++;e--;
            }
        }
        return true;
    }
};
