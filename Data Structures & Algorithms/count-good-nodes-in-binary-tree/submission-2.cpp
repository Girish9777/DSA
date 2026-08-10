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
    void solve(TreeNode* root,int maxvalue,int& count){
        if(root==NULL)
        {
            return;
        }
        if(maxvalue<=root->val){
            count++;
            maxvalue=root->val;
        }
        solve(root->left,maxvalue,count);
        solve(root->right,maxvalue,count);

    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;

        }
        int maxvalue=root->val;
        int count=0;
        solve(root,maxvalue,count);return count;
    }
};
