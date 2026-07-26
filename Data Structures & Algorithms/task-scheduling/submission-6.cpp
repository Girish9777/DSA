class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> temp(26);
        for(int i=0;i<tasks.size();i++)
        {
          temp[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
          if(temp[i]>0)pq.push(temp[i]);
        }int time=0;
        while(!pq.empty()){
          vector<int> cool;
          for(int i=1;i<=n+1;i++){
            if(!pq.empty()){
            int freq=pq.top();
            freq--;
            cool.push_back(freq);pq.pop();}
          }
        
        for(int v:cool){
          if(v>0)pq.push(v);
        }
        if(pq.empty()){
          time+=cool.size();
        }
        else{
          time+=n+1;
        }}
        return time;

    }
};
