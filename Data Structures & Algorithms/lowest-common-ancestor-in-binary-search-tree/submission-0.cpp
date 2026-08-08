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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }
        // left or right
        TreeNode* lefta=lowestCommonAncestor(root->left,p,q);
        TreeNode*  righta=lowestCommonAncestor(root->right,p,q);
        if(lefta!= NULL && righta!=NULL){
            return root;
        }
        else if(lefta!=NULL && righta==NULL){
            return lefta;
        }
        else if(righta!=NULL && lefta==NULL){
            return righta;
        }else{
            return NULL;
        }

    }
};
