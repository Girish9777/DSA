class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       for(int row=0;row<board.size();row++){
        for(int col=0;col<board[0].size();col++){
            if(rec(board,word,row,col,0)){
                return true;
            }
        }
       }  return false;
    }
    bool rec(vector<vector<char>>& board,string word,int row,int col,int idx){
        if(idx==word.size()){
            return true;
        }
         // ERROR FIX: boundary check
        if (row < 0 || col < 0 ||
            row >= board.size() ||
            col >= board[0].size()) {
            return false;
        }
        //choice to not take
        if(!check(board,word,row,col,idx)){
            return false;
        }

        // it means we can taje this index and then we check the another level
            char ch=board[row][col];
            board[row][col]='*';
            if(rec(board,word,row,col+1,idx+1)||rec(board,word,row,col-1,idx+1)||
            rec(board,word,row-1,col,idx+1) ||rec(board,word,row+1,col,idx+1)){
                return true;
            }
            board[row][col]=ch;
            return false ;
        
        
    
    }
    bool check(vector<vector<char>>& board,string word,int row,int col,int idx)
    {
        if(board[row][col]!=word[idx]){
            return false;
        }
        return true;
    }
};
