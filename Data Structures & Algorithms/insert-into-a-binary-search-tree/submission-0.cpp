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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        if(curr == nullptr) {
            return new TreeNode(val);
        }

        if(curr->val > val) {
            curr->left =  insertIntoBST(curr->left, val);
        } else if(curr->val < val) {
            curr->right = insertIntoBST(curr->right, val);
        }
        return root;
    }
};