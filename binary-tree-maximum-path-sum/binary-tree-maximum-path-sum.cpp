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
    int ans = -1e9;
    
    int func(TreeNode* root){
        if(root == NULL) return 0;
        
        int left = max(0,func(root->left));
        int right = max(0,func(root->right));
        
        ans = max(ans, left+right+root->val);
        
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        func(root);
        return ans;
    }
};