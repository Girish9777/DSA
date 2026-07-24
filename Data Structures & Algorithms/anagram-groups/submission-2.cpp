class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        string ans="";
        for(int i=0;i<strs.size();i++){
            ans=strs[i];
            sort(ans.begin(),ans.end());
            mp[ans].push_back(strs[i]);

        }
        vector<vector<string>> res;
        for(auto m:mp){
                res.push_back(m.second);
        }return res;
    }
};
