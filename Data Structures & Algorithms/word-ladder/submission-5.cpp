class Solution {
    using state=pair<string,int>;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;

        for(int i=0;i<wordList.size();i++){
                st.insert(wordList[i]);
        }
        if(!st.contains(endWord)){
            return 0;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            state curr=q.front();
            q.pop();
            string word=curr.first;
            int steps=curr.second;
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                string orig=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.contains(word)){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word=orig;
            }
        }
        return 0;
    }
};
