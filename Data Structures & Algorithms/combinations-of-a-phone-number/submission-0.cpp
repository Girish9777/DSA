class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        if(digits=="")
        {
            return output;
        }
        string ans="";
        string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        rec(digits,output,ans,mapping,0);
        return output;
    }
    void rec(string& digits,vector<string>& output,string ans,string mapping[],int idx){
        if(idx==digits.size()){
            output.push_back(ans);
            return ;
        }
        // choice to take or not 
        int val=digits[idx]-'0';
        string mapped=mapping[val];
        for(int i=0;i<mapped.size();i++){
            ans+=mapped[i];
            rec(digits,output,ans,mapping,idx+1);
            ans.pop_back();
        }
    }
};
