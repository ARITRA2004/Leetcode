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

    int max_path_sum(TreeNode* root, int &maxi){
        if(root == nullptr){
            return 0;
        }

        int leftsum = max(0,max_path_sum(root->left,maxi));
        int rightsum = max(0,max_path_sum(root->right,maxi));

        maxi = max(root->val + leftsum + rightsum, maxi);

        return max(leftsum,rightsum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        max_path_sum(root,maxi);

        return maxi;
    }
};