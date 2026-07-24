class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans=0;
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(a+b);
            }
            else if( tokens[i]=="-"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(b-a);
            }
            else if( tokens[i]=="*"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(a*b);
            }
            else if( tokens[i]=="/"){// agar java toh comparison .equals se 
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(b/a);
            }
            else{
                st.push(stoi(tokens[i]));// agar java hoti toh Integer.parseInt(tokens[i])
            }
        }
        return st.top();
    }
};
