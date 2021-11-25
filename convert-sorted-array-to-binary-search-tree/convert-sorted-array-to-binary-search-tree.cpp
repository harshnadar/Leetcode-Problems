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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int  n = nums.size();
        if(n==0) return NULL;
        TreeNode* node = new TreeNode(nums[n/2]);
        vector<int> v(nums.begin(), nums.begin()+n/2);
        node->left = sortedArrayToBST(v);
        vector<int> a(nums.begin()+n/2+1, nums.end());
        node->right = sortedArrayToBST(a);
        
        return node;
    }
};