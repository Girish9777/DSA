class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;
        for(int i=0;i<tickets.size();i++){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string> st;vector<string> ans;
        st.push("JFK");
        while(!st.empty()){
            string src=st.top();
            if(adj[src].size()==0){
                ans.push_back(src);
                st.pop();
            }
            else{
                auto dst=adj[src].begin();
                st.push(*dst);
                adj[src].erase(dst);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
