/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root,int& count,int maxval){
            if(root==NULL)
            {
                return ;
            }
            if(root->val>=maxval){
                maxval=root->val;
                count++;
            }
            solve(root->left,count,maxval);
            solve(root->right,count,maxval);
          

    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int count=0;
        solve(root,count,root->val);
        return count;
    }
};
