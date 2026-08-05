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
    pair<bool,int> check(TreeNode* root){
        if(root==NULL){
            return make_pair(true,0);
        }
        pair<bool,int> left=check(root->left);
        pair<bool,int> right=check(root->right);
        bool leftans=left.first;
        bool rightans=right.first;
        bool diff=abs(left.second-right.second)<=1;
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        if(leftans&& rightans&& diff){
                ans.first= true;
        }else{
            ans.first=false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return check(root).first;
        
    }
};
