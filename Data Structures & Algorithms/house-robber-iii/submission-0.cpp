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
public: // include the house exclude the house
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return make_pair(0,0);
        }
        pair<int,int> leftans=solve(root->left);
        pair<int,int> rightans=solve(root->right);
        pair<int,int> res;
        res.first=root->val+leftans.second+rightans.second;
        res.second=max(leftans.first,leftans.second)+max(rightans.first,rightans.second);
        return res;

    }
    int rob(TreeNode* root) {
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
    }
};