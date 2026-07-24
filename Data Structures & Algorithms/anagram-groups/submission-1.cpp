class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(auto s:strs){
            string st=s;
            sort(st.begin(),st.end());
            mp[st].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto c:mp){
            ans.push_back(c.second);
        }
        return ans;
    }
};
