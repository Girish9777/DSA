class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp;
        for(int i=0;i<s1.length();i++){
            mp[s1[i]]++;
        }
        int size=s1.length();
        int head=-1;
        int tail=0;
        int count=0;int n=s2.length();
        map<char,int> temp;
        while(tail<n){
            while(head+1<n && count<size){
               temp[s2[head+1]]++;
               head++; 
               count++;
            }
            if(head-tail+1==size){
                if(mp==temp)return true;
            }
            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                    if(temp[s2[tail]]>0){
                        temp[s2[tail]]--;
                        if(temp[s2[tail]]==0){
                            temp.erase(s2[tail]);
                        }
                    }
                
                tail++;
                count--;
            }
        }
        return false;
    }
};
