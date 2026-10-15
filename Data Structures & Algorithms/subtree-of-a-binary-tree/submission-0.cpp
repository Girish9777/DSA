class Solution {
public:
    void find(TreeNode* root, TreeNode* &res, TreeNode* subRoot)
    {
        if(root == NULL || res != NULL){
            return;
        }

        // ERROR 1: root == subRoot compares addresses.
        // FIX: Compare values and verify complete subtree.
        if(root->val == subRoot->val && check(root, subRoot)){
            res = root;
            return;
        }

        // Continue searching if current node doesn't match.
        find(root->left, res, subRoot);
        find(root->right, res, subRoot);
    }

    bool check(TreeNode* root, TreeNode* subRoot)
    {
        if(root == nullptr || subRoot == nullptr){
            return root == subRoot;
        }

        if(root->val != subRoot->val){
            return false;
        }

        // ERROR 2: You wrote:
        // if(root->val == subRoot->val) return true;
        // Remove it. We must compare all descendants.

        bool left = check(root->left, subRoot->left);
        bool right = check(root->right, subRoot->right);

        return left && right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(subRoot == NULL) return true;
        if(root == NULL) return false;

        TreeNode* res = nullptr;

        find(root, res, subRoot);

        // ERROR 3: Earlier you checked only one candidate.
        // FIX: find() now stores only a completely matching node.
        return res ;
    }
};