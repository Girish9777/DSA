class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>    q;
        q.push({beginWord,1});
        unordered_map<string,int> mp;
        for(auto v:wordList){
            mp[v]++;
        }
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;q.pop();
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                string orig=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(mp[word]==1){
                        mp[word]--;
                        mp.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word=orig;
            }
          

        }  return 0;
    }
};
