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
    bool flag = true;
    int height(TreeNode* root){
        if(root == NULL) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        if(abs(rh-lh)>1) {flag = false; }
        
        return 1+max(lh,rh);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        height(root);
        return flag;
    }
};