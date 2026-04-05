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
private:
    void solve(TreeNode* root, int maxiSum, int& count) {
        if(!root) return;
        if(root->val >= maxiSum) {
            count++;
            maxiSum = max(maxiSum, root->val);
        }

        solve(root->left, maxiSum, count);
        solve(root->right, maxiSum, count);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        int maxi = root->val;
        solve(root, maxi, count);
        return count;
    }
};
