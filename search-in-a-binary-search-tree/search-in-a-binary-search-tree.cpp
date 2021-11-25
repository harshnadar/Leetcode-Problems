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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root->val == val) return root;
        while(root && root->val!=val){
            if(root->val<val){
                root = root->right;
            }
            else if(root->val>val){
                root = root->left;
            }
            if(root && root->val == val){
                return root;
            }
        }
        
        return NULL;
    }
};